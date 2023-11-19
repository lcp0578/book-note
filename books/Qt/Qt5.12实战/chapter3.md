## 第3章 Qt编程基础
#### Qt5模块(https://doc.qt.io/qt-5/qtmodules.html)
- Qt5模块分为Essentials Modules和Add-on Modules两部分。
- 基础模块 Essentials Modules
	- Qt Core,提供核心的非GUI功能，所有模块都需要这个模块。
	- Qt GUI，提供GUI程序的基本功能，包括与窗口系统的集成、事件处理、OpenGL和OpenGL ES集成、2D图像、字体、拖放等。
	- Qt Multimedia，提供适配、音频、收音机以及摄像头等功能。
	- Qt Network，提供跨平台的网络功能。
	- Qt QML，提供了QML（一种脚本语言，也提供了JavaScript的交互机制）使用的C++ API。
	- Qt Quick，允许Qt/C++程序中嵌入Qt Quick（一种基于Qt的高度动画的用户界面，适合于移动平台开发）。
	- Qt SQL，允许使用SQL访问数据库。
	- Qt Test，提供Qt程序的单元测试功能。
	- Qt WebKit，基于WebKit2的实现以及一套全新的QML API。
- 扩展模块 Add-on Modules
#### 字节数组类QByteArray
- 字节数组类QByteArray提供一个字节数组，用于存储原始字节。

#### QChar类
- QChar类是Qt中用于表示一个字符的类，实现在QtCore共享库中。
- QChar类的内部用两个字节的Unicode编码来表示一个字符。

####  QString类
- QString类有如下特点
	- 使用隐式共享技术来节省内存和减少不必要的数据备份。
	- 跨平台使用，不用考虑字符串的平台兼容性。
	- QString类直接支持字符串的平台兼容性。
	- QString类直接支持字符串之间的大小比较（按照字典顺序）。
	- QString类直接支持不同编码下的字符串转换。
	- QString类直接支持std::string和std::wstring之间的相互转换。
	- QString类直接支持正则表达式的使用。

#### 列表类QList
- QList类以列表的形态存储并管理其中的列表元素，并支持基于快速索引的数据存取，也可以进行快速的数据删除操作。
- 对于尺寸比指针大的共享类，使用QVector类会更好。

#### 字符串列表类QStringList
- 字符串列表类QStringList是从QList<QString>继承而来的，在处理多个字符串时使用QStringList类有时能事半功倍。

#### 事件
- 通过调用QApplication::exec()函数启动事件主循环。
- 主循环从事件队列中获取事件，然后创建一个合适的QEvent类的对象或其子类的对象类表示该事件。
- 在此步骤中，事件循环首先处理所有发布的事件，直到队列为空；然后处理自发的事件；最后处理在自发事件期间产生的已发布事件。注意：发送的事件不由事件循环处理，该类事件会被直接传递给对象。 

#### 信号
- 信号与槽（Slot）其实都是函数。当特定事件被触发时（如在编辑框输入了字符）将发送一个信号，与之连接的槽则可以接收到并做出响应。
- 信号和槽是多对多的关系。一个信号可以连接多个槽，一个槽也可以监听多个信号。
- Qt的事件和Qt中的信号是不一样的。后者通常用来使用widget，而前者是用来实现widget的。如果是使用系统预定义的控件，那么我们关心的是信号；如果使用的是自定义控件，那么我们关心的是事件。