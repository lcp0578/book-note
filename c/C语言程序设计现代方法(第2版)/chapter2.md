## 第2章 C语言基本概念
- 编译和链接
	- 预处理  
		首先程序会被送交给预处理器(preprocessor)。预处理器执行以#开头的命令（通常称为指令）。
	- 编译  
		编译器(compiler)会把程序翻译成机器指令（即目标代码）。然而，这样的程序还是不可以运行的。
	- 链接  
		链接器(linker)把由编辑器产生的目标代码和所需的其他附加代码整合在一起，这样才最终产生了完全可执行的程序。
- 3个关键语言特性
	- 指令（预处理器执行的命令）
	- 函数（构建程序的构建块）
	- 语句（程序运行时执行的命令）
- 注释
	
		/* this is comment */
		// this another comment //C99提供
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
	- _Bool
	- _Complex
	- _Imaginary