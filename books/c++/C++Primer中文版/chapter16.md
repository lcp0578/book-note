## 第16章 模板与泛型编程
- 函数模板定义

		template <typename T>
        int compare(const T &v1, const T &v2)
        {
        	if(v1 < v2) return -1;
            if(v2 < v1) return 1;
            return 0;
        }
- 类模板

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
- 类模板成员函数的实例化
	- 默认情况下，一个类模板的成员函数只有当程序用到它时才进行实例化。
- 在一个类模板的作用域内，我们可以直接使用模板名而不必指定模板实参。