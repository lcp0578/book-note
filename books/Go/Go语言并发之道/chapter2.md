## 第2章 对你的代码建模：通信顺序进程
- 并发属于代码；并行属于一个运行中的程序
- CSP(Communicating Sequential Processes)
- Go语言的运行时自动地将goroutine映射到系统的线程上，并为我们管理他们之间的调度。
- 使用通信来共享内存，而不是通过共享内存来通信。
- 追求简洁，尽量使用channel，并且认为goroutine的使用是没有成本的。