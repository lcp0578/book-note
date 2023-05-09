## 第2章 Fortran基础知识
- Fortran对字母大小写不敏感。
- Fortran语句结构
	- 可执行语句(executable)：描述程序执行时的行为（如加、减、乘、除等）
	- 不可执行语句(unexecutable)：对程序中的相应操作进行必要的说明。
	- Fortran语句可以放在书写行的任意位置，每行可以长达132个字符。如果语句太长，不适合放在一行，那么可以用`&`符号标记在下一行继续这行的书写，直到结束（也可以选择，从下一行开始）。
	- 以数字开始的行，这些数字称为语句标号(statement lable)。语句标号可以是1~99999之间的任何一个数字，它是Fortran语句的“名字”，使用它可以在程序的其他部门引用这条语句。
	- 感叹号`!`后面跟随的字符是注释(comment)，Fortran编译器不编译注释。
- 程序示例

		PROGRAM my_first_program ! 声明部分，指定程序的名字
		! Purpose:
		!    To illustrate some of the basic features of a Fortran program.
		INTEGER :: i, j, k ! All variables are integers，类型声明
		WRITE (*, *) 'Enter the numbers to multiply:' ! 执行部分
		READ (*, *) i, j
		k = i * j
		WRITE (*, *) 'Result = ', k
		
		! Finish up. 以下为：终止部分
		STOP
		END PROGRAM my_firs_program
- Fortran编程原则：保留字都大写，而程序变量用小写字母表示。
- Fortran程序，编译，形成：目标文件，再进行：链接，生成：可执行程序。
- 内置函数
- `IMPLICIT NONE` 语句
	- 当使用它时，`IMPLICIT NONE`语句使Fortran中默认提供输入值的功能丧失。
	- 当程序含有`IMPLICIT NONE`语句，没有出现在显式类型声明语句中的变量被认为是错的。
	- `IMPLICIT NONE`语句出现在`PROGRAM`语句之后和类型声明语句之前。
	- 当程序含有`IMPLICIT NONE`语句，程序员必须显式声明程序中每个变量的类型。