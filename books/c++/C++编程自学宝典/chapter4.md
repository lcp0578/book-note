## 第4章 内存、数组和指针
- 当对一个指针使用`sizeof`运算符时，将获得该指针的大小，而不是它指向的内容。
- 空指针
	- 常量 `nullptr`的类型并不是整数，而是`std::nullptr_t`。所有指针类型都可以隐式转换成该类型，因此`nullptr`可以用来初始化任意指针类型的变量。
- 内存类型
	- 静态或全局
	- 字符串池
	- 自动或者堆栈型
	- 自由存储
- 数组
	- 声明数组时必须使用一个常量为它指定大小。
	- 当在一个数组上执行`sizeof`运算符时，它会返回实际数组的字节大小，因此可以通过该值除以单个元素的大小来确定数组的大小。
- `reinterpret_cast`是最灵活和最危险的转型运算符，因为它会在没有类型检查的情况下执行任意指针类型之间的转型操作，本质上是不安全的。

		#include <iostream>
		
		using namespace std;
		
		const int VERY_BIG_NUMER =  999;
		
		int main()
		{
			const char* p1{ "hello" };
			const char* p2{ "hello" };
			cout << hex;
			cout << reinterpret_cast<int>(p1) << endl;
			cout << reinterpret_cast<int>(p2) << endl;
		
			int* pi;
			try
			{
				pi = new int[VERY_BIG_NUMER];
			}
			catch (const std::bad_alloc& e)
			{
				cout << "canot allocate" << endl;
				return 1;
			}
		
			delete[]pi;
		
			int* pi2 = new (std::nothrow) int[VERY_BIG_NUMER];
			if (nullptr == pi2) 
			{
				cout << "cannot allocate" << endl;
			}
			else {
				delete[]pi2;
			}
			return 0;
		}
- RAII
	- Resource Acquisition Is Initialization（ “资源获取就是初始化”）的简称，是C++语言的一种管理资源、避免泄漏的惯用法。
	- 利用的就是C++构造的对象最终会被销毁的原则。
	- RAII的做法是使用一个对象，在其构造时获取对应的资源，在对象生命期内控制对资源的访问，使之始终保持有效，最后在对象析构的时候，释放构造时获取的资源。
- C++标准库
	- STL: Standard Template Library
	- array
		- array类允许在堆栈上创建尺寸各异的数组，并且与内置数组类似，他们不能在运行时收缩或者扩展自己的尺寸。
		- 因为他们在堆栈上分配的，它们不需要在运行时调用内存分配器，不过很明显它们的尺寸应该小于堆栈的尺寸。这意味着array是小型元素数组理想解决方案。
		- array的大小必须在编译时明确告知编译器，并将之作为模板参数传递。
	- vector
		- vector类比array类更灵活，因此可以插入和移动元素，不过这些操作会带来额外的开销，因为实例是在运行时动态分配内存的，使用内存分配器会有一些开销，在初始化和销毁对象实例时(vector对象离开作用域后)会存在一些额外的开销。
		- vector类对象还会占用比它自身保存数据更多的内存。因此，它并不适合处理少量数据（array是一个更好的选择）。
- 引用
	- 引用没有被初始化为变量的值，即变量的数据，它只是变量的别名。
	- 常量引用
	- 返回引用
	- 临时引用
	- 右值引用
	- for循环区间和引用
	
