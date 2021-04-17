## 第3章 C++类型探秘
- C++提供了运算符`sizeof`来计算变量的字节数，使用运算符`alignof`来确定变量在内存中的对齐方式。
- 内置类型
	- 整数类型（char类型是整数类型的一种）
	- 浮点类型
	- 布尔类型
- C++允许将0（零）视为false，将其他非零值视为true。
- C++提供的typedef语句可以为某个类型创建别名：

		typedef tuple<string, int> name_year_t;
        vector<name_year_t> beatles;
- C++11引入了另外一种机制来创建别名，即using语句；

		using name_year = tuple<string, int>