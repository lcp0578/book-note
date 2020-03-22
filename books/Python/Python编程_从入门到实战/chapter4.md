## 第4章 操作列表
- for语句

		for value in range(1, 5)
        	print(value)
- 切片

        >>> my_food = ['pizza', 'falafel', 'cake']
        >>>
        >>> friend_food = my_food[:]
        >>>
        >>> friend_food
        ['pizza', 'falafel', 'cake']
        >>> my_food.append('cannoli')
        >>>
        >>> my_food
        ['pizza', 'falafel', 'cake', 'cannoli']
        >>> friend_food
        ['pizza', 'falafel', 'cake']
        >>>
        >>> my_slice_food = my_food[1:3]
        >>> my_slice_food
        ['falafel', 'cake']

- 元组（不可变的列表，圆括号。列表是方括号）
- Python解释器根据水平缩进情况来解读代码，但不关系垂直间距。