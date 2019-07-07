## 8 补充知识
- 试图在一个函数中对不存在的全局变量赋值或者使用不存在的全局变量，将会抛出异常。

		attempt to perform arithmetic on a nil value
- Lua语言将所有不是false和nil的值当作真（特别地，Lua语言将0和空字符串也当做真）