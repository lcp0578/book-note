## 第8章 概念和泛型编程
#### 8.1 引言
- 模板作为编译时计算和类型控制提供了强有力的机制，使得我们可以编写出更加简洁高效的代码。
- 模板的第一个也是最常见的应用是支持泛型编程(generic programming)，泛型编程主要关注通用的算法的设计、实现和使用。
- 模板是C++支持泛型编程最重要的工具，提供了（编译时）参数级多态性。
#### 8.2 概念
- 大多数模板参数必须符合特定需求才能被正常编译和运行。这是说，其实绝大多数模板都应当时受限模板。
#### 8.3 泛型编程
- C++直接支持的泛型编程形式围绕着这样的思想：从具体、高效的算法中抽象出来，从而获得可以与不同数据表示相结合的泛型算法，以生成各种有用的软件。
#### 8.4 可变参数模板
- 定义模板时可以令其接受任意数量、任意类型的实参，这样的模板被称为可变参数模板（variadic template）。
#### 8.5 模板编译模型
- 为模板提供的实例化时类型检查，用来检查模板定义中参数的使用情况。这种机制提供了被称为压字类型的编译特性。
#### 8.6 建议
- 为所有模板实参指定概念。