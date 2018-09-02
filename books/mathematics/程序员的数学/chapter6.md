## 第6章 递归--自己定义自己
 - GNU: GNU is Not Unix
 - 汉诺塔问题  
 	先从小问题着手  
	递推公式：H(n) = H(n-1) + 1 + H(n-1)  (n=0,1,2,3 ...时)
 - 再谈阶乘  
 	定义了 0！= 1
 - 递归(recursive)与归纳(inductive)
 	- 递归： 从一般性前提退出个别性结论
 	- 归纳： 从个别性前提退出一般性结论
 - 斐波那契数列
 - 帕斯卡三角形，又称杨辉三角  
 	C<sub>n</sub><sup>k</sup> = C<sub>n-1</sub><sup>k-1</sup> + C<sub>n-1</sub><sup>k</sup>(0<k<n时)  
    C<sub>n</sub><sup>k</sup> = 1 (n=0或n=k时)
 - 递归图形的例子--谢尔平斯基三角形