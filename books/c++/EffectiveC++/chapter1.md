## 1 让自己习惯C++(Accustoming Yourself to C++)
### 条款01： 视C++为一个语言联邦(View C++ as a federation of languages)
- 今天的C++已经是个多重泛型编程语言，一个同时支持过程形式(procedural)、面向对象形式(object-oriented)、泛型形式(generic)、元编程形式(metaprogramming)的语言。
- 为了理解C++，你必须认识其主要的次语言。幸运的是总共只有四个：
	- **C**。说到底C++仍是以C为基础。区块(blocks)、语句(statements)、预处理器(preprocessor)、内置数据类型(built-in data types)、数组(arrays)、指针(pointers)等统统来自C。许多时候C++对问题的解法其实不过就是较高级的C解法，但是当你以C++内的C成分工作时，高效编程守则映照出C语言的局限：没有模板(templates)，没有异常(exception)，没有重载(overloading)...
	- **Object-Oriented C++**。这部分也就是C with Classes所诉求的：class(包括构造函数和析构函数)，封装(encapsulation)、继承(inheritance)、多态(pplymorphism)、virtual函数(动态绑定)...等等。这一部分是面向对象设计之古典守则在C++上的最直接实施。
	- **Template C++**。这是C++的泛型编程(generic programming)部分，也是大多数程序员经验最少的部分。Template相关考虑与设计已经弥漫整个C++，良好编程守则中“惟template适用”的特殊条款并不罕见。实际上由于template威力强大，它们带来崭新的编程泛型(programming paradigm)，也就是所谓的template metaprogramming(TMP,模板元编程)。
	- **STL**。STL是个template程序库，看名称也知道，但它是非常特殊的一个。它对容器(containers)、迭代器(iterators)、算法(algorithms)以及函数对象(function objetcs)的规约有极佳紧密配合与协调，然而templates及程序库也可以其他想法建置出来。STL有自己特殊的办事方式，当你伙同STL一起工作，你必须遵守它的规约。
- 因此我说，C++并不是一个带有一组守则的一体语言：它是从四个次语言组成的联邦政府，每个语言都有自己的规约。记住这四个次语言你就会发现C++容易了解许多。
- C++高效编程守则视情况而变化，取决于你使用C++的哪一部分。


### 条款02：尽量以`const`,`enum`,`inline`替换`#define`(Prefer consts,enums,and inlines to #defines)
- 对于单纯常量，(为了避免调试中问题)，最好以const对象或enums替换#defines。
- 对于形似函数的宏(macros)，最好改用inline函数替换#defines。
- 有了consts、enums和inlines，我们对预处理器(特别是`#define`)的需求降低了，但并非完全消除。`#include`仍然是必需品，而`#ifdef`/`#ifndef`也继续扮演控制编译的重要角色。

### 条款03：尽可能使用const(Use const whenever possible)
- const允许你指定一个语义约束(也就是指定一个“不该被改动”的对象)，而编译器会强制实施这项约束。它允许你告诉编译器和其他程序员某值应该保持不变。只要这（某值保持不变）是事实，你就该明确说出来，因为说出来可以获得编译器的相助，确保这条约束不被违反。
- 关键字const多才多艺。
	- 你可以用它在classes外部修饰global或者namespace作用域中的常量，或修饰文件、函数或区块作用域(block scope)中被声明为static的对象。
	- 你也可以用它修饰classes内部的static和non-static成员变量。
	- 面对指针，你可以指出指针自身、指针所指物，或两个都（或都不）是const。
- const语法虽然变化多端，但并不莫测高深。
	- 如果关键字const出现在星号左边，表示被指物是常量
	- 如果出现在星号右边，表示指针自身是常量
	- 如果出现在星号两边，表示被指物和指针两者都是常量。
- STL迭代器系以指针为根据塑模出来，所以迭代器的作用就像个`T*`指针。声明迭代器为`const`就像声明指针为`const`一样(即声明一个`T* const`指针)，表示这个迭代器不得指向不同的东西，但它所指的东西的值是可以改动的。如果你希望迭代器所指的东西不可被改动(即希望STL模拟一个`const T*`的指针)，你需要的是`const_iterator`。

		std::vector<int> vec;
		...
		const std::vector<int>::iterator iter = vec.begin();
		*iter = 10;  //没问题，改变iter所指物
		++iter;  //错误！iter是const
		
		std::vector<int>::const_iterator cIter = vec.begin();
		*cIter = 10;  //错误！*cIter是const
		++cIter;  //没问题，改变cIter
- 令函数返回一个常量值，往往可以降低因客户错误而造成的意外，而又不至于放弃安全性和高效性。
- 将某些东西声明为const可帮助编译器侦测出错误用法。const可以被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
- 编译器强制实施bitwise constness,但你编写程序时应该使用“概念上的常量性”(conceptual constness)。
- 当const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本可避免代码重复。

### 条款04：确定对象被使用前已先被初始化(Make sure that objects are initalized before they're used)
- 永远在使用对象之前先将它初始化。对于无任何成员的内置类型，你必须手工完成此事。
- 至于内置类型以外的任何其他东西，初始化责任落在构造函数(constructors)身上。规则很简单：确保每一个构造函数都将对象的每一个成员初始化。
- 这个规则很容易奉行，重要的是别混淆了赋值(assignment)和初始化(initialization)。

		class PhoneNumber { ... }
		class ABEntry {
		public:
			ABEntry(const std:string& name, const std:string& address, const std::list<PhoneNumber>& phones);
		private:
			std::string theName;
			std::string theAddress;
			std::list<PhoneNumber> thePhones;
			int numTimesConsulted;
		};
		ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
		{
			theName = name; //这些都是赋值(assignments)而非初始化(initializations)
			theAddress = address;
			thePhones = phones;
			numTimesConsulted = 0;
		}
- ABEntry构造函数的一个较佳写法是，使用所谓的member initialization list(成员初值列)替换赋值动作：

		ABEntry(const std:string& name, const std:string& address, const std::list<PhoneNumber>& phones) : theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0) //现在，这些都是初始化(initialization)
		{} //现在，构造函数本体不必有任何动作
- 这个构造函数和上一个的最终结果相同，但通常效率较高。基于赋值的那个版本首先调用default构造函数为theName、theAddress和thePhones设初值，然后立刻再对它们赋予新值。
- C++有着十分固定的“成员初始化次序”。是的，次序总是相同：base classes更早于其derived class被初始化，而class的成员变量总是一起声明次序被初始化。
- 既然这样，为避免在对象初始化之前过早地使用它们，你需要做三件事。
	- 第一,手工初始化内置型non-member对象
	- 第二，使用成员初值列(member initialization lists)对付对象的所有成分。
	- 最后，在“初始化次序不确定性”（这对不同编译单元所定义的non-local static对象是一种折磨）氛围下加强你的设计。
- 请记住
	- 为内置型对象进行手工初始化，因为C++不保证初始化它们。
	- 构造函数最好使用成员初值列(member initialization list)，而不要在构造函数本体内使用赋值操作(assignment)。初值列列的成员变量，其排列次序应该和它们在class中声明次序相同。
	- 为免除“跨编译单元之初始化次序”问题，请以local static对象替换non-local static对象。

