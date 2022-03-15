## 第5章 函数
- 函数原型并不一定必须包含参数名称。这是因为编译期间只需要知道参数的类型，而不是它们的名称。
- 内联化
	- 如果函数中计算某个值的操作可以在编译期间执行，那么我们可以在语句声明的左边使用关键字`constexpr`对它进行标记，以告知编译期在编译代码时计算它的值，从而达到优化代码性能的目的。
	- 如果函数值可以在编译过程中计算，则意味着必须在编译期间获知函数中的参数，因此它们必须是字面值。
	- 该函数也必须是一个单行函数。如果不符合这些条件，那么编译器将自行忽略这些声明符。
	- `inline`当其他代码调用函数时，它可以被放置在函数声明的左边作为一个提示编译器的标记，而不是让编译器在内存中插入一个到该函数的跳转，编译器应该将实际的代码副本放在调用函数中、此外，编译器可以自行忽略该声明符。
- 返回类型
	- 第一种是在函数名前面指定返回类型。
	- 第二种方法称为函数返回类型后置，需要用户将关键字`auto`放在函数名前面作为发回来类型，并使用`->`语法在参数列表后面给出实际的返回值类型。

			inline auto mult(int lhs, int rhs) -> int
            {
            	return lhs*rhs;
            }
	- 当函数被模板化并且返回类型可能不明显时，第二种语法很有用。
- 如果一个函数根本不会返回任何职，可以使用C++11属性`[[noreturn]]`对它进行标记。编译器可以根据这个属性编写出更高效的代码。
- 声明异常

		int calculate(int param) throw(overflow_error, other_error)//异常类型列表，逗号分隔
        {
        }
        int calculate(int param) throw(...)//可能抛出任何异常
        {
        }
        int calculate(int param) throw()//不会抛出异常
        {
        }
        //C++11风格，不会抛出异常
        int calculate(int param) noexcept
        {
        }
- 默认参数
	- 默认值是出现在函数定义而不是函数原型中。
- 可变参数

		#include <iostream>
		#include <cstdarg>
		
		using namespace std;
		
		int sum(int count, ...) {
			int sum = 0;
			va_list args;
			va_start(args, count);
			while (count--) {
				int i = va_arg(args, int);
				sum += i;
			}
			va_end(args);
			return sum;
		}
		
		int main() {
			cout << sum(0) << endl;
			cout << sum(6, -6, -5, -4, -3, -2, -1) << endl;
			cout << sum(3, 10, 20, 30) << endl;
			return 0;
		}
- 堆栈调用
	- 当调用一个函数时，编译器将为新的函数调用创建一个栈帧，并且它会将元素推送到堆栈上。
	- 这意味着在运行中发起一个函数调用时，在执行函数之前会产生一些内存开销和创建栈帧的性能开销，以及在函数执行完毕后清理方面的性能开销。
	- 如果一个函数时内联的，将不会产生这些开销，因为函数调用将使用当前的栈帧，而不是新建一个。
- 声明维护堆栈的方式
	- `__clrcall`
	- `__cdecl`
	- `__stdcall`
	- `__thiscall`
- 函数重载
- 声明函数指针
	- 获取函数地址的方法非常简单，只需要使用没有括号的函数名称即可：

			void *pv = get_status;
- 模板函数

		template<typename T, typename U>
		T maximun(T lhs, U rhs)
		{
			return (lhs > rhs) ? lhs : rhs;
		}
- 专一化模板

		template <typename T> int number_of_byte(T t) {
			return sizeof(t);
		}
		//专一化模板
		template <> int number_of_byte<const char*>(const char* str) {
			return strlen(str) + 1;
		}
		
		template<typename T>
		T maximum(T lhs, T rhs) {
			return (lhs > rhs) ? lhs : rhs;
		}
		//专一化模板
		template <> bool maximum<bool>(bool lhs, bool rhs) = delete;
- 可变参数模板
- 运算符重载
	- C++提供了关键字`operator`用于声明运算符函数而不使用函数调用语法，而是使用与运算符相关的语法。
- 函数对象
	- 头文件`<functional>`中包含多种可以当做函数对象使用的类型
		- 算数运算: `divides`、`minus`、`modulus`、`mutiplies`、`negate`、`plus`
		- 位运算：`bit_and`、`bit_not`、`bit_or`、`bit_xor`
		- 比较运算：`equal_to`、`greater`、`greater_equal`、`less`、`less_equals`、`not_equal_to`
		- 逻辑运算:`logical_and`、`logical_not`、`logical_or`
- lambda表达式用在将要使用函数对象的地方创建一个匿名函数对象，这可以让代码更易读。
- 综合示例

		#include <iostream>
		#include <string>
		#include <windows.h>
		#include <vector>
		#include <tuple>
		#include <iomanip>
		#include <algorithm>
		
		using namespace std;
		
		struct file_size {
			unsigned int high;
			unsigned int low;
		};
		
		using file_info = tuple<string, file_size>;
		
		void files_in_folder(const char* folderPath, vector<file_info>& files) {
			string folder(folderPath);
			folder += "*";
			WIN32_FIND_DATAA findfiledata{};
			void* hFind = FindFirstFileA(folder.c_str(), &findfiledata);
			cout << findfiledata.cFileName << endl;
			if (hFind != INVALID_HANDLE_VALUE)
			{
				do {
					string findItem(folderPath); //等价于 string findItem = folderPath;
					findItem += "";
					findItem += findfiledata.cFileName;
					if ((findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
					{
						string folder(findfiledata.cFileName);
						if (folder != "." && folder != "..") {
							files_in_folder(findItem.c_str(), files);
						}
					}
					else {
						file_size fs{};
						fs.high = findfiledata.nFileSizeHigh;
						fs.low = findfiledata.nFileSizeLow;
						files.push_back(make_tuple(findItem, fs));
					}
				} while (FindNextFileA(hFind, &findfiledata));
				FindClose(hFind);
			}
		}
		
		ostream& operator<<(ostream& os, const file_size fs) {
			int flags = os.flags();
			unsigned long long ll = fs.low + ((unsigned long long)fs.high << 32);
			os << hex << ll;
			os.setf(flags);
			return os;
		}
		bool operator>(const file_size& lhs, const file_size& rhs)
		{
			if (lhs.high > rhs.high) return true;
			if (lhs.high == rhs.high) {
				if (lhs.low > rhs.low) return true;
			}
			return false;
		}
		int main(int argc, char* argv[])
		{
			//if (argc < 2) return 1;
			string dir2("D:");
			vector<file_info> files;
			cout << dir2.c_str() << endl;
			files_in_folder(dir2.c_str(), files);
		
			sort(files.begin(), files.end(),
				[](const file_info& lhs, const file_info& rhs)
				{return get<1>(rhs) > get<1>(lhs);
				});
			for (auto file : files) {
				cout << setw(16) << get<1>(file) << " " << get<0>(file) << endl;
			}
			return 0;
		}