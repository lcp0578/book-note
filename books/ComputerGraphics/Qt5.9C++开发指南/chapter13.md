## 第13章 多线程
- `QThread`是线程类，是实现多线程操作的核心类，一般从`QThread`继承定义自己的线程类。
- 线程之间的同步是其交互的主要问题，Qt提供了`QMutex`、`QMutexLocaker`、`QReadWriteLock`、`QWaiteCondition`、`QSemaphore`等多种类用于实现线程之间的同步。
- Qt还有`Qt Concurrent`模块，提供一些高级的API实现的多线程程序可以自动根据处理器内核个数调整线程个数。
### QThread创建多线程程序
- `QThread`类提供不依赖于平台的管理线程的方法。一个`QThread`类的对象管理一个线程，一般从`QThread`继承一个自定义类，并重定义虚函数`run()`，在`run()`函数里实现线程需要完成的任务。
- 将应用程序的线程称为主线程，额外创建的线程称为工作线程。一般在主线程里创建工作线程，并调用`start()`开始执行工作线程的任务。`start()`会在内部调用`run()`函数，进入工作线程的事件循环，在`run()`函数里调用`exit()`或`quite()`可以结束线程的事件循环，或在主线程里调用`terminate()`强制结束线程。
- `QThread`是`QObject`的子类，所以可以使用信号与槽机制。`QThread`自身定义了`started()`和`finished()`两个信号，`start()`信号在线程开始执行之前发射，也就是在`run()`函数被调用之前，`finised()`信号在线程就要结束时发射。
- `QThread`类的主要接口函数、信号和槽函数。

| 类型 | 函数 | 功能 |
| -- | -- | -- |
|公共函数 | bool isFinished() | 线程是否结束 |
| | bool is Running() | 线程是否正在运行 |
| | Priority priority() | 返回线程的优先级 | 
| | void setPriority(Priority priority) | 设置线程的优先级 |
| | void exit(int returnCode = 0) | 退出线程的事件循环，退出码为returnCOde,0表示成果退出；否则表示有错误 |
| | bool wait(unsigned long time) | 阻止线程执行，直到线程结束(从run()函数返回)，或等待时间超过time毫秒。 |
| 公共槽函数 | void quit() | 退出线程的事件循环，并返回代码0，等效于`exit(0)` |
| | void start(Priority priority) | 内部调用`run()`开始执行线程，操作系统根据priority参数进行调度 |
| | void terminate() | 终止线程的运行，但不是立即结束线程，而是等待操作系统结束线程。使用terminate()之后应使用wait() |
| 信号 | void finished() | 在线程就要结束时发射此信号 |
| | void started() | 在线程开始执行、run()函数被调用之前发射此信号 |
| 静态公共成员 | int idealThreadCount() | 返回系统上能运行的线程的理想个数 |
| | void msleep(unsigned long msecs) | 强制当前线程休眠 msecs毫秒 |
| | void sleep(unsigned long secs) | 强制当前线程休眠 secs 秒 |
| | void usleep(unsigned long usecs) | 强制当前线程休眠 usecs 微秒 |
| 保护函数 | virtual void run() | start()调用run()函数开始线程任务的执行，所以在run()函数里实现线程的任务功能。 |
| | int exec() | 由run()函数调用，进入线程的事件循环，等待exit()退出 |
### 线程同步
- 基于`QMutex`互斥量的线程同步
- 基于`QReadWriteLock`的线程同步
- 基于`QWaitCondition`的线程同步
- 基于信号量`QSemaphore`的线程同步