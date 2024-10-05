# sysMaster

源码仓库：[https://gitee.com/openeuler/sysmaster](https://gitee.com/openeuler/sysmaster)

## 0-背景

Linux的启动流程大致如下:

1. BIOS：硬件检测，查找并加载磁盘上的MBR
2. MBR：存储BootLoader信息，加载GRUB
3. GRUB：查找并加载Kernal
4. Kernal：装载驱动，挂载rootfs，执行/sbin/init
5. Init：OS初始化，执行runlevel相关程序
6. Runlevel：启动指定级别的服务

> MBR：MBR（Master Boot Record）是硬盘上一段重要的引导代码区域，位于硬盘的第一个扇区（通常是第0号扇区，即第512字节的位置）。这个扇区包含了引导加载程序（boot loader）以及分区表（partition table），用于告诉计算机操作系统的位置。
>
> GRUB：GRUB（GNU GRand Unified Bootloader）是一种广泛使用的引导加载程序（boot loader），主要用于 Unix-like 操作系统，如 Linux 和 BSD。

Init是OS的初始化过程，最常见的就是systemd~~，但是其代码量大并且性能一般，所以有了sysMaster~~

## 1-sysMaster

sysMaster共有init、core、exts三个部分：

* init：1号进程，LOC 1k左右
* core：systemd原有核心功能，插件化、崩溃快速自愈
* exts：抽屉式、解耦各组件

### 1-0 init

```rust
// main函数位于sysmaster/init/main.rs
fn main() -> std::io::Result<()> {
    setup_mount_early();

    log::init_log_to_kmsg_console("sysmaster-init", log::Level::Info);

    prepare_init();

    reset_all_signal_handlers();
    install_crash_handler();

    let mut rt = Runtime::new()?;
    rt.set_state(InitState::Running);

    rt.runloop()?;

    if rt.is_reexec() {
        rt.reexec();
    }
    shutdown_init();
    Ok(())
}
```

* setup_mount_early

  * 在/sysmaster/init/mount.rs文件中[定义](../image/sysMaster/setup_mount_early.png)
  * 功能：挂载文件系统/sys /proc /dev /run
  * /sys和/proc对于获取系统和进程信息非常有用；/dev和/run对于存放设备文件和运行时数据很关键
* init_log_to_kmsg_console

  * 在/sysmaster/libs/log/src/lib.rs文件中[定义](../image/sysMaster/init_log_to_kmsg_console.png)
  * 功能：初始化日志记录器
* prepare_init

  * 在/sysmaster/init/main.rs文件中[定义](../image/sysMaster/prepare_init.png)
  * 功能：确保daemon以正确的权限和状态运行
  * 设置文件权限掩码、确保进程以超级用户权限运行、确保pid是1
* reset_all_signal_handlers

  * 在/sysmaster/init/main.rs文件中[定义](../image/sysMaster/reset_all_signal_handlers.png)
  * 功能：设置信号处理程序为忽略，除了SIGKILL和SIGSTOP
  * 确保daemon能够稳定地运行，并且不会因为外部信号而导致不可预测的行为
* install_crash_handler

  * 在/sysmaster/init/main.rs文件中[定义](../image/sysMaster/install_crash_handler.png)
  * 功能：安装崩溃处理程序
  * 这些都是严重的错误信号，需要特殊处理
* Runtime

  * 在/sysmaster/init/runtime.rc文件中[定义属性](../image/sysMaster/runtime-0.png)和[方法](../image/sysMaster/runtime-1.png)
  * new和set_state都是方法，前者会把rt的InitState初始化为Init，并且初始化其他属性；后者会把InitState改为Running
  * runloop是一个[死循环](../image/sysMaster/runtime-runloop.png)，不断地处理SIGNAL、TIMER、SOCKET等
  * 崩溃快速自愈的实现是由runloop中的is_running来判断，之后会在main中执行reexec

### 1-1 core-sctl

```rust
// main函数位于sysmaster/core/sctl/src/main.rs
fn main() {
    let args = parse_args();

    let command_request = match generate_command_request(args) {
        None => {
            eprintln!("This command is currently not supported");
            exit(nix::Error::ENOTSUP as i32);
        }
        Some(v) => v,
    };

    let stream = match UnixStream::connect(PRIVATE_SOCKET) {
        Err(e) => {
            eprintln!("Failed to connect to sysmaster: {}", e);
            exit(e.raw_os_error().unwrap());
        }
        Ok(v) => v,
    };

    let mut client = ProstClientStream::new(stream);

    let data = match client.execute(command_request) {
        Err(e) => {
            eprintln!("Failed to execute the given command: {}", e);
            exit(1);
        }
        Ok(v) => v,
    };

    /* We should always print the error message if the returned error code is not 0. */
    if data.message.is_empty() {
        exit(0);
    }

    if data.error_code == 0 || (data.error_code & ERROR_CODE_MASK_PRINT_STDOUT != 0) {
        /* Don't care if we fail to write the message out. */
        let _ = writeln!(std::io::stdout(), "{}", data.message);
    } else {
        eprintln!("{}", data.message);
    }

    exit((data.error_code & !ERROR_CODE_MASK_PRINT_STDOUT) as i32);
}
```
