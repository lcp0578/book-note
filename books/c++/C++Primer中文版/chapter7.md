## 第7章 类
#### 定义抽象数据类型
- 定义在类内部的函数是隐式的`inline`函数。
- 常量对象，以及常量对象的引用或指针都只能调用常量成员函数。
- 编译器分两步处理类：
	- 首先编译成员的声明
	- 然后才编译成员函数体（如果有的话）
	- 因此，成员函数体可以随意使用类中的其他成员而无须在意这些成员出现的次序。
- 一般来说，如果非成员函数是类接口的组成部分，则这些函数的声明应该与类在同一个头文件内。
- 构造函数
	- 默认构造函数无须任何实参。
	- 编译器创建的构造函数又被称为**合成的默认构造函数**(synthesized default constructor)。
	- 只有当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数。
- `=default`的含义
	- 在C++11新标准中，如果我们需要默认的行为，那么可以通过在参数列表后面写上`=default`来要求编译器生成构造函数。
#### 访问控制与封装
- 使用`class`和`struct`定义类唯一的区别就是默认的访问权限。
- 类可以允许其他类或者函数访问他的非公有成员，方法是令其他类或者函数称为它的友元(friend)。
#### 类的其他特性
- 即使两个类的成员列表完全一致，它们也是不同的类型。
- 友元关系不存在传递性。
- 每个类负责控制自己的友元类或友元函数。
#### 类的作用域
- 类型名的定义通常出现在类的开始处，这样就能确保所有使用该类型的成员都出现在类名的定义之后。
#### 构造函数再探
- 如果成员是`const`、引用，或者属于某种未提供默认构造函数的类类型，必须通过构造函数初始值列表为这些成员提供初值。
- 委托构造函数
	- C++11新标准扩展了构造函数初始值的功能，使得我们可以定义所谓的**委托构造函数**(delegating constructor)。
	- 一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程，或者说它把它自己的一些（或者全部）职责委托给了其他构造函数。

			class Sales_data {
			public:
				// 非委托构造函数使用对应的实参初始化成员
				Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt*price) {}
				//其余构造函数全部委托给另一个构造函数
				Sales_data() : Sales_data("", 0, 0) {}
				Sales_data(std::string s) : Sales_data(s, 0, 0) {}
				Sales_data(std::istream &is) : Sales_data() { read(is, *this);}
			}
- explicit抑制构造函数定义的隐式转换
	- 关键字`explicit`只对一个实参的构造函数有效。
	- 需要多个实参的构造函数不能用于执行隐式转换，所以无需将这些构造函数指定为`explicit`的。
	- 只能在类内声明构造函数时使用`explicit`关键字，在类外部定义时不应重复。
#### 类的静态成员
- 即使一个常量静态数据成员在类内部被初始化了，通常情况下也应该在类的外部定义一下该成员。