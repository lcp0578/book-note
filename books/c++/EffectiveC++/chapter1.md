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