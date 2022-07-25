## 5 实现(Implementations)
### 条款26：尽可能延后变量定义式的出现时间(Postpone variable definitions as long as possible.)
- 尽可能延后变量定义的出现。这样做可增加程序的清晰度并改善程序效率。

### 条款27：尽量少做转型动作(Minimize casting.)
- C风格的转型动作：

		(T)expression //将expression转型为T
- 函数风格的转型动作：

		T(expression)  //将expression转型为T
- C++还提供四种新式转型
	- `const_cast<T>(expression)` 通常被用来将对象的常量性转除(cast away the constness)。它也是唯一有此能力的C++-style转型操作符。
	- `dynamic_cast<T>(expression)` 主要用来执行“安全向下转型”(safe downcasting)，也就是用来决定某对象是否归属继承体系中的某个类型。它是唯一无法由旧式语法执行的动作，也是唯一可能耗费重大运行成本的转型动作。
	- `reinterpret_cast<T>(expression)` 意图执行低级转型，实际动作（及结果）可能取决于编译器，这也就表示它不可移植、例如将一个pointer to int转型为一个int。这类转型在低级代码以外很少见。
	- `static_cast<T>(expression)` 用来强迫隐式转换(implicit conversions)，例如将non-const对象转为const对象，或将int转为doubile等等。它也可以用来执行上数转换的反向转换，例如将void*指针zhuanweityped指针，将pointer-to-base转为pointer-to-derived。但它无法将const转换为non-const--这个只有`const_cast`才办得到。
- 旧式转型仍然合法，但是新式转型较受欢迎。
	- 第一，它们很容易在代码中被辨识出来，因而得以简化“找出类型系统在哪个地点被破坏”的过程。
	- 第二，各转型动作的目标愈窄化，编译器愈可能诊断出错误的运用。
- 如果可以，尽量避免转型，特别是在注重效率的代码中避免`dynamic_cast`。如果有个设计需要转型动作，试着发展无需转型的代替设计。
- 如果转型是必要的，试着将它隐藏于某个函数背后。客户随后可以调用该函数，则不需要将转型放进他们自己的代码内。
- 宁可使用C++-style（新式）转型，不要使用旧式转型。前者很容易辨识出来，而且也比较有着分门别类的职掌。

### 条款28：避免返回handles指向对象内部成分(Avoid returning "handles" to object internals.)
- 第一，成员变量的封装性最多只等于“返回其reference”的函数的访问级别。
- 第二，如果const成员函数传出一个reference，后者所指数据与对象自身有关联，而它又被存储于对象之外，那么这个函数的调用者可以修改那笔数据，这正是bitwise constness的一个附带结果。
- 避免返回handles（包括reference、指针、迭代器）指向对象内部。遵守这个条款可增加封装性，帮助const成员函数的行为像个const，并将发生“需吊号码牌”（dangling handles）的可能性将至最低。

### 条款29：为“异常安全”而努力是值得的(Strive for exception-safe code.)
- 当异常被抛出时，带有异常安全性的函数会：
	- 不泄露任何资源
	- 不允许数据败坏
- 异常安全函数(Exception-safe functions)即使发生异常也不会泄露资源或允许任何数据结构败坏。这样的函数区分为三种可能的保证：基本型、强烈型、不抛异常型。
- “强烈保证”往往能够以copy-and-swap实现出来，但“强烈保证”并非对所有函数都可实现或具备现实意义。
- 函数提供的“异常安全保证”通常最高值等于其所调用之各个函数的“异常安全保证”中的最弱者。

### 条款30：透彻了解inlining的里里外外(Understand the ins and outs of inlining.)
- 将大多数inlining限制在小型、被频繁调用的函数身上。这可使日后的调试过程和二进制升级（binary upgradability）更容易，也可使潜在的代码膨胀问题最小化，使程序的速度提升机会最大化。
- 不要只因为function templates出现在头文件，就将它们声明为inline。

