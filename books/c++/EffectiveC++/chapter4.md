## 4 设计与声明(Designs and Declarations.)
### 条款18：让接口容易被正确使用，不易被误用(Make interfaces easy to use correctly and hard to use incorrectly.)
- 好的接口很容易被正确使用，不容易被误用。你应该在你的所有接口中努力达成这些性质。
- “促进正确使用”的办法包括接口的一致性，以及与内置类型的行为兼容。
- “阻止误用”的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任。
- `tr1::shared_ptr`支持定制型删除器(custom deleter)。这可防范DLL问题，可被用来自动解除互斥锁（mutexes）等等。

### 条款19：设计class犹如设计type (Treat class design as type design.)
- Class的设计就是type的设计。在定义一个新type之前，请确定你已经考虑过本条款涵盖的所有讨论主题。

### 条款20：宁以pass-by-reference-to-const替换pass-by-value(Prefer pass-by-reference-to-const to pass-by-value.)
- 缺省情况下C++以by value方式（一个继承自C的方式）传递对象值（或来自）函数。除非你另外指定，否则函数参数都是以实际实参的复件（副本）为初值，而调用端所获得的亦是函数返回值的一个复件。这些复件（副本）系有对象的copy构造函数产出，这可能使得pass-by-value成为昂贵的（费时的）操作。
- 尽量以pass-by-reference-to-const替换pass-by-value。前者通常比较高效，并可避免切割问题（slicing problem）.
- 以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-vaule往往比较适当。

### 条款21：必须返回对象时，别妄想返回其reference(Don't try to return a reference when you must return an object.)
- 绝不要返回pointer或reference指向一个local stack对象，或返回reference指向一个heap-allocated对象，或返回pointer或reference指向一个local static对象而有可能同时需要多个这样的对象。
- 条款04已经为“在单线程环境中合理返回reference指向一个local static对象”提供了一份设计实例。

### 条款22：将成员变量声明为private(Declare data members private.)
- 将成员变量隐藏在函数接口的背后，可以为“所有可能的实现”提供弹性。
- 切记将成员变量声明为private。这可赋予客户访问数据的一致性、可细微划分访问控制、允诺约束条件获得保证，并提供class作者以充分的实现弹性。
- protected并不比public更具封装性。

### 条款23：宁以non-member、non-friend替换member函数(Prefer non-member non-friend functions to member functions.)
- 宁可拿non-member non-friend函数替换member函数。这样可以增加封装性、包裹弹性(packaging flexibility)和机能补充性。

### 条款24：若所有参数皆需要类型转换，请为此采用non-member函数(Declare non-member functions when type conversions should apply to all parameters.)
- 如果你需要为某个函数的所有参数（包括被this指针所指的那个银鱼参数）进行类型转换，那么这个函数必须是个non-member。