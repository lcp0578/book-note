## 第2章 C语言基本概念
- 编译和链接
	- 预处理  
		首先程序会被送交给预处理器(preprocessor)。预处理器执行以#开头的命令（通常称为指令）。
	- 编译  
		编译器(compiler)会把程序翻译成机器指令（即目标代码）。然而，这样的程序还是不可以运行的。
	- 链接  
		链接器(linker)把由编辑器产生的目标代码和所需的其他附加代码整合在一起，这样才最终产生了完全可执行的程序。
- gcc编译器
	- GCC编译器是最流行的C编译器之一。
	- `% gcc -o pun pun.c`
- string literal 字符串字面量
- 3个关键语言特性
	- 指令（预处理器执行的命令）
	- 函数（构建程序的构建块。事实上，C程序就是函数的集合）
	- 语句（程序运行时执行的命令）
- 注释
	
		/* this is comment */
		// this another comment //C99提供
- 变量和赋值
	- 每一个变量都必须有一个类型（type）
- 初始化
	- 当程序开始执行时，某些变量会自动被设置为0，而大多数的变量则不会。
	- 没有默认值并且尚未在程序中被赋值的变量是未初始化的（uninitialized）
- 宏定义（macro definition）
	- `#define INCHES_PRE_POUND 16`
- 标识符（identifier）
	- 在编写程序时，需要对变量、函数、宏和其他的实体进行命名。这些名字成为标识符。
	- 在C语言中，标识符可以含有字母、数字和下划线，但是必须以字母或下划线开头。
- 关键字(keyword)
	- auto
	- break
	- case
	- char
	- const
	- continue
	- default
	- do
	- double
	- else
	- enum
	- extern
	- float
	- for
	- goto
	- if
	- inline(C99)
	- int
	- long
	- register
	- restrict(C99)
	- return
	- short
	- signed
	- sizeof
	- static
	- struct
	- switch
	- typedef
	- union
	- unsigned
	- void
	- volatile
	- while
	- _Bool(C99)
	- _Complex(C99)
	- _Imaginary(C99)