# 03-二进制与逻辑电路

## 数的表示

**定点数**

* 32位->正数的补码==原码；负数的补码==正数的原码按位(不包括符号位)取反+1
* 64位->和32位一样的

定点数的原码表示范围中有正零和负零，在补码中，将负零变成了最小的负数

**浮点数**

* 32位(单精度)->从左到右，符号位1位，阶码8位，剩下为尾码；阶数==阶码-127，底数==0.尾码+1.0；若阶码==0，且尾码==0，则表示正负0；若阶码==0，尾码!=0，则表示非规格化数，此时阶数==阶码-126，底数==0.尾码；若阶码==255，且尾码==0，则表示正负无穷大；若阶码==255，且尾码!=0，则表示非数NaN
* 64位(双精度)->相比于单精度，阶码11位；127对应1023，255对应2047

## CMOS管

反相器：PN

NAND2：(P并P)串N串N

NOR2：P串P串(N并N)

N管接地，P管接电；P管有个0所以它有多余的空穴，N管有多余的电子；P管在电路图中有圈，N管没有。

### CMOS电路的延迟

输出由高到低的延迟==输出负载*输出的单位负载延迟+输出由高到低的延迟+（输入负载+连线负载）*输入的单位负载延迟+输入由低到高的延迟

FO4：一个逻辑门输出驱动四个相同类型的逻辑门

### 逻辑电路

逻辑电路分为组合逻辑电路和时序逻辑电路

时序逻辑电路需要掌握RS触发器、D锁存器、D触发器