## 第6章 类
- 结构体和类之间的区别是，在默认情况下，结构体的成员是公有的，类的成员是 私有的。
- 对象的构造
	- 默认构造函数
	- 拷贝构造函数
	- 移动构造函数
	- 析构函数
	- 拷贝赋值
	- 移动赋值
- 显式标记构造函数
	- 在某些情节下，不希望昨晚构造函数参数传递的一种类型与另外一种类型进行隐式的转换。

			class mytype
			{
			public:
				explicit mytype(double x);
			};
			
			mytype t1 = 10.0; //不能通过编译，无法转换成mytype
			mytype t2(10.0); //通过编译
- 移动语义
- 对象和指针
- 智能指针
	- 标准库有3个智能指针类
		- unique_ptr
		- shared_ptr
		- weak_ptr
- 模板
- 综合示例

		#include <iostream>
		#include <string>
		#include <io.h>
		
		using namespace std;
		
		class search_handle
		{
			intptr_t handle;
		public:
			search_handle() : handle(-1) {}
			search_handle(intptr_t p) : handle(p) {}
			void operator=(intptr_t p) { handle = p; }
			//我们希望这个类的对象拥有句柄的独占所有权，因此通过如下代码来删除拷贝构造函数和拷贝赋值运算符
			search_handle(search_handle& h) = delete;
			void operator=(search_handle& h) = delete;
			//如果一个对象被移动，那么现有对象中的任何句柄都必须被释放
			search_handle(search_handle&& h) noexcept{ close(); handle = h.handle; }
			void operator=(search_handle&& h) noexcept { close(); handle = h.handle; }
			//支持隐式类型转换
			operator bool() const { return (handle != 1); }
			operator intptr_t() const { return handle; }
		
			void close()
			{
				if (handle != -1)
					_findclose(handle);
				handle = 0;
			}
			~search_handle() { close(); }
		};
		
		class file_search
		{
			search_handle handle;
			string search;
		public:
			file_search(const char* str) : search(str) {}
			file_search(const string& str) : search(str) {}
			const char* path() const { return search.c_str(); }
			void close() { handle.close(); }
			bool next(string& ret)
			{
				cout << ret << endl;
				_finddata_t find{};
				if (!handle) //代表第一次调用
				{
					cout << search.c_str() << endl;
					handle = _findfirst(search.c_str(), &find);
					if (!handle) return false;
				}
				else
				{
					if (-1 == _findnext(handle, &find)) return false;
				}
				ret = find.name;
				return true;
			}
		};
		void usage()
		{
			cout << "usage: search pattern" << endl;
			cout << "pattern is the file or folder to search for"
				<< "with or without windows wildcards * and ?" << endl;
		}
		
		int main(int argc, char* argv[])
		{
			/*char filePath[32];
			cin >> filePath;*/
			/*if (argc < 2)
			{
				usage();
				return 1;
			}*/
			string filePath = "ch*";
			file_search files(filePath);
			cout << "searching for:" << files.path() << endl;
			string file;
			while (files.next(file))
			{
				cout << file << endl;
			}
		}