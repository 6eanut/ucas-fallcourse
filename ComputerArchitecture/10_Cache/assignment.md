# 高速缓存

访问cache时，访问地址由Tag、Index、Offset三部分组成

* Offset是块内地址，在地址的低几位；当cache块为32字节时，读cache时把32个字节作为一组一起读出来，用Offset在32字节中选择本次访问需要的字或双字
* Index用来访问索引，即一路里面有多少cache项
* Tag即为地址

通过页大小获得页内偏移，访问Cache的地址Index+Offset位，若后者大于前者，则多出来的那几位就是页着色位
