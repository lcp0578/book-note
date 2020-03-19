## 第2章 变量和简单的数据类型 
- 使用方法修改字符串的大小写

        >>> name = 'lee peng'
        >>> print(name.title())
        Lee Peng
        >>>
        >>> name = 'Lee Peng'
        >>> print(name.upper())
        LEE PENG
        >>> print(name.lower())
        lee peng

- 删除空白

        >>> lang = ' Python   '
        >>> lang.rstrip()
        ' Python'
        >>> lang.lstrip()
        'Python   '
        >>> lang.strip()
        'Python'

- Python使用两个乘号（`**`）表示乘方运算。
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
        >>>