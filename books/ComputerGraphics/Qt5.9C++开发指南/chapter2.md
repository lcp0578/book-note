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

			QT_BEGIN_NAMESPACE
			namespace Ui { class MainWindow; }
			QT_END_NAMESPACE
			//等价于
			namespace QT_NAMESPACE {
			namespace Ui { class MainWindow; }
			}
-信号与槽关联是用`QObject::connect()`函数实现的，其基本格式是：

			QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
	connect()是QObject类的一个静态函数，而QObject是所有Qt类的基类，在实际调用时可以忽略前面的限定符，所以可以直接写为：

			connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));


