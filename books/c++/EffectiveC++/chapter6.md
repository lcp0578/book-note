## 6 继承与面向对象设计(Inheritance and Object-Oriented Design.)
### 条款32：确定你的public继承塑模出is-a关系(Make sure public inheritance models "is-a".)
- “public继承”意味着is-a。适用于base classes身上的每一件事情一定也适用于derived classes身上，因为每一个derived class对象也都是一个base class对象。

### 条款33：避免遮掩继承而来的名称(Aviod hiding inherited names.)
- derived classes内的名称会遮掩base classes内的名称。在public继承下从来没有人希望如此。
- 为了让被遮掩的名称再见天日，可使用using声明式或转交函数（forwarding functions）。

### 条款34：区分接口继承和实现继承(Differentiate between inheritance of interface and inheritance of implementation.)