## 第2章 线程管控
- `std::bind`
- `std::ref`
- 在`std::thread`对象析构前，我们必须明确：是等待线程完成还是要与之分离。不然，便会导致关联的线程终结。
- 只要`std::thrad`对象正管控着一个线程，就不能简单地向它赋新值，否则该线程会因此被遗弃。
- `std::thread`支持移动操作的意义是，函数可以便捷地向外部转移线程的所属权。
- `std::thread::hardware_concurrency()` 表示程序在各次运行中真正并发的线程数量。
- 线程ID所属型别是`std::thread::id`，它有两种获取方法
	- 在线程关联的`std::thread`对象上调用成员函数`get_id()`，即可得到改线程的ID。如果`std::thread`对象没有关联任何执行线程，调用`get_id()`则会返回一个`std::thread::id`对象，它按默认构造方式生成，表示“线程不存在”。
	- 当前的线程ID可以通过调用`std::this_thread::get_id()`获得。