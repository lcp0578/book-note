## 第1章 Python入门
- NumPy是用于数值计算的库，提供了很多高级的数学算法和便利的数组（矩阵）操作方法。
- Matplotlib是用来画图的库，将结果可视化。
- `**` 表示乘方
- `/` 除法结果不同
    - 7/5=1(整数，python 2.x)
    - 7/5=1.4(浮点数，python 3.x)
- `type()` 查看数据类型

		>>> type(20)
        <class 'int'>
        >>> type('20')
        <class 'str'>

- 列表（数组）

		>>> a = [1,2,3,4,5]
        >>> print(a)
        [1, 2, 3, 4, 5]
        >>> a[0:2]
        [1, 2]
        >>> a[1:]
        [2, 3, 4, 5]
        >>> a[:3]
        [1, 2, 3]
        >>> a[:-1]
        [1, 2, 3, 4]
        >>> a[:-2]
        [1, 2, 3]

- 字典

        >>> me = {'height': 100}
        >>> me
        {'height': 100}
        >>> me['height']
        100
        >>> me['weight']=65
        >>> me
        {'height': 100, 'weight': 65}
        >>>
        >>> me["age"]=22
        >>> me
        {'height': 100, 'weight': 65, 'age': 22}

- 布尔 bool， True False
- if语句（4个空格）

		hungry = True
        if hungry:
            print("I'm hungry")
        else:
            print("I'm not hungry")
- for语句

		for i in [1, 2, 3]:
            print(i)
- 函数 

		def hello():
            print("hello world")
        def helloObj(object)
            print("hello" + object)
- 类

		class Man:
            def __init__(self, name):
                self.name = name
                print('init')

            def hello(self):
                print('hello ' + self.name + '!')

            def goodby(self):
                print('Good-by ' + self.name)

        m = Man('lcp0578')
        m.hello()
        m.goodby()