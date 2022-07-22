## 4 设计与声明(Designs and Declarations.)
### 条款18：让接口容易被正确使用，不易被误用(Make interfaces easy to use correctly and hard to use incorrectly.)
- 好的接口很容易被正确使用，不容易被误用。你应该在你的所有接口中努力达成这些性质。
- “促进正确使用”的办法包括接口的一致性，以及与内置类型的行为兼容。
- “阻止误用”的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任。
- `tr1::shared_ptr`支持定制型删除器(custom deleter)。这可防范DLL问题，可被用来自动解除互斥锁（mutexes）等等。

### 条款19：设计class犹如设计type (Treat class design as type design.)
- Class的设计就是type的设计。在定义一个新type之前，请确定你已经考虑过本条款涵盖的所有讨论主题。