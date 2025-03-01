## 第9章 标准库
#### 9.1 引言
- 在IOS C++标准中，标准库规范几乎占了三分之二的篇幅。你应深入了解并尽量使用标准库来解决问题，而不是使用自制的替代品来编写程序。
#### 9.2 标准库组件
- 标准库提供的工具和方法可以分为如下几类：
	- 运行时语言支持库（例如，对资源分配、异常和运行时类型信息的支持）。
	- C标准库（进行了非常小的修改，以便尽量减少与类型系统的冲突）。
	- 字符串库，提供对国际字符集、本地化及子字符串只读视图的支持。
	- 正则表达式库，提供对正则表达式的匹配的支持。
	- I/O流库，这是一个可扩展的输入输出框架，用户可向其中添加自己设计的类型、流、缓冲策略、区域设定和字符集。它还提供了对输出进行灵活格式化的设施。
	- 以可移植的方式处理文件系统的文件操作库。
	- 容器框架库（如vector和map）和算法库（如find()、sort()和merge()）。人们习惯上称这个框架为标准模板库（STL），用户可向其中添加自己定义的容器和算法。
	- 范围库，包括视图、发生器及管道。
	- 概念库，包含基础类型及范围的概念。
	- 数值计算支持库，例如，标准数学函数，复数、向量的数学运算，数学常数，以及随机数发生器。
	- 并发程序支持库，包括thread和锁机制。在此基础上，用户能够以库的形式添加新的并发模型。
	- 同步协程库及一步协程库。
	- 并行库，包含部分数学算法及大多数STL算法的并行版本，比如sort()及reduce()。
	- 支持模板元程序设计的工具库（如类型特性）、STL风格的泛型程序设计（如pair）和通用程序设计（如variant和optional）。
	- 用于资源管理的“智能指针”库（如unique_ptr和shared_ptr）。
	- 特殊用途容器库，例如array、bitset和tuple。
	- 绝对时间与时段库，例如time_point及system_clock。
	- 日历库，例如month和time_zone。
	- 单位后缀库，例如ms代表毫秒及i代表虚数。
	- 元素序列操作库，比如视图、string_view和span。
#### 9.3 标准库的组织
- 标准库的所有设施都被放在名为std的命名空间中，用户可以通过模块或者头文件来访问。
#### 9.4 建议
-  不要认为标准库在任何情况下都是理想之选。
