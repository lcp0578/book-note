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
        - 矩阵相等，两个矩阵A、B相等的含义是它们对应的元素相等，记为A = B  
        - 矩阵的和、差、常数倍
        当 <a href="https://www.codecogs.com/eqnedit.php?latex=A&space;=&space;\begin{pmatrix}&space;2\&space;7\&space;\\&space;1\&space;8\&space;\end{pmatrix},B=\begin{pmatrix}&space;2\&space;8\&space;\\&space;1\&space;3\&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A&space;=&space;\begin{pmatrix}&space;2\&space;7\&space;\\&space;1\&space;8\&space;\end{pmatrix},B=\begin{pmatrix}&space;2\&space;8\&space;\\&space;1\&space;3\&space;\end{pmatrix}" title="A = \begin{pmatrix} 2\ 7\ \\ 1\ 8\ \end{pmatrix},B=\begin{pmatrix} 2\ 8\ \\ 1\ 3\ \end{pmatrix}" /></a>时:  
        <a href="https://www.codecogs.com/eqnedit.php?latex=A&space;&plus;&space;B&space;=&space;\begin{pmatrix}&space;2&plus;2&space;&&space;7&plus;8&space;\\&space;1&plus;1&space;&&space;8&plus;3&space;\end{pmatrix}=\begin{pmatrix}&space;4&space;&&space;15&space;\\&space;2&space;&&space;11&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A&space;&plus;&space;B&space;=&space;\begin{pmatrix}&space;2&plus;2&space;&&space;7&plus;8&space;\\&space;1&plus;1&space;&&space;8&plus;3&space;\end{pmatrix}=\begin{pmatrix}&space;4&space;&&space;15&space;\\&space;2&space;&&space;11&space;\end{pmatrix}" title="A + B = \begin{pmatrix} 2+2 & 7+8 \\ 1+1 & 8+3 \end{pmatrix}=\begin{pmatrix} 4 & 15 \\ 2 & 11 \end{pmatrix}" /></a>  
        <a href="https://www.codecogs.com/eqnedit.php?latex=A&space;-&space;B&space;=&space;\begin{pmatrix}&space;2-2&space;&&space;7-8&space;\\&space;1-1&space;&&space;8-3&space;\end{pmatrix}=\begin{pmatrix}&space;0&space;&&space;-1&space;\\&space;0&space;&&space;5&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A&space;-&space;B&space;=&space;\begin{pmatrix}&space;2-2&space;&&space;7-8&space;\\&space;1-1&space;&&space;8-3&space;\end{pmatrix}=\begin{pmatrix}&space;0&space;&&space;-1&space;\\&space;0&space;&&space;5&space;\end{pmatrix}" title="A - B = \begin{pmatrix} 2-2 & 7-8 \\ 1-1 & 8-3 \end{pmatrix}=\begin{pmatrix} 0 & -1 \\ 0 & 5 \end{pmatrix}" /></a>  
        <a href="https://www.codecogs.com/eqnedit.php?latex=3A&space;=&space;\begin{pmatrix}&space;3*2&space;&&space;3*7&space;\\&space;3*1&space;&&space;3*8&space;\end{pmatrix}=\begin{pmatrix}&space;6&space;&&space;21&space;\\&space;3&space;&&space;24&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?3A&space;=&space;\begin{pmatrix}&space;3*2&space;&&space;3*7&space;\\&space;3*1&space;&&space;3*8&space;\end{pmatrix}=\begin{pmatrix}&space;6&space;&&space;21&space;\\&space;3&space;&&space;24&space;\end{pmatrix}" title="3A = \begin{pmatrix} 3*2 & 3*7 \\ 3*1 & 3*8 \end{pmatrix}=\begin{pmatrix} 6 & 21 \\ 3 & 24 \end{pmatrix}" /></a>  
        - 矩阵的乘积，对于两个矩阵A、B，将Ade第i行看做行向量，B的第j列看做列向量，将它们的内积作为第行第j列元素，由此而产生的矩阵就是矩阵A、B的乘积AB。  
        <a href="https://www.codecogs.com/eqnedit.php?latex=AB&space;=&space;\begin{pmatrix}&space;2*2&plus;7*1&space;&&space;2*8&plus;7*3&space;\\&space;1*2&plus;8*1&space;&&space;1*8&plus;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;11&space;&&space;37\&space;\\&space;10&space;&&space;32&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?AB&space;=&space;\begin{pmatrix}&space;2*2&plus;7*1&space;&&space;2*8&plus;7*3&space;\\&space;1*2&plus;8*1&space;&&space;1*8&plus;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;11&space;&&space;37\&space;\\&space;10&space;&&space;32&space;\end{pmatrix}" title="AB = \begin{pmatrix} 2*2+7*1 & 2*8+7*3 \\ 1*2+8*1 & 1*8+8*3 \end{pmatrix}=\begin{pmatrix} 11 & 37\ \\ 10 & 32 \end{pmatrix}" /></a>  
        <a href="https://www.codecogs.com/eqnedit.php?latex=AB&space;=&space;\begin{pmatrix}&space;2*2&plus;7*1&space;&&space;2*8&plus;7*3&space;\\&space;1*2&plus;8*1&space;&&space;1*8&plus;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;11&space;&&space;37\&space;\\&space;10&space;&&space;32&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?AB&space;=&space;\begin{pmatrix}&space;2*2&plus;7*1&space;&&space;2*8&plus;7*3&space;\\&space;1*2&plus;8*1&space;&&space;1*8&plus;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;11&space;&&space;37\&space;\\&space;10&space;&&space;32&space;\end{pmatrix}" title="AB = \begin{pmatrix} 2*2+7*1 & 2*8+7*3 \\ 1*2+8*1 & 1*8+8*3 \end{pmatrix}=\begin{pmatrix} 11 & 37\ \\ 10 & 32 \end{pmatrix}" /></a>  
        	- 矩阵的乘法不满足交换律。也就是说，除例外情况，一下关系式成立  
        	<a href="https://www.codecogs.com/eqnedit.php?latex=AB\neq&space;BA" target="_blank"><img src="https://latex.codecogs.com/gif.latex?AB\neq&space;BA" title="AB\neq BA" /></a>  
            - 而单位矩阵E与任意矩阵A的乘积都满足以下交换律  
            AE=EA=A
        - Hadamard乘积，对于相同形状的矩阵A、B，将相同位置的元素相乘，由此产生的矩阵为矩阵A、B的**Hadamard乘积**，用<a href="https://www.codecogs.com/eqnedit.php?latex=A\odot&space;B" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A\odot&space;B" title="A\odot B" /></a>表示  
        <a href="https://www.codecogs.com/eqnedit.php?latex=A\odot&space;B=\begin{pmatrix}&space;2*2&space;&&space;7*8&space;\\&space;1*1&space;&&space;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;4&space;&&space;56\\&space;1&space;&&space;24&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A\odot&space;B=\begin{pmatrix}&space;2*2&space;&&space;7*8&space;\\&space;1*1&space;&&space;8*3&space;\end{pmatrix}=\begin{pmatrix}&space;4&space;&&space;56\\&space;1&space;&&space;24&space;\end{pmatrix}" title="A\odot B=\begin{pmatrix} 2*2 & 7*8 \\ 1*1 & 8*3 \end{pmatrix}=\begin{pmatrix} 4 & 56\\ 1 & 24 \end{pmatrix}" /></a>
        - 转置矩阵(transposed matrix),将矩阵A的第行第j列的元素与第j行第i列的元素交换。用<a href="https://www.codecogs.com/eqnedit.php?latex=^{t}A,A^{t}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?^{t}A,A^{t}" title="^{t}A,A^{t}" /></a>等表示。  
        <a href="https://www.codecogs.com/eqnedit.php?latex=A=\begin{pmatrix}&space;2&space;&&space;7\\&space;1&space;&&space;8&space;\end{pmatrix},&space;^{t}A=\begin{pmatrix}&space;2&space;&&space;1&space;\\&space;7&space;&&space;8&space;\end{pmatrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?A=\begin{pmatrix}&space;2&space;&&space;7\\&space;1&space;&&space;8&space;\end{pmatrix},&space;^{t}A=\begin{pmatrix}&space;2&space;&&space;1&space;\\&space;7&space;&&space;8&space;\end{pmatrix}" title="A=\begin{pmatrix} 2 & 7\\ 1 & 8 \end{pmatrix}, ^{t}A=\begin{pmatrix} 2 & 1 \\ 7 & 8 \end{pmatrix}" /></a>  

- 导数
	- 函数y=f(x)的导函数f'(x)的定义如下所示：  
	<a href="https://www.codecogs.com/eqnedit.php?latex=f'(x)=\lim_{\Delta&space;x&space;\to&space;0}\frac{f(x&plus;\Delta&space;x)-f(x)}{\Delta&space;x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f'(x)=\lim_{\Delta&space;x&space;\to&space;0}\frac{f(x&plus;\Delta&space;x)-f(x)}{\Delta&space;x}" title="f'(x)=\lim_{\Delta x \to 0}\frac{f(x+\Delta x)-f(x)}{\Delta x}" /></a>  
    - 导函数的含义：作出函数f(x)的图像，f'(x)表示图像切线的斜率。因此，具有光滑图像的函数是可导的。
    - 导数公式  
    <a href="https://www.codecogs.com/eqnedit.php?latex=(e)'=0,(x)'=1,(x^{2})=2x,(e^{x})'=e^{x},(e^{-x})=-e^{x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(e)'=0,(x)'=1,(x^{2})=2x,(e^{x})'=e^{x},(e^{-x})=-e^{x}" title="(e)'=0,(x)'=1,(x^{2})=2x,(e^{x})'=e^{x},(e^{-x})=-e^{x}" /></a>  
    - 导数的线性性：和的导数为导数的 和，常数倍的导数为导数的常数倍。  
    <a href="https://www.codecogs.com/eqnedit.php?latex=\left&space;\{&space;{f(x)&plus;g(x)}&space;\right&space;\}'=f'(x)&plus;g'(x),\left&space;\{&space;cf(x)&space;\right&space;\}'=cf'(x)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left&space;\{&space;{f(x)&plus;g(x)}&space;\right&space;\}'=f'(x)&plus;g'(x),\left&space;\{&space;cf(x)&space;\right&space;\}'=cf'(x)" title="\left \{ {f(x)+g(x)} \right \}'=f'(x)+g'(x),\left \{ cf(x) \right \}'=cf'(x)" /></a>  
    - 导数的分数表示方法  
    <a href="https://www.codecogs.com/eqnedit.php?latex=f'(x)=\frac{dy}{dx}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f'(x)=\frac{dy}{dx}" title="f'(x)=\frac{dy}{dx}" /></a>  
    - 分数函数的导数  
    <a href="https://www.codecogs.com/eqnedit.php?latex=\left&space;\{&space;\frac{1}{f(x)}&space;\right&space;\}'=-\frac{f'(x)}{\left&space;\{&space;f(x)&space;\right&space;\}^{2}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\left&space;\{&space;\frac{1}{f(x)}&space;\right&space;\}'=-\frac{f'(x)}{\left&space;\{&space;f(x)&space;\right&space;\}^{2}}" title="\left \{ \frac{1}{f(x)} \right \}'=-\frac{f'(x)}{\left \{ f(x) \right \}^{2}}" /></a>  
    - Sigmoid函数的导数  
    <a href="https://www.codecogs.com/eqnedit.php?latex=\sigma&space;(x)=&space;\frac{1}{1&plus;e^{-x}},&space;\sigma&space;'(x)=-\frac{(1&plus;e^{-x})'}{(1&plus;e^{-x})^{2}}=\frac{e^{-x}}{(1&plus;e^{-x})^{2}}=\frac{1&plus;e^{-x}-1}{(1&plus;e^{-x})^{2}}=\frac{1}{1&plus;e^{-x}}&space;-&space;\frac{1}{(1&plus;e^{-x})^{2}}=\sigma&space;(x)-\sigma(x)^2=\sigma&space;(x)(1-\sigma&space;(x))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sigma&space;(x)=&space;\frac{1}{1&plus;e^{-x}},&space;\sigma&space;'(x)=-\frac{(1&plus;e^{-x})'}{(1&plus;e^{-x})^{2}}=\frac{e^{-x}}{(1&plus;e^{-x})^{2}}=\frac{1&plus;e^{-x}-1}{(1&plus;e^{-x})^{2}}=\frac{1}{1&plus;e^{-x}}&space;-&space;\frac{1}{(1&plus;e^{-x})^{2}}=\sigma&space;(x)-\sigma(x)^2=\sigma&space;(x)(1-\sigma&space;(x))" title="\sigma (x)= \frac{1}{1+e^{-x}}, \sigma '(x)=-\frac{(1+e^{-x})'}{(1+e^{-x})^{2}}=\frac{e^{-x}}{(1+e^{-x})^{2}}=\frac{1+e^{-x}-1}{(1+e^{-x})^{2}}=\frac{1}{1+e^{-x}} - \frac{1}{(1+e^{-x})^{2}}=\sigma (x)-\sigma(x)^2=\sigma (x)(1-\sigma (x))" /></a>  
    - 最小值条件，f'(a)=0是函数f(x)在x=a处取得最小值的必要条件。
- 偏导数基础
	- 多变量函数：有两个以上自变量的函数称为多变量函数。
	- 求导的方法也同样适用于多变量函数的情况。但是。由于有多个变量，所以必须指明对哪一个变量进行求导。在这个意义上，关于某个特定变量的导数就称为**偏导数**(partial derivative)。
	- 假设两个变量x、y的函数z=f(x,y)。
		- 关于x的偏导数  
		<a href="https://www.codecogs.com/eqnedit.php?latex=\tfrac{\partial&space;z}{\partial&space;x}=\tfrac{\partial&space;f(x,&space;y)}{\partial&space;x}=\lim_{\Delta&space;x&space;\to&space;0}\frac{f(x&plus;\Delta&space;x,&space;y)&space;-&space;f(x,&space;y)}{\Delta&space;x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\tfrac{\partial&space;z}{\partial&space;x}=\tfrac{\partial&space;f(x,&space;y)}{\partial&space;x}=\lim_{\Delta&space;x&space;\to&space;0}\frac{f(x&plus;\Delta&space;x,&space;y)&space;-&space;f(x,&space;y)}{\Delta&space;x}" title="\tfrac{\partial z}{\partial x}=\tfrac{\partial f(x, y)}{\partial x}=\lim_{\Delta x \to 0}\frac{f(x+\Delta x, y) - f(x, y)}{\Delta x}" /></a>  
		- 关于y的偏导数  
		<a href="https://www.codecogs.com/eqnedit.php?latex=\tfrac{\partial&space;z}{\partial&space;y}=\tfrac{\partial&space;f(x,&space;y)}{\partial&space;y}=\lim_{\Delta&space;y&space;\to&space;0}\frac{f(x,&space;y&plus;\Delta&space;y)&space;-&space;f(x,&space;y)}{\Delta&space;y}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\tfrac{\partial&space;z}{\partial&space;y}=\tfrac{\partial&space;f(x,&space;y)}{\partial&space;y}=\lim_{\Delta&space;y&space;\to&space;0}\frac{f(x,&space;y&plus;\Delta&space;y)&space;-&space;f(x,&space;y)}{\Delta&space;y}" title="\tfrac{\partial z}{\partial y}=\tfrac{\partial f(x, y)}{\partial y}=\lim_{\Delta y \to 0}\frac{f(x, y+\Delta y) - f(x, y)}{\Delta y}" /></a>  
        - 多变量函数的最小值条件：函数z=f(x,y)取得最小值的必要条件是
        <a href="https://www.codecogs.com/eqnedit.php?latex=\tfrac{\partial&space;f}{\partial&space;x}=0,\tfrac{\partial&space;f}{\partial&space;y}=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\tfrac{\partial&space;f}{\partial&space;x}=0,\tfrac{\partial&space;f}{\partial&space;y}=0" title="\tfrac{\partial f}{\partial x}=0,\tfrac{\partial f}{\partial y}=0" /></a>  
        - 拉格朗日乘数法。求函数<a href="https://www.codecogs.com/eqnedit.php?latex=z=f(x,&space;y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?z=f(x,&space;y)" title="z=f(x, y)" /></a>在满足下的条件极值，可以转化为函数<a href="https://www.codecogs.com/eqnedit.php?latex=F(x,&space;y,&space;\lambda&space;)=f(x,&space;y)&plus;\lambda&space;\varphi&space;(x,&space;y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?F(x,&space;y,&space;\lambda&space;)=f(x,&space;y)&plus;\lambda&space;\varphi&space;(x,&space;y)" title="F(x, y, \lambda )=f(x, y)+\lambda \varphi (x, y)" /></a>的无条件极值问题。
        - [拉格朗日参考资料](https://www.cnblogs.com/maybe2030/p/4946256.html)
- 链式法则
	- 神经网络和符合函数
		- 已知函数 y=f(u),当u表示为u=g(x)时，y作为x的函数可以表示为形如y=f(g(x))的嵌套结构（u和x表示多变量）。
		- 嵌套结构的函数f(g(x))称为f(u)和g(x)的**复合函数**
	- 单变量函数的链式法则
		- 已知函数 y=f(u),当u表示为u=g(x)时，复合函数f(g(x))的导函数可以如下简单地求出来。  
		<a href="https://www.codecogs.com/eqnedit.php?latex=\frac{\mathrm{d}&space;y}{\mathrm{d}&space;x}=\frac{\mathrm{d}&space;y}{\mathrm{d}&space;u}\frac{\mathrm{d}&space;u}{\mathrm{d}&space;x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\frac{\mathrm{d}&space;y}{\mathrm{d}&space;x}=\frac{\mathrm{d}&space;y}{\mathrm{d}&space;u}\frac{\mathrm{d}&space;u}{\mathrm{d}&space;x}" title="\frac{\mathrm{d} y}{\mathrm{d} x}=\frac{\mathrm{d} y}{\mathrm{d} u}\frac{\mathrm{d} u}{\mathrm{d} x}" /></a>  
        - 这个公式称为单变量函数的**复合函数求导公式**，也称为**链式法则**。
	- 多变量函数的链式法则
		- 变量z为u、v的函数，如果u、v分别为x、y的函数，则z为x、y的函数，此时下式（多变量函数的链式法则）成立。  
		<a href="https://www.codecogs.com/eqnedit.php?latex=\frac{\partial&space;z}{\partial&space;x}=\frac{\partial&space;z}{\partial&space;u}\frac{\partial&space;u}{\partial&space;x}&space;&plus;&space;\frac{\partial&space;z}{\partial&space;v}\frac{\partial&space;v}{\partial&space;x}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\frac{\partial&space;z}{\partial&space;x}=\frac{\partial&space;z}{\partial&space;u}\frac{\partial&space;u}{\partial&space;x}&space;&plus;&space;\frac{\partial&space;z}{\partial&space;v}\frac{\partial&space;v}{\partial&space;x}" title="\frac{\partial z}{\partial x}=\frac{\partial z}{\partial u}\frac{\partial u}{\partial x} + \frac{\partial z}{\partial v}\frac{\partial v}{\partial x}" /></a>  
	- 单变量函数的近似公式(△x为微小的数)  
	<a href="https://www.codecogs.com/eqnedit.php?latex=f(x&space;&plus;&space;\Delta&space;x))\approx&space;f(x)&plus;f'(x)\Delta&space;x" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x&space;&plus;&space;\Delta&space;x))\approx&space;f(x)&plus;f'(x)\Delta&space;x" title="f(x + \Delta x))\approx f(x)+f'(x)\Delta x" /></a>
    - 多变量函数的近似公式  
    <a href="https://www.codecogs.com/eqnedit.php?latex=f(x&space;&plus;&space;\Delta&space;x,&space;y&space;&plus;&space;\Delta&space;y))\approx&space;f(x,y)&plus;\frac{\partial&space;f(x,&space;y)}{\partial&space;x}\Delta&space;x&plus;\frac{\partial&space;f(x,&space;y)}{\partial&space;y}\Delta&space;y" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(x&space;&plus;&space;\Delta&space;x,&space;y&space;&plus;&space;\Delta&space;y))\approx&space;f(x,y)&plus;\frac{\partial&space;f(x,&space;y)}{\partial&space;x}\Delta&space;x&plus;\frac{\partial&space;f(x,&space;y)}{\partial&space;y}\Delta&space;y" title="f(x + \Delta x, y + \Delta y))\approx f(x,y)+\frac{\partial f(x, y)}{\partial x}\Delta x+\frac{\partial f(x, y)}{\partial y}\Delta y" /></a>  
- 回归分析
	- 由多个变量组成的数据中，着眼于其中一个特定的变量，用其余的变量来解释这个特定的变量，这样的方法称为**回归分析**。