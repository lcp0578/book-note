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

### 条款08:别让异常逃离析构函数(Prevent exceptions from leaving destructors.)
- 析构函数绝对不需要土出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕获任何异常，然后吞下它们（不传播）或结束程序。
- 如果客户需要对某个操作函数运行期间抛出的异常作出反应，那么class应该提供一个普通函数（而非在析构函数中）执行该操作。

### 条款09：绝不在构造和析构过程中调用virtual函数(Never call virtual functions during construction or destruction.)
- 你不应该在构造函数和析构函数期间调用virtual函数，因为这样的调用不会带来你预想的结果。
- 由于base class构造函数的执行更早于derived class构造函数，当base class构造函数执行时derived class的成员变量尚未初始化。
- 在derived对象的base class构造期间，对象类型是base class而不是derived class。不只virtual函数会被编译器解析至(resolve to)base class，若使用运行期类型信息(runtime type information,例如dynamic_case和typeid)，也会把对象视为base class类型。
- 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class（比起当前执行构造函数和析构函数的那层）。

### 条款10:令operator= 返回一个reference to *this(Have assignment operators return a reference to *this.)
- 为了实现“连锁赋值”，赋值操作符必须返回一个reference指向操作符的左侧实参。
- 令赋值(assignment)操作符返回一个reference to *this.

### 条款11：在operator=中处理“自我赋值”(Handle assignment to selft in operator=.)


