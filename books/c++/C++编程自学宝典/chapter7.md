## 第7章 面向对象编程简介
### 继承和组合
- 从一个类继承

		#include <string>
		
		using namespace std;
		
		class os_file
		{
			const string file_name;
			int file_handle;
			//其他数据成员
		public:
			os_file(const string& name) : file_name(name), file_handle(open_file(name)) {}
			~os_file() { close_file(file_handle); }
			long get_size_in_bytes();
			//其他方法
		};
		
		class mp3_file : public os_file
		{
			long length_secs;
			//其他数据成员
		public:
			mp3_file(const string& name) : os_file(name) {}
			~mp3_file() {/*清理mp3文件*/ }
			long get_length_in_seconds();
			//其他方法
		};
		
		long os_file::get_size_in_bytes()
		{
			return 0;
		}
		
		long mp3_file::get_length_in_seconds()
		{
			return 0;
		}
- 调用派生类实例时，添加任意基类中同名的方法都会隐藏基类的方法。
- 如果有一个基类指针，可以使用关键字`static_cast`将它转型为派生类指针。
- 如果正在编写一个基类，并且打算一直将它当做基类使用，则可以让西沟函数的类型是`protected:`
- 可以使用`using`语句通过派生类转换访问层级。
- 继承访问层级
	- 对于一个类来说，如果没有提供继承访问声明符，编译器将假定它是私有的；
	- 对于一个结构体，如果没有提供继承访问声明符，编译器将假定它是公有的。
- 多继承
#### 多态
- 虚方法
- 友元和继承
- 重载和关键字final
	- 如果错误地输入了派生类虚方法的原型，我们的本意是调用新版本的方法，但是实际上将调用基类的方法。声明符`override`是专门防止这类问题而诞生的。
- 虚拟继承
- 抽象类
	- C++提供了一种名为纯虚函数的机制，用于指示该方法应该被派生类重写。

			struct abstract_base
			{
				virtual void f() = 0;
				void g()
				{
					cout << "do something" << endl;
					f();
				}
			};
- 获取类型信息
	- C++提供了一种名为运行期型别辨识(Runtime Type Information, RTTI)的机制。
	- C++提供了一种执行运行时检查的转型运算符，并且这类运行时类型检查被称为`dynamic_cast`，如果对象可以被转型为所需的类型，那么该操作将成功执行并返回有效的指针。如果对象无法通过请求的指针访问，则转换失败，运算符将返回`nullptr`。
- 智能指针和虚方法
- 接口