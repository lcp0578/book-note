## 第二章 类型
- Go变量总是有固定的数据类型，类型决定了变量内存的长度和存储格式。
- 运行时，内存分配操作会确保变量自动初始化为二进制零值（zero value）,避免出现不可预测行为。
- 简短模式（short variable declaration）的限制
	- 定义变量，同时显示初始化
	- 不能提供数据类型
	- 只能用在函数内部
	- 简短模式并不总是重新定义变量，也可能是部分退出的赋值操作
		- 退化赋值的前提条件：最少有一个新变量被定义，且必须是同一作用域。
- Go并没有明确意义上的enum定义，不过可借助iota标识符实现一组自增常量值来实现枚举类型。
- 不同于变量在运行期分配存储内存（非优化状态），常量通常会被编译器在预处理阶段直接展开，作为指令数据使用。
- 基本类型

	| 类型 | 长度 | 默认值 | 说明 |
    | -- | -- | -- | -- |
    | bool | 1 | false | - |
    | byte | 1 | 0 | uint8 |
    | int,uint | 4,8 | 0 | 默认整数类型，依据目标平台，32或64位 |
    | int8, uint8 | 1 | 0 | -128 ~ 127; 0 ~ 255 |
    | int16, uint16 | 2 | 0 | -32,768 ~ 32,767; 0 ~ 65,535 |
    | int32, uint32 | 4 | 0 | -2^31 ~ 2^31-1; 0 ~ 2^32 |
    | int64, uint64 | 8 | 0 | -2^63 ~ 2^63-1; 0 ~ 2^64 |
    | float32 | 4 | 0.0 | - |
    | float64 | 8 | 0.0 | 默认浮点类型 |
    | complex64 | 8 |  | 复数类型,由float32组成 |
    | complex128 | 16 |  | 复数类型,由float64组成 |
    | rune | 4 | 0 | Unicode Code Point, int32|
    | uintptr | 4,8| 0 | 足以存储指针的uint |
    | string |  | "" | 字符串，默认值为空字符串，而非NULL |
    | array |  |  | 数组 |
    | struct |  |  | 结构体 |
    | function | | nil | 函数 |
    | interface | | nil | 接口 |
    | map | | nil | 字典，引用类型 |
    | slice || nil | 切片，引用类型 |
    | channel | | nil | 通道，引用类型 | 
- 引用类型
	- 所谓引用类型（reference type）特指 slice、map、channel这三种预定义类型。
	- 内置函数 `new` 按指定类型长度分配零值内存，返回指针，并不关心类型内部构造和初始化方式。
	- 而引用类型则必须使用`make`函数创建，编译器会将`make`转化为目标类型专用的创建函数（或指令），以确保完成全部内存分配和相关属性初始化。

- 反编译可执行文件

        $ go tool objdump -s "main\.main" chapter2
        TEXT main.main(SB) /Users/lcp0578/github.com/book-note/books/go/Go语言学习笔记/code/chapter2.go
          chapter2.go:3		0x104ea70		65488b0c2530000000	MOVQ GS:0x30, CX
          chapter2.go:3		0x104ea79		483b6110		CMPQ 0x10(CX), SP
          chapter2.go:3		0x104ea7d		7646			JBE 0x104eac5
          chapter2.go:3		0x104ea7f		4883ec10		SUBQ $0x10, SP
          chapter2.go:3		0x104ea83		48896c2408		MOVQ BP, 0x8(SP)
          chapter2.go:3		0x104ea88		488d6c2408		LEAQ 0x8(SP), BP
          chapter2.go:6		0x104ea8d		e85e4efdff		CALL runtime.printlock(SB)
          chapter2.go:6		0x104ea92		48c7042405000000	MOVQ $0x5, 0(SP)
          chapter2.go:6		0x104ea9a		e8d155fdff		CALL runtime.printint(SB)
          chapter2.go:6		0x104ea9f		e88c50fdff		CALL runtime.printsp(SB)
          chapter2.go:6		0x104eaa4		48c7042403000000	MOVQ $0x3, 0(SP)
          chapter2.go:6		0x104eaac		e8bf55fdff		CALL runtime.printint(SB)
          chapter2.go:6		0x104eab1		e8ca50fdff		CALL runtime.printnl(SB)
          chapter2.go:6		0x104eab6		e8b54efdff		CALL runtime.printunlock(SB)
          chapter2.go:7		0x104eabb		488b6c2408		MOVQ 0x8(SP), BP
          chapter2.go:7		0x104eac0		4883c410		ADDQ $0x10, SP
          chapter2.go:7		0x104eac4		c3			RET
          chapter2.go:3		0x104eac5		e8e684ffff		CALL runtime.morestack_noctxt(SB)
          chapter2.go:3		0x104eaca		eba4			JMP main.main(SB)
          :-1			0x104eacc		cc			INT $0x3
          :-1			0x104eacd		cc			INT $0x3
          :-1			0x104eace		cc			INT $0x3
          :-1			0x104eacf		cc			INT $0x3