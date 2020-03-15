## 第2章 Python整洁之道
- 用断言加一层保险
	- 从根本上来说，Python的断言语句是一种调试工具，用来测试某个断言条件。
	- 如果断言条件为真，则程序将继续正常执行；但如果条件为假，则会引发`AssertionError`异常并显示相关错误消息。
	- 断言应该只用于帮助开发人员识别bug，它不是用于处理运行时错误的机制。
	- 常见陷阱
		- 注意事项1：不要使用断言验证数据
			- 若在命令行中使用`-O`和`-OO`标识，或修改CPython中的`PYTHONOPTIMIZE`环境变量，都会全局禁用断言。
		- 注意事项2：永不失败的断言
- 巧妙的放置逗号
	- 合理的格式化及逗号放置能让列表、字典和集合常量更容易维护。
	- 字符串字面值拼接
		- 以空白符分割多个相连的字符串或byte字面值，即使他们各自使用不同的引号，也会执行拼接操作。
	- 巧妙放置逗号，可以避免**字符串字面值拼接**特性带来难以发现的bug。
- 上下文管理器和with语句
	- with语句通过在所谓的上下文管理器中封装`try...finally`语句的标准用法来简化异常处理。
	- with语句一般用来管理系统资源的安全获取和释放、资源授权由with语句获取。并在执行离开with上下文时自动释放。
	- 有效地使用with有助于避免资源泄露问题，让代码更加易于阅读。
	- 只要实现所谓的**上下文管理器**(context manager)，就可以在自定义的类和函数中获得相同的功能。
	- 标准库中的`contextlib`模块在上下文管理器基本协议的基础上提供了更多抽象。
- [PEP 8 -- Style Guide for Python Code](https://legacy.python.org/dev/peps/pep-0008/)
- dunder
	- 在Python社区通常称双下划线为dunder(double underscore)。
- 下划线、双下划线及其他
	- `_var`前置单下划线：以单下划线开头的变量或方法只在内部使用。
	- `var_`后置单下划线：用一个后置单下划线来避免与Python关键字的命令冲突是一个约定。
	- `__var`前置双下划线：双下划线前缀会让Python解释器重写属性名称，已避免子类中的命名冲突。这也称为**名称改写**(name mangling)，即解释器会更改变量的名称，以便在稍后扩展这个类时避免命名冲突。`__baz`会被改写成`_ClassName__baz`
	- `__var__`前后双下划线：通常被称为魔术方法，`__init__`,`__call__`
	- `_` 单下划线：按照约定，单下划线有时用作名称，来表示变量是临时的或无关紧要的。
- 字符串格式化
	- “旧式”字符串格式化
	
    		>>> name = 'lcp0578'
    		>>> hello, %s' % name
			'hello, lcp0578'
            >>> errorno = 2048
            >>> '%x' % errorno
            '800'
            >>>
	- "新式“字符串格式化(Python >= 2.7)
	
- Python之禅

        >>> import this
        The Zen of Python, by Tim Peters

        Beautiful is better than ugly.
        Explicit is better than implicit.
        Simple is better than complex.
        Complex is better than complicated.
        Flat is better than nested.
        Sparse is better than dense.
        Readability counts.
        Special cases aren't special enough to break the rules.
        Although practicality beats purity.
        Errors should never pass silently.
        Unless explicitly silenced.
        In the face of ambiguity, refuse the temptation to guess.
        There should be one-- and preferably only one --obvious way to do it.
        Although that way may not be obvious at first unless you're Dutch.
        Now is better than never.
        Although never is often better than *right* now.
        If the implementation is hard to explain, it's a bad idea.
        If the implementation is easy to explain, it may be a good idea.
        Namespaces are one honking great idea -- let's do more of those!