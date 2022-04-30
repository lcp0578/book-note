## 第2章 GUI应用程序设计基础
- 项目文件说明
	- `.pro`存储项目设置的文件。
	- `main.cpp`主程序入口文件，实现了`main()`函数
	- `.ui`窗体页面文件，一个XML格式存储的窗体上的元件及其布局的文件。
	- `mainwindow.h`是所设计的窗体类的头文件。
	- `mainwindow.cpp`是`mainwindow.h`里自定义类的实现文件。
- 标准`C++`语言里并没有`property`关键字，`property`是Qt对标准`C++`的扩展，使得在Qt Designer里就可以可视化设置类的数据。
- Qt的宏：QT_BEGIN_NAMESPACE、QT_END_NAMESPACE
	- 在qglobal.h中我们可以看到这样的定义
	
			# define QT_BEGIN_NAMESPACE namespace QT_NAMESPACE {
			# define QT_END_NAMESPACE }
	- 因此：
	
			QT_BEGIN_NAMESPACE

			namespace Ui { class MainWindow; }

			QT_END_NAMESPACE
			//等价于
			namespace QT_NAMESPACE {
				namespace Ui { class MainWindow; }
			}
- 信号与槽关联是用`QObject::connect()`函数实现的，其基本格式是：

		QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
	connect()是QObject类的一个静态函数，而QObject是所有Qt类的基类，在实际调用时可以忽略前面的限定符，所以可以直接写为：

		connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
	SIGNAL和SLOT是Qt的宏，用于指明信号和槽，并将它们的参数转换为相应的字符串。
- Qt Creator快捷键
	- `F4` Switch Header/Source在同名头文件和源程序文件之间切换
	- `F2` Follow Symbol Under Cursor 跟踪光标下的符号，若是变量，可跟踪到变量声明的地方；若是函数体或函数声明，可在两者之间切换
	- `F1` Context Help 为光标所在的符号显示帮助文件的内容
- 查看帮助文档
	- Qt Creator `Help` -> `context`
	- Qt Assistant帮助系统


