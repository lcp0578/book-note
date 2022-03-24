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
### 多态
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

		#include <iostream>
		#include <vector>
		#include <string>
		
		using namespace std;
		
		#define interface struct
		
		interface IPrint
		{
			virtual void set_page(/*size, orientation etc*/) = 0;
			virtual void print_page(const string& str) = 0;
		};
		
		interface IScan
		{
			virtual void set_page(/*resolution etc*/) = 0;
			virtual string scan_page() = 0;
		};
		
		class inkjet_printer : public IPrint, public IScan
		{
		public:
			virtual void IPrint::set_page(/*size, orientation etc*/) override
			{
				//设置页面属性
			}
			virtual void print_page(const string& str) override
			{
				cout << str << endl;
			}
			virtual void IScan::set_page(/*resolution etc*/) override
			{
				//设置页面属性
			}
			virtual string scan_page() override
			{
				static int page_no;
				string str("page ");
				str += to_string(++page_no);
				return str;
			}
		};
		
		void print_doc(IPrint* printer, vector<string> doc);
		
		void print_doc(IPrint* printer, vector<string> doc)
		{
		}
		
		void scan_doc(IScan* scanner, int num_pages);
		
		void scan_doc(IScan* scanner, int num_pages)
		{
		}
		
		
		
		int main(int argc, char* argv[])
		{
			inkjet_printer inkjet;
			IPrint* printer = &inkjet;
			printer->set_page(/*属性*/);
			vector<string> doc{ "page 1", "page 2", "page 3" };
			print_doc(printer, doc);
		
			IScan* scanner = &inkjet;
			scanner->set_page(/*属性*/);
			scan_doc(scanner, 5);
		
			IPrint* printer2 = dynamic_cast<IPrint*>(scanner);
			if (printer2 != nullptr)
			{
				printer2->set_page(/*属性*/);
				vector<string> doc{ "page 4", "page 5", "page 6" };
				print_doc(printer2, doc);
			}
		}
- mixin类(混入类)

		#include <iostream>
		#include <vector>
		#include <string>
		
		using namespace std;
		
		template <typename BASE>
		class mixin : public BASE
		{
		public:
			void something()
			{
				cout << "mixin do something" << endl;
				BASE::something();
				cout << "mixin something else" << endl;
			}
		};
		
		template <typename BASE>
		class mixin2 : public BASE
		{
		public:
			void something()
			{
				cout << "mixin2 do something" << endl;
				BASE::something();
				cout << "mixin2 something else" << endl;
			}
		};
		
		
		class impl
		{
		public:
			void something()
			{
				cout << "impl do something" << endl;
			}
		};
		
		int main(int argc, char* argv[])
		{
			mixin<impl> obj;
			obj.something();
			/*
			mixin do something
			impl do something
			mixin something else
			*/
			mixin2<mixin<impl>> obj2;
			obj2.something();
			/*
			mixin2 do something
			mixin do something
			impl do something
			mixin something else
			mixin2 something else
			*/
			return 0;
		}
### 多态应用

	#include <iostream>
	#include <string>
	#include <vector>
	#include <fstream>
	#include <memory>
	
	using namespace std;
	
	#define interface struct
	
	interface IWork; //前向说明
	
	interface ISerializer 
	{
		virtual void write_string(const string& line) = 0;
		virtual void write_worker(IWork* worker) = 0;
		virtual void write_workers(const vector<unique_ptr<IWork>>& workers) = 0;
	};
	
	interface ISerializable 
	{
		virtual void serialize(ISerializer *stm) = 0;
	};
	
	interface IWork
	{
		virtual const char* get_name() = 0;
		virtual const char* get_position() = 0;
		virtual void do_work() = 0;
	};
	
	class file_writer : public ISerializer
	{
		ofstream stm;
	public:
		file_writer() = delete;
		file_writer(const char* file) { stm.open(file, ios::out); }
		~file_writer() { close(); }
		void close() { stm.close(); }
		virtual void write_worker(IWork* worker) override
		{
			ISerializable* object = dynamic_cast<ISerializable*>(worker);
			if (object != nullptr)
			{
				ISerializer* serializer = dynamic_cast<ISerializer*>(this);
				serializer->write_string(typeid(*worker).raw_name());
				object->serialize(serializer);
			}
		}
	
		virtual void write_workers(const vector<unique_ptr<IWork>>& workers) override
		{
			write_string("[[");
			for (const unique_ptr<IWork>& member : workers)
			{
				write_worker(member.get());
			}
			write_string("]]");
		}
	
		virtual void write_string(const string& line) override
		{
			stm << line << endl;
		}
	};
	
	
	interface IManage
	{
		virtual const vector<unique_ptr<IWork>>& get_team() = 0;
		virtual void manage_team() = 0;
	};
	
	interface IDevelop
	{
		virtual void write_code() = 0;
	};
	
	class worker : public IWork, public ISerializable
	{
		string name;
		string position;
	public:
		worker() = delete;
		worker(const char* n, const char* p) : name(n), position(p) {}
		virtual ~worker() {};
	
		virtual const char* get_name() override
		{
			return this->name.c_str();
		}
	
		virtual const char* get_position() override
		{
			return this->position.c_str();
		}
	
		virtual void do_work() override
		{
			cout << "worker do_work" << endl;
		}
	
		virtual void serialize(ISerializer* stm) override
		{
			stm->write_string(name);
			stm->write_string(position);
		}
	};
	
	class manager : public worker, public IManage
	{
		vector<unique_ptr<IWork>> team;
	public:
		manager() = delete;
		manager(const char* n, const char* p) : worker(n, p) {}
		const vector<unique_ptr<IWork>>& get_team()
		{
			return team;
		}
		virtual void manage_team() override
		{
			cout << "manages a team" << endl;
		}
		void add_team_member(IWork* worker)
		{
			team.push_back(unique_ptr<IWork>(worker));
		}
		virtual void do_work() override
		{
			this->manage_team();
		}
	
		virtual void serialize(ISerializer* stm) override
		{
			worker::serialize(stm);
			stm->write_workers(this->team);
		}
	};
	
	class project_manager : public manager
	{
	public:
		project_manager() = delete;
		project_manager(const char* n) : manager(n, "Project Manager") {}
		virtual void manage_team() override
		{
			cout << "manages team of developers" << endl;
		}
	
		virtual void serialize(ISerializer* stm) override
		{
			manager::serialize(stm);
		}
	};
	
	void print_team(IWork* mgr)
	{
		cout << mgr->get_name() << " is " << mgr->get_position() << " and ";
		IManage* manager = dynamic_cast<IManage*>(mgr);
		if (manager != nullptr)
		{
			cout << " manage a team of:" << endl;
			const vector<unique_ptr<IWork>>& team = manager->get_team();
			for (unsigned idx = 0; idx < team.size(); ++idx)
			{
				cout << team[idx]->get_name() << " " << team[idx]->get_position() << endl;
			}
		}
		else
		{
			cout << "is not a manager" << endl;
		}
	}
	
	class cpp_developer : public worker, public IDevelop
	{
	public:
		cpp_developer() = delete;
		cpp_developer(const char* n) : worker(n, "C++ Dev") {};
		void write_code()
		{
			cout << "Writing C++ ..." << endl;
		}
		virtual void do_work() override
		{
			this->write_code();
		}
	
		virtual void serialize(ISerializer* stm) override
		{
			worker::serialize(stm);
		}
	};
	
	class database_admin : public worker, public IDevelop
	{
	public:
		database_admin() = delete;
		database_admin(const char* n) : worker(n, "DBA") {};
		void write_code()
		{
			cout << "Writing SQL ..." << endl;
		}
		virtual void do_work() override
		{
			this->write_code();
		}
		virtual void serialize(ISerializer* stm) override
		{
			worker::serialize(stm);
		}
	};
	
	void serialize(const char* file)
	{
		project_manager pm("Agnes");
		pm.add_team_member(new cpp_developer("Bill"));
		pm.add_team_member(new cpp_developer("Chris"));
		pm.add_team_member(new cpp_developer("Dave"));
		pm.add_team_member(new database_admin("Edith"));
		print_team(&pm);
	
		cout << endl << "writing to " << file << endl;
	
		file_writer writer(file);
		ISerializer *ser = dynamic_cast<ISerializer*>(&writer);
		ser->write_worker(&pm);
	
	}
	
	void usage()
	{
		cout << "Usage: team_builder file [r|w]" << endl;
	}
	int main(int argc, const char* argv[])
	{
		//project_manager pm("Agnes");
		///*pm.add_team_member(new worker("Bill", "Developer"));
		//pm.add_team_member(new worker("Chris", "Developer"));
		//pm.add_team_member(new worker("Dave", "Developer"));
		//pm.add_team_member(new worker("Edith", "DBA"));*/
		//pm.add_team_member(new cpp_developer("Bill"));
		//pm.add_team_member(new cpp_developer("Chris"));
		//pm.add_team_member(new cpp_developer("Dave"));
		//pm.add_team_member(new database_admin("Edith"));
		//print_team(&pm);
	
		if (argc < 2)
		{
			usage();
			return 0;
		}
	
		bool write = true;
		const char* file = argv[1];
		if (argc > 2) write = (argv[2][0] == 'w');
	
		cout << (write ? "Write " : "Read ") << file << endl << endl;
		if (write) serialize(file);
		return 0;
	}