### 第2章 神经网络的数学基础
- 一次函数
- 二次函数
- 单位阶跃函数
- 指数函数与Sigmoid函数
- 正态分布的概率密度函数
- 数列的通项式
- 将多个数列的递推关系式联合起来组成一组，称为联立递推关系式。
- 在神经网络的世界中，所有神经单元的输入和输出在数学上都可以认为是用联立递推式联系起来的。
- <img src="https://latex.codecogs.com/gif.latex?\sum" title="\sum" /> 符号可以简洁地表示数列的总和。
	- 对于数列{a<sub>n</sub>}, <img src="https://latex.codecogs.com/gif.latex?\tiny&space;\sum&space;{}" title="\sum" /> 符号的定义如下所示:
	<img src="https://latex.codecogs.com/gif.latex?\sum_{k=1}^{n}a_{k}=a_{1}&space;&plus;&space;a_{2}&space;&plus;&space;a_{3}&space;\cdot&space;\cdot&space;\cdot&space;&plus;&space;a_{n-1}&space;&plus;&space;a_{n}" title="\sum_{k=1}^{n}a_{k}=a_{1} + a_{2} + a_{3} \cdot \cdot \cdot + a_{n-1} + a_{n}" />
    
    - <img src="https://latex.codecogs.com/gif.latex?\sum" title="\sum" /> 符号具有线性性质
    <img src="https://latex.codecogs.com/gif.latex?\sum_{k=1}^{n}(a_{k}&space;&plus;&space;b_{k})=\sum_{k=1}^{n}a_{k}&space;&plus;&space;\sum_{k=1}^{n}b_{k},\sum_{k=1}^{n}ca_{k}=c\sum_{k=1}^{n}a_{k}" title="\sum_{k=1}^{n}(a_{k} + b_{k})=\sum_{k=1}^{n}a_{k} + \sum_{k=1}^{n}b_{k},\sum_{k=1}^{n}ca_{k}=c\sum_{k=1}^{n}a_{k}" />

- 向量是具有方向与大小的量，用箭头表示。
	- 向量的坐标表示
	<img src="https://latex.codecogs.com/gif.latex?\mathit{a}=(a_{1},&space;a_{2})" title="\mathit{a}=(a_{1}, a_{2})" />
    
    - 向量a的大小用|a|表示。
    - 向量的内积
    <img src="https://latex.codecogs.com/gif.latex?\mathit{a}\cdot&space;\mathit{b}=|a||b|cos\theta" />
    
    - 柯西-施瓦茨不等式
    <img src="https://latex.codecogs.com/gif.latex?-|a||b|\leqslant&space;a\cdot&space;b\leqslant&space;|a||b|" />
    	- 当两个向量方向相反时，内积取得最小值。
    	- 当两个向量不平行时，内积去平行时的中间值。
    	- 当两个向量方向相同时，内积取得最大值。
    - 内积的坐标表示
    <img src="https://latex.codecogs.com/gif.latex?\mathbf{a}&space;=&space;(a_{1},&space;a_{2}),\mathbf{b}&space;=&space;(b_{1},&space;b_{2});&space;\mathbf{a}\cdot&space;\mathbf{b}=a_{1},&space;b_{a}&space;&plus;&space;a_{2},&space;b_{2}" />

    - 张量(tensor)是向量概念的推广。谷歌提供的人工智能学习系统TensorFlow的命名中就是用到了这个数学术语。
- 矩阵(matrix)
	- 矩阵是数的阵列。
	<a href="https://www.codecogs.com/eqnedit.php?latex=A&space;=&space;\begin{pmatrix}&space;3\&space;1\&space;4&space;\&space;\\&space;1\&space;5\&space;9\&space;\\&space;2\&space;6\&space;5\&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A&space;=&space;\begin{pmatrix}&space;3\&space;1\&space;4&space;\&space;\\&space;1\&space;5\&space;9\&space;\\&space;2\&space;6\&space;5\&space;\end{pmatrix}" title="A = \begin{pmatrix} 3\ 1\ 4 \ \\ 1\ 5\ 9\ \\ 2\ 6\ 5\ \end{pmatrix}" /></a>
    
    	- 行数与列数相同的矩阵称为**方阵**
    	- **单位矩阵**，他说对角线上的元素a<sub>ii</sub>为1、其他元素值为0的方阵，通常用E表示。
    	<a href="https://www.codecogs.com/eqnedit.php?latex=E&space;=&space;\begin{pmatrix}&space;1\&space;0\&space;0\&space;\\&space;0\&space;1\&space;0\&space;\\&space;0\&space;0\&space;1\&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?E&space;=&space;\begin{pmatrix}&space;1\&space;0\&space;0\&space;\\&space;0\&space;1\&space;0\&space;\\&space;0\&space;0\&space;1\&space;\end{pmatrix}" title="E = \begin{pmatrix} 1\ 0\ 0\ \\ 0\ 1\ 0\ \\ 0\ 0\ 1\ \end{pmatrix}" /></a>