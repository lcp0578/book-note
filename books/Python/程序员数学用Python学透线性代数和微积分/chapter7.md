## 第7章 求解线性方程组
- Python的NumPy库有一个线性代数模块和一个用于解决这类方程的函数。

		>>> import numpy as np
		>>> matrix = np.array(((1, -1), (1, 2)))
		>>> output = np.array((0, 8))
		
		>>> np.linalg.solve(matrix, output)
		array([2.66666667, 2.66666667])
- 如果我们把一个没有解的线性方程组传给NumPy，就会得到一个异常。
- 奇异矩阵
- 在n维中，需要至少有n个线性方程的方程组才能找到唯一解、如果线性方程正好是n个，并且方程组有唯一解，那么这些方程称为**独立方程**