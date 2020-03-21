## 第3章 列表简介
- 负数索引

        >>> letters = ['A' , 'B', 'C', 'D']
        >>> letters[-1]
        'D'
        >>> letters[-3]
        'B'
        >>> letters[-5]
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        IndexError: list index out of range

- 修改、添加和删除元素

        >>> letters = ['A' , 'B', 'C', 'D']
        >>> letters.append('F')
        >>> letters
        ['A', 'B', 'C', 'D', 'F']
        >>> letters.insert(4, 'E')
        >>> letters
        ['A', 'B', 'C', 'D', 'E', 'F']
        >>>
        >>> del letters[2]
        >>>
        >>> letters
        ['A', 'B', 'D', 'E', 'F']
        >>> letters.pop()
        'F'
        >>> letters
        ['A', 'B', 'D', 'E']
        >>> letters.pop(2)
        'D'
        >>> letters
        ['A', 'B', 'E']
        >>>
        >>> letters.remove('B')
        >>>
        >>> letters
        ['A', 'E']

- 组织列表

        >>> cars = ['bmw', 'audi', 'toyota', 'subaru']
        >>> cars.sort()
        >>>
        >>> cars
        ['audi', 'bmw', 'subaru', 'toyota']
        >>>
        >>> cars.sort(reverse=True)
        >>> cars
        ['toyota', 'subaru', 'bmw', 'audi']
        >>>
        >>>
        >>>
        >>> sorted(cars)
        ['audi', 'bmw', 'subaru', 'toyota']
        >>>
        >>>
        >>> cars
        ['toyota', 'subaru', 'bmw', 'audi']
        >>>
        >>>
        >>> cars.reverse()
        >>>
        >>> cars
        ['audi', 'bmw', 'subaru', 'toyota']
        >>>
        >>> cars.reverse()
        >>>
        >>> cars
        ['toyota', 'subaru', 'bmw', 'audi']
        >>>
        >>> len(cars)
        4
        >>>
        >>>