## 第6章 函数
- 参数传递
	- 当形参是引用类型时，我们说它对应的实参被引用传递(passed by reference)或者函数被引用调用(called by reference)。
	- 当实参的值被拷贝给形参时，形参和实参是两个相互独立的对象。我们说这样的实参被值传递(passed by value)或者函数被传值调用(called by value)。
- 尽量使用常量引用
- 为了编写能处理不同数量实参的函数，C++11新标准提供了两种主要的方法：
	- 如果所有的实参类型相同，可以传递一个名为`initializer_list`的标准库类型；
	- 如果实参的类型不同，我们可以编写一种特殊的函数，也就是可变参数模板。

			void error_msg(initializer_list<string> il)
			{
				for(auto beg = il.begin(); beg != il.end(); ++ beg)
					cout << *beg << "  ";
				cout << endl;
			}
- 不要返回局部对象的引用或指针
- 使用`decltype`

		int odd[] = {1, 3, 5, 7, 9};
		int even[] = {0, 2, 4, 6, 8};
		//返回一个指针，该指针指向含有5个整数的数组
		decltype(odd) *arrPtr(int i)
		{
			return (i % 2) ? &odd : &even;
		}
- 函数重载
	- 顶层`const`不影响传入函数的对象。一个拥有顶层`const`的形参无法和另一个没有顶层`const`的形参区分开来。
- 默认实参
- 内联函数可避免函数调用的开销
- `constexpr`函数是指能用于常量表达式的函数。
	- 定义`constexpr`需要遵循的约定：
		- 函数的返回类型及所有形参的类型都得是字面值类型，而且函数中必须有且只有一条`return`语句。
- 调试帮助
	- `assert`预处理宏
		- 所谓预处理宏其实是一个预处理变量，它的行为有点类似于内联函数。
		- `assert`的行为依赖一个名为`NDEBUG`的预处理变量的状态。如果定义了`NDEBUG`，则`assert`什么也不做。
		- 默认状态下没有定义`NDEBUG`，此时`assert`将执行运行时检查。
	- `__func__` 输出当前调试的函数的名字。
	- `__FILE__` 存放文件名的字符串字面值
	- `__LINE__` 存放当前行号的整型字面值
	- `__TIME__` 存放文件编译时间的字符串字面值
	- `__DATE__` 存放文件编译日期的字符串字面值
- 函数指针