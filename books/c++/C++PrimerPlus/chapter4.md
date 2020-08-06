## 第4章 复合类型
- 数组
	- 存储在每个元素中值的类型
	- 数组名
	- 数组中的元素数
- `sizeof`运算符返回类型或数据对象的长度（单位为字节）。
	- 注意，如果将`sizeof`运算符用于数组名，得到的将是整个数组中的字节数。
	- 但如果将`sizeof`用于数组元素，则得到的将是元素的长度（单位为字节）。
- C-风格字符串(C-style string)

		char cat[8] = {'f', 'a','t','e', 's', 's', 'a', '\0'}
- `getline()` 、`get()`
- string类
- 结构体 `struct`
	- 如果结构体是结构名，则使用句点运算符；如果标识符是指向结构体的指针，则使用箭头运算符。
- 共用体，或称 联合体 `union`
	- 共用体(union)是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型。
	- 共用体的长度为其最大成员的长度。
- 枚举 `enum`
	- 枚举更常被用来定义相关的符号常量，而不是新类型。
- 指针
	- `*`运算符被称为间接值(indirect value)或解除引用(dereferencing)运算符，将其应用与指针，可以得到该地址处存储的值。
	- 一定要在对指针应用解除引用运算符(*)之前，将指针初始化为一个确定的、适当的地址。
	- new
	- delete
	- 一定要配对地使用new和delete，否则将发生内存泄露（memory leak），也就是说，被分配的内存再也无法使用了。如果内存泄露严重，则程序将由于不断寻找更多内存而终止。
	- 只能用delete来释放使用new分配的内存。然而，对空指针使用delete是安全的。
- 自动存储、静态存储和动态存储
- 数组的替代品
	- 模板类 `vector`

			#include <vector>
            ...
            using namespace std;
			vector <int> vi; //create a zero-size array of int
            vector <double> vd(n); //create an array of n doubles
	- 模板类 `array`(C++ 11)

			#include <array>
            ...
            using namespace std;
            array<int, 5> ai; //create array object of 5 ints
            array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
