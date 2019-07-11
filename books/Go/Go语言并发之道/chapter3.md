## 第3章 Go 语言并发组件
- 每个Go语言程序都至少有一个goroutine: main goroutine, 它在进程开始时自动创建并启动。
- 协程是一种非抢占式的简单并发子goroutine（函数、闭包或方法），也就是说，他们不能被中断。取而代之，协程有多个点，允许暂停或者重新进入。
- Go语言的主机托管机制是一个名为M:N的调度器实现，这意味着它将M个绿色线程映射到N个OS线程。
- Go 语言遵循一个称为fork-join的并发模型。
	- fork这个词指的是在程序中的任意一点，他可以将执行的子分支与其父节点同时运行。
	- join这个词指的是，在将来的某个时候，这些并发执行的分支将会合并在一起。
- Why goroutines instead of threads?
	- Goroutines are part of making concurrency easy to use. The idea, which has been around for a while, is to multiplex independently executing functions—coroutines—onto a set of threads. When a coroutine blocks, such as by calling a blocking system call, the run-time automatically moves other coroutines on the same operating system thread to a different, runnable thread so they won't be blocked. The programmer sees none of this, which is the point. The result, which we call goroutines, can be very cheap: they have little overhead beyond the memory for the stack, which is just a few kilobytes.
	- To make the stacks small, Go's run-time uses resizable, bounded stacks. A newly minted goroutine is given a few kilobytes, which is almost always enough. When it isn't, the run-time grows (and shrinks) the memory for storing the stack automatically, allowing many goroutines to live in a modest amount of memory. The CPU overhead averages about three cheap instructions per function call. It is practical to create hundreds of thousands of goroutines in the same address space. If goroutines were just threads, system resources would run out at a much smaller number.


- sync包 包含对低级别内存访问同步最有用的并发原语。
	- WaitGroup(可是视为并发-安全的计数器)
		- Add
		- Done
		- Wait
	- 互斥锁和读写锁
		- sync.Mutex（互斥锁，是保护程序中临界区的一种方式）
		- sync.RWMutex(可以对内存更多的控制)
	- Cond
		- Cond implements a condition variable, a rendezvous point for goroutines waiting for or announcing the occurrence of an event.
	- Once
		- Once is an object that will perform exactly one action.
	- Pool
		- A Pool is a set of temporary objects that may be individually saved and retrieved.
- Channel
- Select
- GOMAXPROCS