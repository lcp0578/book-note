## 第4章 内存、数组和指针
- 空指针
	- 常量 `nullptr`的类型并不是证书，而是`std::nullptr_t`。所有指针类型都可以隐式转换成该类型，因此`nullptr`可以用来初始化任意指针类型的变量。
- 内存类型
	- 静态或全局
	- 字符串池
	- 自动或者堆栈型
	- 自由存储