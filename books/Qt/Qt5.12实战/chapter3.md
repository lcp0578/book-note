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
- `QChar`类是Qt中用于表示一个字符的类，实现在`QtCore`共享库中。
- `QChar`类的内部用两个字节的Unicode编码来表示一个字符。

####  QString类
- C++语言提供了两种字符串的实现：
	- C风格的的字符串，以`'\0'`结尾
	- C++中的`std::string`，即标准模板库中的字符串类。
- Qt提供了自己的字符串类：`QString`。
	- QString类存储字符串采用的是Unicode码，每一个字符都是一个16位的`QChar`类对象，而不是8位的`char`类型字符，所以`QString`类用于处理中文字符没有问题。
- `QString`类有如下特点
	- 使用隐式共享技术来节省内存和减少不必要的数据备份。
	- 跨平台使用，不用考虑字符串的平台兼容性。
	- `QString`类直接支持字符串的平台兼容性。
	- `QString`类直接支持字符串之间的大小比较（按照字典顺序）。
	- `QString`类直接支持不同编码下的字符串转换。
	- `QString`类直接支持`std::string`和`std::wstring`之间的相互转换。
	- `QString`类直接支持正则表达式的使用。
- QTextCodec类可以用来执行转码操作。
#### 列表类QList
- `QList`是一种表示链表的模板类，是Qt的一种泛型容器类。
- `QList`类以列表的形态存储并管理其中的列表元素，并支持基于快速索引的数据存取，也可以进行快速的数据删除操作。
- 对于尺寸比指针大的共享类，使用`QVector`类会更好。
- `QLinkedList`类的成员函数是基于迭代器来实现的。

#### 字符串列表类QStringList
- 字符串列表类`QStringList`是从`QList<QString>`继承而来的，在处理多个字符串时使用`QStringList`类有时能事半功倍。
- `QStringList`类可以使用`QList`类的所有函数（或称为方法）

#### Qt和字符集
- 计算机字符集可归类为3种：
	- 单字节字符集（SBCS）
	- 多字节字符集（MBCS）
	- 宽字符集（Unicode字符集）
- Unicode字符集
	- 被称为统一码、万国码或单一码。
	- 为了把全世界所有的文字符号都统一进行编码，标准化组织ISO提出了Unicode编码方案。
	- 这个编码方案可以容纳世界上所有文字和符合的字符编码，并规定任何语言中的任一字符都只对应一个唯一的数字。

#### 事件
- 通过调用QApplication::exec()函数启动事件主循环。
- 主循环从事件队列中获取事件，然后创建一个合适的QEvent类的对象或其子类的对象类表示该事件。
- 在此步骤中，事件循环首先处理所有发布的事件，直到队列为空；然后处理自发的事件；最后处理在自发事件期间产生的已发布事件。注意：发送的事件不由事件循环处理，该类事件会被直接传递给对象。 
- Qt中常见的事件
	- 鼠标事件（QMouseEvent）
	- 键盘事件（QKeyEvent）
	- 绘制事件（QPaintEvent）
	- 窗口尺寸改变事件（QResizeEvent）
	- 滚动事件（QScrollEvent）
	- 控件显示事件（QShowEvent）
	- 控件隐藏事件（QHideEvent）
	- 定时器事件（QTimerEvent）等。
- 事件的类型
	- 事件类型用枚举QEvent::Type来表示。
- 事件的传递事件的传递也称事件的分发
	- 它的基本规则是：若事件未被目标对象处理，则把事件传递给父对象处理；若父对象仍未处理，则传递给父对象的父对象处理；重复这个过程，直至事件被处理或到达顶层对象为止。
	- 注意：事件是在对象间传递的，这里是指对象的父子关系，而不是指类的父子关系。

#### 信号
- Qt为了方便一些事件的处理，引入了信号(Signal)的概念，封装了一些事件操作的标准预处理，使得用户不必处理底层事件，只需要处理信号即可。
- 信号和槽是Qt特有的信息传输机制，是Qt程序设计的重要基础，可以让互不干扰的对象建立一种联系。
- 信号可以有附加信息。
- 信号与槽（Slot）其实都是函数。当特定事件被触发时（如在编辑框输入了字符）将发送一个信号，与之连接的槽则可以接收到并做出响应。
- 信号和槽是多对多的关系。一个信号可以连接多个槽，一个槽也可以监听多个信号。
- Qt的事件和Qt中的信号是不一样的。后者通常用来使用widget，而前者是用来实现widget的。如果是使用系统预定义的控件，那么我们关心的是信号；如果使用的是自定义控件，那么我们关心的是事件。

#### 信号和槽的连接
- 信号和槽是通过系统函数`connect()`关联起来的，`connect()`函数只能在`QObject`类和`QObject`派生类中使用。
	- 该函数的原型声明如下

			QMetaObject::Connection QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
	- 其中，`sender`是一个指针，指向信号的发送对象
	- `signal`表示要发送的信号，具体使用时必须要用宏`SIGNAL()`将信号转为`const char*`类型
	- `receiver`是一个指针，指向信号的接收对象
	- `method`表示槽函数（信号处理函数），必须使用SLOT宏将其转换为`const char*`类型
	- `type`表示连接类型，可以取以下5个值
		- `Qt::AutoConnection`：默认值，使用这个值时连接类型会在信号发送时决定。如果接收者和发送者在同一个线程中，则自动使用`Qt::DirectConnection`类型。如果接收者和发送者不在同一个线程中，则自动使用`Qt::QueuedConnection`类型。
		- `Qt::DirectConnection`：槽函数会在信号发送的时候直接被调用，槽函数运行于信号发送者所在的线程。效果看上去就像是直接在信号发送位置调用了槽函数。这个在多线程环境下比较危险，可能会造成系统崩溃。
		- `Qt::QueuedConnection`：槽函数在控制回到接收者所在线程的事件循环时被调用，槽函数运行于信号接收者所在的线程。发送信号之后，槽函数不会立刻被调用，等到接收者的当前函数执行完，进入事件循环之后，槽函数才会被调用。在多线程环境下一般用这种连接类型。
		- `Qt::BlockingQueuedConnection`：槽函数的调用时机与`Qt::QueuedConnection`一致，不过发送完信号后发送者所在线程会阻塞，直到槽函数运行完毕。接收者和发送者绝对不能在同一个线程中，否则会死锁。在多线程间进行同步的场合可能需要这种类型。
		- `Qt::UniqueConnection`：可以通过按位或（|）运算符来把以上4个结合在一起使用。使用这种类型，当某个信号和槽已经连接时，再进行重复的连接就会失败，也就是说避免了重复连接。

#### 信号和事件的区别
- 信号由具体对象发出，然后会马上交给由connect()函数连接的槽进行处理。
- 对于事件，Qt使用一个事件队列对所有发出的事件进行维护；当新的事件产生时，会被追加到事件队列的尾部；前一个事件完成后，取出后面的事件接着进行处理。但是，必要的时候，Qt事件也是可以不进入事件队列而直接进行处理的。
- 事件还可以使用“事件过滤器”进行过滤。
- 总而言之，Qt的事件和Qt中的信号是不一样的。后者通常用来使用widget，而前者是用来实现widget的。如果是使用系统预定义的控件，那么我们关心的是信号；如果使用的是自定义控件，那么我们关心的是事件。
#### 获取系统当前时间
- 在Qt下，调用QDateTime类的静态函数currentDateTime()可以获得系统当前时间。比如：

		QDateTime current_date_time = QDateTime::currentDateTime();
		QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");//转为字符串
	- 注意，要转化成自己想要的格式。其中，yyyy表示年；MM表示月；dd表示日；hh表示小时；mm表示分；ss表示秒；zzz表示毫秒；ddd表示周几。