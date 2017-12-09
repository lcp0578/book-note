## 第1章 关于Go语言的介绍
- 在Go语言中,net/http库直接使用个内置的goroutine。每个接收到的请求都自动在其自己的goroutine里处理。
- goroutine使用的内存比线程更少，Go语言运行时，会自动在配置的一组逻辑处理器上调度执行goroutine。
- 通道是一种数据结构，可以让goroutine之间进行安全的数据通信。通道可以帮助用户避免其他语言里常见的共享内存访问的问题。
- Go开发者使用组合(composition) 设计模式，只需简单地将一个类型嵌入到另一个类型，就能复用所有的功能。
- http://play.golang.org 编辑并运行代码