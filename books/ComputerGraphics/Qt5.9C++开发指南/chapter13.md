## 第13章 多线程
### QThread创建多线程程序
- `QThread`类提供不依赖于平台的管理线程的方法。一个`QThread`类的对象管理一个线程，一般从`QThread`继承一个自定义类，并重定义虚函数`run()`，在`run()`函数里实现线程需要完成的任务。
### 线程同步
- 基于`QMutex`互斥量的线程同步
- 基于`QReadWriteLock`的线程同步
- 基于`QWaitCondition`的线程同步
- 基于信号量`QSemaphore`的线程同步