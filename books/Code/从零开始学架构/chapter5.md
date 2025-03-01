## 第5章 计算高性能
- PPC
	- PPC是Process per Connection的缩写，其含义是指每次有新的连接就新建一个进程专门处理这个链接请求，这是传统的UNIX网络服务器所采用的模型。
	- 这种模式的弊端
		- fork代价高
		- 父子进程通信复杂
		- 进程数量增大后对操作系统压力较大
- prefork
	- prefork就是提前创建进程。
	- 系统在启动的时候就预先创建好进程，然后才开始接受用户的请求，当有新的连接进来的时候，就可以省去“fork”进程的操作，让用户的访问更快、体验更好。
- TPC
	- TPC是Thread per Connection的缩写，其含义是指每次有新的连接就新建一个线程专门处理这个连接的请求。
	- 与进程相比，线程更轻量级，创建线程的消耗比进程要少得多；同时多线程是共享进程内存空间的，线程通信相比进程通信更简单。
- prethread
	- 和prefork类似，prethread模式会预先创建线程，然后才开始接受用户的请求，当有新的连接进来的时候，就可以省去创建线程的操作，让用户感觉更快、体验更好。
- Reactor
	- Reactor模式，即I/O多路复用统一监听事件，收到事件后分配(Dispatch)给某个进程。
- Proactor
	- Reactor可以理解为“来了事件我通知您，你来处理”，而Proactor可以理解为“来了事件我来处理，处理完了我通知你”。
- 集群高性能
	- 负载均衡分类
		- DNS负载均衡
		- 硬件负载均衡
		- 软件负载均衡
	- 负载均衡的算法
		- 轮询
		- 加权轮询
		- 负载最低优先
		- 性能最优类
		- Hash类