## 第1章 初识C++
- 与Visual Studio一起安卓的构建工具有：MSBuild和nmake。当用Visual Studio环境下构建一个Visual C++项目时，将使用MSBuild，并且会把编译规则存放在一个XML文件中。nmake是Microsoft在做个编译器之间维护程序多个版本的实用性工具。
- C++中，如果函数声明了返回值，那么它必须返回一个值。不过，该规则存在一个例外情况：如果main函数没有返回值，那么系统默认会将0作为它的返回值。
- main函数参数解释

        void main(int argc,char *argv[])
        {
            for(int i=0;i<argc;i++)
            {
                cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;
            }
            system("pause");
        }
	- argc 是 argument count的缩写，表示传入main函数的参数个数；
	- argv 是 argument vector的缩写，表示传入main函数的参数序列或指针，并且第一个参数argv[0]一定是程序的名称，并且包含了程序所在的完整路径，所以确切的说需要我们输入的main函数的参数个数应该是argc-1个；
- paragma