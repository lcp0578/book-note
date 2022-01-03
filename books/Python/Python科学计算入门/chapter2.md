## 第2章 Python编程基础
- 关键字
		import keyword

		print(keyword.kwlist)
        
        ['False', 'None', 'True', 'and', 'as', 'assert', 'async', 'await', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']
-  内部使用名称
		dir(__builtinr__)
        
        ['ArithmeticError',
         'AssertionError',
         'AttributeError',
         'BaseException',
         'BlockingIOError',
         'BrokenPipeError',
         'BufferError',
         'BytesWarning',
         'ChildProcessError',
         'ConnectionAbortedError',
         'ConnectionError',
         'ConnectionRefusedError',
         'ConnectionResetError',
         'DeprecationWarning',
         'EOFError',
         'Ellipsis',
         'EnvironmentError',
         'Exception',
         'False',
         'FileExistsError',
         'FileNotFoundError',
         'FloatingPointError',
         'FutureWarning',
         'GeneratorExit',
         'IOError',
         'ImportError',
         'ImportWarning',
         'IndentationError',
         'IndexError',
         'InterruptedError',
         'IsADirectoryError',
         'KeyError',
         'KeyboardInterrupt',
         'LookupError',
         'MemoryError',
         'ModuleNotFoundError',
         'NameError',
         'None',
         'NotADirectoryError',
         'NotImplemented',
         'NotImplementedError',
         'OSError',
         'OverflowError',
         'PendingDeprecationWarning',
         'PermissionError',
         'ProcessLookupError',
         'RecursionError',
         'ReferenceError',
         'ResourceWarning',
         'RuntimeError',
         'RuntimeWarning',
         'StopAsyncIteration',
         'StopIteration',
         'SyntaxError',
         'SyntaxWarning',
         'SystemError',
         'SystemExit',
         'TabError',
         'TimeoutError',
         'True',
         'TypeError',
         'UnboundLocalError',
         'UnicodeDecodeError',
         'UnicodeEncodeError',
         'UnicodeError',
         'UnicodeTranslateError',
         'UnicodeWarning',
         'UserWarning',
         'ValueError',
         'Warning',
         'ZeroDivisionError',
         '__IPYTHON__',
         '__build_class__',
         '__debug__',
         '__doc__',
         '__import__',
         '__loader__',
         '__name__',
         '__package__',
         '__spec__',
         'abs',
         'all',
         'any',
         'ascii',
         'bin',
         'bool',
         'breakpoint',
         'bytearray',
         'bytes',
         'callable',
         'chr',
         'classmethod',
         'compile',
         'complex',
         'copyright',
         'credits',
         'delattr',
         'dict',
         'dir',
         'display',
         'divmod',
         'enumerate',
         'eval',
         'exec',
         'filter',
         'float',
         'format',
         'frozenset',
         'get_ipython',
         'getattr',
         'globals',
         'hasattr',
         'hash',
         'help',
         'hex',
         'id',
         'input',
         'int',
         'isinstance',
         'issubclass',
         'iter',
         'len',
         'license',
         'list',
         'locals',
         'map',
         'max',
         'memoryview',
         'min',
         'next',
         'object',
         'oct',
         'open',
         'ord',
         'pow',
         'print',
         'property',
         'range',
         'repr',
         'reversed',
         'round',
         'set',
         'setattr',
         'slice',
         'sorted',
         'staticmethod',
         'str',
         'sum',
         'super',
         'tuple',
         'type',
         'vars',
         'zip']
- as关键字使用示例
		import random as r
- from语句使用示例
		from math import pi, cos
- 数值的字面常量可以使用`_`对位数进行分段，使位数较大的数值显示得更易于阅读。
- Python中复数类型提供了内置的支持(complex)
	- 在Python中，我们通常将j和J作为虚数单位，在整数或浮点数的字面常量后面输入虚数单位。
	- 附属中的实部可以使用real属性进行访问，虚部可以使用imag属性进行访问。
- 算术运算符
	- `**` 幂运算（求幂）
	- `//` 取整
- 使用3个`"`或`'`字符将元素围起来，就可以将多行字符串定义为一个字符串对象。
- `format`方法或者`f`字符串，值就会被插入到字符串中。
- 元组是类似于列表的序列，元组是不可变对象。
- 使用enumerate函数，就可以获得整数型索引及列表中的元素。
        words = ['a', 'b', 'c']
        for i, x in enumerate(words):
            print(i, x)

        0 a
        1 b
        2 c
- 装饰器
	- 在代码运行期间动态增加功能的方式，称之为“装饰器”（Decorator）
- lambda表达式
		c=lambda x,y,z:x*y*z
        c(2,3,4)

        24