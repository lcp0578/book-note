## 第7章 文件系统和文件读写
### 文本文件读写
- Qt提供了两种读写纯文本的基本方法
	- 一种是用`QFile`类的`IODevice`读写功能直接进行读写
	- 另一种是利用`QFile`和`QTextStream`结合起来，用流(Stream)的方法进行文件读写。
### 二进制文件读写
- Qt使用`QFile`和`QDataStream`进行二进制数据文件的读写。
	- `QFile`负责文件的IO设备接口，即与文件的物理交互
	- `QDataStream`以数据流的方式读取文件内容或写入文件内容。
### 文件目录操作
- `QCoreApplication`用于提取应用程序路径、程序名等文件信息。
- `QFile`除了打开文件操作外，`QFile`还有复制文件、删除文件等功能。
- `QFileInfo`用于提取文件信息，包括路径、文件名、后缀等。
- `QDir`用于提取目录或文件信息，获取一个目录下的文件或目录列表，创建或删除目录和文件，文件重命名等操作。
- `QTemporaryDir`和`QTemporaryFile`用于创建临时目录和临时文件。
- `QFileSystemWatcher`文件和目录监听类，监听目录下文件的添加、删除等变化，监听文件修改变化。
