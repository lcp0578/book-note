## 3 资源管理(Resource Management)
### 条款13：以对象管理资源(Use objects to manage resources)
- 把资源放进对象内，我们便可依赖C++的“析构函数自动调用机制”确保资源被释放。
- 获取资源后立刻放进管理对象内。
	- 实际上“以对象管理资源”的观念常被称为“资源取得时机便是初始化时机”(Resource Acquisition Is Initialization; RAll),因为我们几乎总是在获得一笔资源后于同一语句内以它初始化某个管理对象。
- 管理对象运用析构函数确保资源被释放。
- auto_ptr有一个不同寻常的性质：若通过copy构造函数或copy assignment操作符复制它们，它们会变成null，而复制所得的指针将取得资源的唯一拥有权。
- 为防止资源泄露，请使用RAll对象，它们在构造函数中获得资源并在析构函数中释放资源。
- 两个常被使用的RAll classes分别是tr1::shared_ptr和auto_ptr。前者通常是较佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它（被复制物）指向null。