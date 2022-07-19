## 3 资源管理(Resource Management)
### 条款13：以对象管理资源(Use objects to manage resources)
- 把资源放进对象内，我们便可依赖C++的“析构函数自动调用机制”确保资源被释放。
- 获取资源后立刻放进管理对象内。
	- 实际上“以对象管理资源”的观念常被称为“资源取得时机便是初始化时机”(Resource Acquisition Is Initialization; RAII),因为我们几乎总是在获得一笔资源后于同一语句内以它初始化某个管理对象。
- 管理对象运用析构函数确保资源被释放。
- auto_ptr有一个不同寻常的性质：若通过copy构造函数或copy assignment操作符复制它们，它们会变成null，而复制所得的指针将取得资源的唯一拥有权。
- 为防止资源泄露，请使用RAII对象，它们在构造函数中获得资源并在析构函数中释放资源。
- 两个常被使用的RAII classes分别是tr1::shared_ptr和auto_ptr。前者通常是较佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它（被复制物）指向null。

### 条款14：在资源管理类中小心copying行为(Think carefully about copying behavior in resource-managing classes.)
- 赋值RAII对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的copying行为。
- 普遍而常见的RAII class copying行为是：抑制copying、施行引用计数法(reference counting)。不过其他行为也都可能被实现。

### 条款15：在资源管理类中提供对原始资源的访问(Provide access to raw resources in resource-managing classes.)
- `tr1::shared_ptr`和`auto_ptr`都提供一个get成员函数，用来执行显式转换，也就是它会返回智能指针内部的原始指针（的复件）。
- 就像（几乎）所有智能指针一样，`tr1::shared_ptr`和`auto_ptr`也重载了指针取值(point dereferencing)操作符(operator->和operator*)，它们运行隐式转换至底部原始指针。
- APIs往往要求访问原始资源（raw resources），所以每一个RAII class应该提供一个“取得其所管理之资源”的办法。
- 对原始资源的访问可能经由显式转换或隐式转换。一般而言显式转换比较安全，但隐式转换对客户比较方便。