## 第5章 循环和关系表达式
- `for`循环
- `while`循环
- `do while`循环
- 类型别名
	- 使用预处理器

			#define BYTE char;
            
            //在声明一系列变量时，会有问题
            #define FLOAT_POINTER float *;
            FLOAT_POINTER pa, pb;
            //预处理器置换将该声明转换为如下
            float * pa, pb;//pa a pointer to float, pb just a float
	- 使用C++（和C）的关键字`typedef`来创建别名。
	
    		typedef typeName aliasName;
            // typedef不会创建新类型，而只是为已有的蕾西建立一个新名称。