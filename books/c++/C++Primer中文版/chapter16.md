## 第16章 模板与泛型编程
- 面向对象编程（OOP）和泛型编程都能处理在编写程序时不知道类型的情况。不同之处在于：OOP能处理类型在程序运行之前都未知的情况；而在泛型编程中，在编译时就能获知类型了。
- 模板是C++中泛型编程的基础。一个模板就是一个创建类或函数的蓝图或者说公式。
- 函数模板定义（在模板定义中，模板参数列表不能为空）

		template <typename T>
        int compare(const T &v1, const T &v2)
        {
        	if(v1 < v2) return -1;
            if(v2 < v1) return 1;
            return 0;
        }
- 编译器用推断出的模板参数来为我们**实例化**(instantiate)一个特定版本的函数。当编译器实例化一个模板时，它使用实际的模板实参代替对应的模板参数来创建出模板的一个新“实例”。
- 非类型模板参数

		template<unsigned N, unsigned M> 
		int compare(const char (&p1)[N], const char (&p2)[M])
		{
			return strcmp(p1, p2);
		}
	- 非类型模板参数的模板实参必须是常量表达式。
- inline和constexpr的函数模板

		template <typename T> inline min(const T&, const T&);
- 模板程序应该尽量减少对实参类型的要求。
- 模板编译
	- 当编译器遇到一个模板定义时，它并不生成代码。只有当我们实例化出模板的一个特定版本时，编译器才会生成代码。当我们使用（而不是定义）模板时，编译器才生成代码，这一特性影响了我们如何组织代码以及错误何时被检测到。
	- 通常，当我们调用一个函数时，编译器只需要掌握函数的声明。类似的，当我们使用一个类类型的对象时，类定义必须是可用的，但成员函数的定义不必已经出现。因此，我们将类定义和函数声明放在头文件中，而普通函数和类的成员函数的定义放在源文件中。
	- 模板则不同：为了生成一个实例化版本，编译器需要掌握函数模板或类模板成员函数的定义。因此，与非模板代码不同，模板的头文件通常即包括声明也包括定义。
- 大多数编译错误在实例化期间报告
- 类模板
	- **类模板**(class template)是用来生成类的蓝图的。与函数模板的不同之处是，编译器不能为类模板推断模板参数类型。 
	- 一个类模板的每个实例都形成一个独立的类。
	- 类模板的成员函数
		- 与其他任何类相同，我们既可以在类模板内部，可以在类模板外部为其定义成员函数，且定义在类模板内的成员函数被隐式声明为内联函数。
	- 类模板成员函数的实例化
		- 默认情况下，一个类模板的成员函数只有当程序用到它时才进行实例化。
	- 在一个类模板的作用域内，我们可以直接使用模板名而不必指定模板实参。

			#include <string>
	        #include <initializer_list>
			#include <vector>
	        
	        template <typename T> class Blob {
	            public:
	                typedef T value_type;
	                typedef typename std::vector<T>::size_type size_type;
	                //构造函数
	                Blob();
	                Blob(std::initializer_list<T> il);
	                //Blob元素数目
	                size_type size() const {return data->size();}
	                bool empty() const {return data->empty();}
	                //添加和删除元素
	                void push_back(const T &t) {data->push_back(t);}
	                void push_back(T &&t) { data->push_back(std::move(t));}
	                void pop_back();
	                //元素访问
	                T& back();
	                T& operator[](size_type i);
	            private:
	                std::shared_ptr<std::vector<T>> data;
	                //若data[i]无效，则抛出msg
	                void check(size_type i, const std::string &msg) const;
	        };
	        
	        #include "Blob.h"
	
	        template <typename T>
	        void Blob<T>::check(size_type i, const std::string &msg) const 
	        {
	            if (i >= data->size())
	                throw std::out_of_range(msg)
	        }
	
	        template <typename T> 
	        T& Blob<T>::back()
	        {
	            check(0, "back on empty Blob");
	            return data->back();
	        }
	
	        template <typename T>
	        T& Blob<T>::operator[](size_type i)
	        {
	            check(i, "subscript out of range");
	            return (*data)[i];
	        }
	
	        template <typename T> 
	        Blob<T>::Blob():data(std::make_shared<std::vector<T>>()){}
- 一个类也可以将另一个模板的每个实例都声明为自己的友元，或者限定特定的实例为友元
