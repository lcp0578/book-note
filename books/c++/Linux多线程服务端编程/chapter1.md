## 第1章 线程安全的对象生命期管理
- dangling pointer 空悬指针
	- 指向已经销毁的对象或已经回收的地址。
- wild pointer 野指针
	- 指的是未经初始化的指针。
- `shared_ptr`/`weak_ptr`