## 第一章 快速上手
- 要从逻辑上删除一段C代码，更好的办法是使用#if指令。
	
		#if 0
			statements
			.......
		#endif
- 预处理指令(preprocessor directives)

		#include <stdio.h> /* 标准I/O库， Standard I/O Library */
		#include <stdlib.h> /* 定义了EXIT_SUCCESS 和 EXIT_FAILURE 符号 */
		#include <string.h> /* 字符串操作函数 */
		#define MAC_COLS 20
		#define MAX_INPUT 1000
- 在C语言中，数组传参是以引用(reference)形式进行传递的，也就是传址调用，而标量和常量则是按值(value)传递的。
- 字符串常量(string literal)  
	"hello" 在内存中占据六个字节，按顺序分别是h、e、l、l、o和NUL。  
	NUL是ASCII字符集中'\0' 字符的名字，它的字节模式为全0.
	字符串是一串由NUL字节结尾的字符。
- printf  
	格式化输出
	- %d 以十进制形式打印一个整型值
	- %o 以八进制形式打印一个整型值
	- %x 以十六进制形式打印一个整型值
	- %g 打印一个浮点值
	- %c 打印一个字符
	- %s 打印一个字符串
	- \n 换行
- scanf  
	格式化输入
	- %d 读取一个整数 int
	- %ld 读取一个长整型值 long
	- %f 读取一个浮点数 float
	- %lf 读取一个双精度 double
	- %c 读取一个字符 char
	- %s 读取一个字符串 char数组型
- [demo code](code/chapter1.c)