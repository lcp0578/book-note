## 第3章 Qt类库概述
### Qt核心特点
- 概述
	- Qt的元对象编译器(moc)是一个预处理器。在源程序被编译前先将这些Qt特性的程序转换为标准C++兼容的形式，然后再由标准C++编译器进行编译。
	- 这就是为什么在使用信号与槽机制的类里，必须添加一个`Q_OBJECT`宏的原因，只有添加了这个宏，moc才能对类里的信号与槽的代码进行预处理。
- 元对象系统(Meta-Object System)提供了对象之间通信的信号与槽机制、运行时类型信息和动态属性系统。元对象系统由以下三个基础组成：
	- QObject类是所有使用元对象系统类的基类。
	- 在一个类的`private`部分声明`Q_OBJECT`宏，使得类可以使用元对象的特性，如动态属性、信号与槽。
	- MOC(元对象编译器，Meta-Object Compiler)为每个`QObject`的子类提供必要的代码来实现元对象系统的特性。
- 除了信号与槽机制外，元对象还提供如下一些功能：
	- `QObject::metaObject()` 函数返回类关联的元对象，元对象类`QMetaObject`包含了访问元对象的一些接口函数，例如`QMetaObject::className()`函数可在运行时返回类的名称字符串。
	- `QMetaObject::newInstance()`函数创建类的一个新的实例。
	- `QObject::inherits(const char *className)`函数判断一个对象实例是否是名称为className的类或`QObject`的子类的实例。
	- `QObject::tr()`和`QObject::trUtf8()`函数可翻译字符串，用于多语言界面设计。
	- `QObject::setProperty()`和`QObject::property()`函数用于通过属性名称动态设置和获取属性值。
	- 对于`QObject`及其子类，还可以使用`qobject_cast()`函数进行动态投射。
- 属性系统
	- Qt提供一个`Q_PROPERTY()`宏可以定义属性，它也是基于元对象系统实现的。
	- 宏`Q_CLASSINFO()`可以为类的元对象定义附加信息。
- 信号与槽
	- 在槽函数里，使用`QObject::sender()` 可以获取信号发射者的指针。如果知道信号发射者的类型，可以将指针投射为确定的类型，然后使用这个确定类的接口函数。
### Qt全局定义
- `<QtGlobal>`头文件包含了Qt类库的一些全局定义，包括基本数据类型、函数和宏，一般的Qt类的头文件都会包含该文件，所以不用显示包含这个头文件也可以使用其中的定义。
- 数据类型定义
	- 为了确保在各个平台上各数据类型都有统一确定的长度，Qt为各种常见数据类型定义了类型符号。
- 函数
- 宏定义
	- `QT_VERSION`这个宏展开为数值形式0xMMNNPP(MM = major, NN = minor, PP = patch)表示Qt编译器ibanben，例如Qt编译器版本为Qt 5.9.1，则`QT_VERSION`为0x050901。
	- `QT_VERSION_CHECK` 这个宏展开为Qt版本号的一个整数表示，例如

			if(QT_VERSION >= QT_VERSIOB_CHECK(5, 0, 0))
	- `QT_VERSIOB_STR` 这个宏展开为Qt版本号的字符串
	- `QT_BYTE_ORDER`、`QT_BIG_ENDIAN`、`QT_LITTLE_ENDIAN`字节序
	- `Q_DECL_IMPORT`和`Q_DECL_EXPORT` 在使用或设计共享库时，用于导入或导出库的内容
	- `Q_DECL_OVERRIDE`在类定义中，用于重载一个虚函数。
	- `Q_DECL_FINAL`这个宏讲一个虚函数定于为最终级别。不能被重载，或定义一个类不能再被继承。
	- `Q_UNUSED(name)` 用于在函数中定义不在函数体里使用的参数。
	- `foreach(variable, container)` 用于容器类的遍历
	- `forever` 用于构造一个无限循环
	- `qDebug(const char *message, ...)` 在debugger窗体显示信息，如果编译器设置了`Qt_NO_DEBUG_OUTPUT`，则不作任何输出。
### 容器类
- 顺序容器类
	- `QList`
	- `QLinkedList`
	- `QVector`
	- `QStack`
	- `QQueue`
- 关联容器类
	- `QMap`
	- `QMultiMap`
	- `QHash`
	- `QMultiHash`
	- `QSet`
### 容器类的迭代
- Java类型迭代器
- STL类型迭代器
- `foreach`关键字
### Qt类库的模块
- Qt基本模块(Qt Essentials):提供了Qt在所有平台上的基本功能。
- Qt附加模块(Qt Add-Ons):实现了一些特定功能的提供附加价值的模块。
- 增值模块(Value-Add Modules):单独发布的提供额外价值的模块或工具。
- 技术预览模块(Technology Preview Modules):一些处于开发阶段，但是可以作为技术预览使用的模块。
- Qt工具(Qt Tools)：帮助应用程序开发的一些工具。
