## 第8章 IO库
#### IO类
- `iostream` 定义了用于读写流的基本类型
	- `istream`,`wistream` 从流读取数据
	- `ostream`,`wostream` 向流写入数据
	- `iostream`,`wiostream` 读写流
- `fstream` 定义了读写命名文件的类型
	- `ifstream`,`wifstream` 从文件读取数据
	- `ofstream`,`wofstream` 向文件写入数据
	- `fstream`,`wfstream` 读写文件
- `sstream` 定义了读写内存string对象的类型。
	- `istringstream`,`wistreamstream` 从string读取数据
	- `ostringstream`,`wostreamstream` 向string写入数据
	- `stringstream`,`wstringstream` 读写string
- IO对象无拷贝或赋值
- 条件状态
	- `strm::iostate` strm是一种IO类型。iostate是一种机器相关的类型，提供了表达条件状态的完整功能。
	- `strm::badbit` 用来指出流已崩溃
	- `strm::failbit` 用来指出一个IO操作失败了
	- `strm::eofbit` 用来指出流到达了文件结束
	- `strm::goodbit` 用来指出流未处于错误状态。此值保证为零
	- `s.eof()` 若流s的eofbit置位，则返回true
	- `s.fail()` 若流s的failbit或badbit置位，则返回true
	- `s.bad()` 若流s的badbit置位，则返回true
	- `s.good()` 若流s处于有效状态，则返回true
	- `s.clear()` 将流s中所有条件状态复位，将流的状态设置为有效。返回void
	- `s.clear(flags)` 根据给定的flags标志位，将流s中对应条件状态复位。
	- `s.setstate(flags)` 根据给定的flags标志位，将流s中对应条件状态置位。
	- `s.rdstate()` 返回流s的当前条件状态，返回值类型为strm::iostate
- unitbuf操纵符
	- 如果想在每次输出操作后都刷新缓冲区，我们可以使用unitbuf操纵符。
#### 文件输入输出
#### string流