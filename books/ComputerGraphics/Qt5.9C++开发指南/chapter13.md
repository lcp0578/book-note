## 第13章 多线程
- `QThread`是线程类，是实现多线程操作的核心类，一般从`QThread`继承定义自己的线程类。
- 线程之间的同步是其交互的主要问题，Qt提供了`QMutex`、`QMutexLocaker`、`QReadWriteLock`、`QWaiteCondition`、`QSemaphore`等多种类用于实现线程之间的同步。
- Qt还有`Qt Concurrent`模块，提供一些高级的API实现的多线程程序可以自动根据处理器内核个数调整线程个数。
### QThread创建多线程程序
- `QThread`类提供不依赖于平台的管理线程的方法。一个`QThread`类的对象管理一个线程，一般从`QThread`继承一个自定义类，并重定义虚函数`run()`，在`run()`函数里实现线程需要完成的任务。
- 将应用程序的线程称为主线程，额外创建的线程称为工作线程。一般在主线程里创建工作线程，并调用`start()`开始执行工作线程的任务。`start()`会在内部调用`run()`函数，进入工作线程的事件循环，在`run()`函数里调用`exit()`或`quite()`可以结束线程的事件循环，或在主线程里调用`terminate()`强制结束线程。
- `QThread`是`QObject`的子类，所以可以使用信号与槽机制。`QThread`自身定义了`started()`和`finished()`两个信号，`start()`信号在线程开始执行之前发射，也就是在`run()`函数被调用之前，`finised()`信号在线程就要结束时发射。
- `QThread`类的主要接口函数、信号和槽函数。
	<table>
		<tr>
			<th>类型</th><th>函数</th><th>功能</th>
		</tr>
		<tr>
			<td rowspan="6">公共函数</td><td>bool isFinished() </td><td> 线程是否结束 </td>
		</tr>
		<tr>
			<td>bool is Running()</td><td> 线程是否正在运行 </td>
		</tr>
		<tr>
			<td> Priority priority()</td><td>返回线程的优先级</td>
		</tr>
		<tr>
			<td>void setPriority(Priority priority)</td><td>设置线程的优先级</td>
		</tr>
		<tr>
			<td>void exit(int returnCode = 0) </td><td> 退出线程的事件循环，退出码为returnCOde,0表示成果退出；否则表示有错误</td>
		</tr>
		<tr>
			</td><td>bool wait(unsigned long time)</td><td>阻止线程执行，直到线程结束(从run()函数返回)，或等待时间超过time毫秒。</td>
		</tr>
		<tr>
			<td rowspan="3">公共槽函数</td><td> void quit() </td><td>退出线程的事件循环，并返回代码0，等效于`exit(0)` </td>
		</tr>
		<tr>
			<td>void start(Priority priority) </td><td> 内部调用`run()`开始执行线程，操作系统根据priority参数进行调度 </td><td>
		</tr>
		<tr>
			<td> void terminate() </td><td>终止线程的运行，但不是立即结束线程，而是等待操作系统结束线程。使用terminate()之后应使用wait() </td>
		</tr>
		<tr>
			<td rowspan="2">信号 </td><td> void finished() </td><td> 在线程就要结束时发射此信号 </td>
		</tr>
		<tr>
			<td>void started() </td><td> 在线程开始执行、run()函数被调用之前发射此信号</td>
		</tr>
		<tr>
			<td rowspan="4"> 静态公共成员 </td><td> int idealThreadCount() </td><td> 返回系统上能运行的线程的理想个数 </td>
		</tr>
		<tr>
			<td>void msleep(unsigned long msecs) </td><td> 强制当前线程休眠 msecs毫秒 </td>
		</tr>
		<tr>
			<td>void sleep(unsigned long secs) </td><td>强制当前线程休眠 secs 秒 </td>
		</tr>
		<tr>
			<td> void usleep(unsigned long usecs) </td><td> 强制当前线程休眠 usecs 微秒 </td>
		</tr>
		<tr>
			<td rowspan="2"> 保护函数 </td><td> virtual void run() </td><td> start()调用run()函数开始线程任务的执行，所以在run()函数里实现线程的任务功能。 </td>
		</tr>
		<tr>
			<td> int exec() </td><td> 由run()函数调用，进入线程的事件循环，等待exit()退出 </td>
		</tr>
	</table>
### 线程同步
- `QMutex`和`QMutexLocker`是基于互斥量的线程同步类
	- `QMutex`定义的实例是一个互斥量，`QMutex`主要提供3个函数。
		- `lock()`: 锁定互斥量，如果另外一个线程锁定了这个互斥量，它将阻塞执行直到其他线程解锁这个互斥量。
		- `unlock()`: 解锁一个互斥量，需要与`lock()`配对使用。
		- `tryLock()`: 试图锁定一个互斥量，如果成功锁定就返回true;如果其他线程已经锁定这个互斥量，就返回false，但不阻塞程序执行。
	- `QMutexLocker`是另外一个简化了互斥量处理的类。
		- `QMutexLocker`的构造函数接受一个互斥量作为参数并将其锁定，`QMutextLocker`的析构函数则将此互斥量解锁，所以在`QMutexLocker`实例变量的生存期内的代码段得到保护，自动进行互斥量的锁定和解锁。
- `QReadWriteLock`以读或写锁定的同步方法允许读或写的方式保护一段代码，它可以允许多个线程以只读方式同步访问资源，但是只要有一个线程在以写方式访问资源时，其他线程就必须等待直到写操作结束。
	- `QReadWriteLock`提供以下主要的函数：
		- `lockForRead()`,以只读方式锁定资源，如果有其他线程以写入方式锁定，这个函数会阻塞；
		- `lockForWrite()`,以写入方式锁定资源，如果本线程或其他线程以读或写模式锁定资源，这个函数就堵塞；
		- `unlock`，解锁
		- `tryLockForRead()`,是`lockForRead()`的非阻塞版本；
		- `tryLockForWrite()`，是`lockForWrite()`的非阻塞版本。
- `QWaitCondition`提供了另外一种改进的线程同步方法，`QWaitCondition`与`QMutex`结合，可以使在一个线程满足一定条件时通知其他多个线程，使它们及时作出响应，这样比只使用互斥量效率要高一些。
	- `QWaitCondition`提供如下一些函数：
		- `wait(QMutex *lockedMutex)`，解锁互斥量lockedMutex，并阻塞等待唤醒条件，被唤醒后锁定lockedMutex并退出函数；
		- `wakeAll()`，唤醒所有处于等待状态的线程，线程唤醒的顺序不确定，由操作系统的调度策略决定；
		- `wakeOne()`，唤醒一个处于等待状态的线程，唤醒哪个线程不确定，由操作系统的调度策略决定。
	- `QWaitCondition`一般用于“生产者/消费者”(producer/consumer)模型中。
- 基于信号量`QSemaphore`的线程同步
	- 信号量(semaphore)是另一种限制对共享资源进行访问的线程同步机制，它与互斥量(Mutex)相似，但是有区别。一个互斥量只能被锁定一次，而信号量可以多次使用。
	- 信号量通常用来保护一定数量的相同的资源，如数据采集时的双缓冲区。
	- `QSemaphore`是实现信号量功能的类，它提供一下几个基本的函数
		- `acquire(int n)`,尝试获得n个资源。如果没有这么多资源，线程将阻塞直到有n个资源可用；
		- `release(int n)`,释放n个资源，如果信号量的资源已全部可用后再release(),就可以创建更多的资源，增加可用资源的个数；
		- `int available()` 返回当前信号量可用的资源个数，这个个数永远不可能为负数，如果为0，就说明当前没有资源可用；
		- `bool tryAcquire(int n=1)`，尝试获取n个资源。不成功时不阻塞线程。