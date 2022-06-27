## 第17章 标准库特殊设施
- tuple类型
	- tuple的一个常见用途是从一个函数返回多个值。

	|tuple支持的操作| |
	|----|----|
	| `tuple<T1, T2, ..., Tn> t;` | t是一个tuple，成员数为n，第i个成员的类型为Ti。所有成员都进行值初始化。|
	|`tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);` |t是一个tuple，成员类型为T1...Tn，每个成员用对应的初始值vi进行初始化。次构造函数是explicit的。|
	|`make_tuple(v1, v2, ..., vn);` |返回一个用给定初始值初始化的tuple。tuple的类型从初始值的类型推断。|
	|`t1 == t2 / t1 != t2`| 当两个tuple具有相同数量的成员且成员对应相等时，两个tuple相等。这两个操作使用的==运算符来完成。一旦发现某对成员不等，接下来的成员就不用比较了。|
	|`t1 relop t2` |tuple的关系运算使用字典序。两个tuple必须具有相同数量的成员。使用<运算符比较t1的成员和t2中对应成员。|
	|`get<i>(t)` |返回t的第i个数据成员的引用；如果t是一个左值，结果是一个左值引用；否则，结果是一个右值引用。tuple的所有成员都是public的。|
	|`tuple_size<tupleType>::value`| 一个类模板，可以通过一个tuple类型来初始化。他有一个名为value的public constexpr static数据成员，类型为size_tt，表示给定tuple类型中成员的数量。|
	| `tuple_element<i, tupleTypr>::type`| 一个类模板，可以通过一个整型常量和一个tuple类型来初始化。它有一个名为type的public成员。表示给定tuple类型中指定成员的类型。|

- bitset类型
- 正则表达式
- 随机数
- IO库