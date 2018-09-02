## 第5章 排列组合--解决计数问题的方法
 - 植树问题--不要忘记0
 - 容斥原理（The  principle of Inclusion and Exclusion）  
 	|A∪B| = |A| + |B| - |A∩B|
 - 阶乘(factorial)  
 	n! = n * (n-1) * (n-2) * .... * 3 * 2 * 1
 - 排列(permutation)
   我们将从n张牌中取出k张按一定顺序排列的方法称作**排列**  
	P<sup>k</sup><sub>n</sub> = n * (n-1) * (n-2) * ... * (n-k+1)  
	  = n!/(n-k)!
 - 组合(combination)  
   C<sup>k</sup><sub>n</sub> = P<sup>k</sup><sub>n</sub> /P<sup>k</sup><sub>k</sub>  
	= n!/(n-k)!k!
 	