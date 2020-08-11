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
            // typedef不会创建新类型，而只是为已有的类型建立一个新名称。
- 基于范围的for循环（C++）
	- 基于范围（range-based）的for循环
	
    		double prices[5] = {4.99, 10.99, 6.87}
            for(double x : prices)
            	cout << x << std:endl;
            for(double &x : prices)
            	x = x * 0.8;
            for(int x : {3, 5, 2, 8, 6})
                cout << x << " "
            cout << '\n';