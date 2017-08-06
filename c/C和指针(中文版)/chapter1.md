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
- printf
- scanf
	