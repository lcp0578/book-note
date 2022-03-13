## 第3章 C++类型探秘
- 一个变量就是一种类型的实例，同时也会分配相应的内存来保存这种类型的数据。
- C++提供了运算符`sizeof`来计算变量的字节数，使用运算符`alignof`来确定变量在内存中的对齐方式。
- 对于基本类型，运算符`sizeof`和`alignof`会返回相同的值、只有在需要对自定义类型上调用运算符`alignof`时，它将返回类型中最大的数据成员的对齐方式。
- 内置类型
	- 整数类型（char类型是整数类型的一种）
	- 浮点类型
		- `float`单精度
		- `double`双精度
		- `long double` 扩展双精度
	- 布尔类型
- C++允许将0（零）视为false，将其他非零值视为true。
- auto关键字

		#include <string>
		#include <vector>
		#include <tuple>
		#include <iostream>
		using namespace std;
		
		
		
		void main() {
			vector<tuple<string, int> > beatles;
			beatles.push_back(make_tuple("AAA", 1991));
			beatles.push_back(make_tuple("BBB", 1992));
			beatles.push_back(make_tuple("CCC", 1993));
			beatles.push_back(make_tuple("DDD", 1994));
		
		
			for (tuple<string, int> musician : beatles)
			{
				cout << get<0>(musician) << " " << get<1>(musician) << endl;
			}
			//使用auto简化
			for (auto musician : beatles)
			{
				cout << get<0>(musician) << " " << get<1>(musician) << endl;
			}
		}
- 存储类`thread_local`
	- 一般用于需要保证线程安全的函数中
	- 表示每个线程自身都拥有变量的副本。因此，如果两个线程访问了同一函数，函数中的变量会被标记为`thread_local`，这意味着每个线程只能看到它自己生成的变更。
- C++提供的typedef语句可以为某个类型创建别名：

		typedef tuple<string, int> name_year_t;
        vector<name_year_t> beatles;
- C++11引入了另外一种机制来创建别名，即using语句；

		using name_year = tuple<string, int>
- 结构体
	- 字节对齐
- 联合体
	- 联合体是所有成员占用同一内存的结构体，这种类型的大小是其最大成员的尺寸。因为联合体只能保存数据的一个元素，它是一种通过多张方式解析数据的机制。
- C++提供了一种名为`typeid`的运算符，它将返回程序运行时某个变量的类型信息。运行时类型信息(Runtime Type Information, RTTI)对于使用多态机制中的自定义类型非常重要。
- 转型
	- `const_cast`
	- `static_cast`
	- `reinterpret_cast`
	- `dynamic_cast`