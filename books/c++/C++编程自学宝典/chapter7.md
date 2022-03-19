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