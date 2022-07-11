## 2 构造/析构/赋值运算(Constructors,Destructors,and Assignment Operators)
### 条款05：了解C++默默编写并调用哪些函数(Know what functions C++ silently writes and calls)
- 编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment操作符，以及析构函数。
### 条款06：若不想使用编译器自动生成的函数，就该明确拒绝(Explicitly disallow the use of complier-generated functions you do not want.)
- 为驳回编译器自动（暗自）提供的机能，可将相应的成员函数声明为private并且不予实现。使用像Uncopyable这样的base class也是一种做法。
### 条款07: 为多态基类声明virtual析构函数(Declare destructors virtual in polymorphic base classes.)
- 析构函数的运作方式是，最深层派生(most derived)的那个class其析构函数最先被调用，然后是其每一个base class的析构函数被调用。
- polymorphic(带多态性质的)base class应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual析构函数。
- 这种base classes的设计目的是为了用来“通过base class接口处理derived class对象”。
- Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性(polymorphicall)，就不该声明virtual析构函数。