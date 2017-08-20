## 第八章 数据库设计概论
- HEAP数据表  
	HEAP数据表只存在于内存中（不是硬盘上），他们使用了一个散列索引(hash index)，所以数据记录的读取速度非常快。  
	HEAP数据表主要用途是充当临时数据表。
- MySQL 数据类型
	- 整数（默认即可包含正数，也包含负数，若定义UNSIGNED属性，则取值范围仅限正数）
		- TINYINT(m), 8位整数（1个字节， -128 ~ +127）
		- SMALLINT(m)， 16位整数(2个字节，从-2<sup>15</sup> ~ +2<sup>15</sup>-1)
		- MEDIUMINT(m), 24位整数(3个字节， 从-2<sup>23</sup> ~ +2<sup>23</sup>-1)
		- INT(m)、INTEGER(m), 32位整数(4个字节， 从-2<sup>31</sup> ~ +2<sup>31</sup>-1)
		- BIGINT(m), 64位整数(8个字节， 从-2<sup>63</sup> ~ +2<sup>63</sup>-1)  
		- SERIAL 为BIGINT AUTO_INCREMENT NOT NULL PRIMARY KEY的简写。  
		PS: 可选参数m给出的是SELECT查询结果中的数据列宽度(Maximum Display Width, 最大显示宽度)，对取值范围没有影响。作用是把查询结果以一种整齐易读的格式显示。  
	- 二进制数据
		- BOOL 是TINYINT的同义词
		- BIT(m),可以存储多达64位二进制数据
	- 浮点数
		- FLOAT(m,d) 单精度浮点数，8位精度（4字节）。
		- DOUBLE(m,d) 双精度浮点数
		- REAL(m,d) DOUBLE的同义词  
		PS：参数m和d是可选的。m是十进制数字的总个数，d是小数点后面数字的个数。在插入数据的时候，数值将做必要的舍入。超出范围的数值将被替换为最大可取值。可以用SHOW WARNING命令来查看警告的内容。  
  		参数m只影响显示效果，对数值没有影响。参数d则不同，小数点后面的数字需要按照它来舍入。
	- 定点数（在使用FLOAT和DOUBLE数据类型时，会自动进行必要的舍入，如果因此带来的误差不可接受（比如处理财务数据时），就应该选择DECIMAL）  
		- DECIMAL(p,s)  定点数，以二进制格式进行保存 
		- NUMERIC、DEC 双精度浮点数，16位精度（8字节）  
		PS: p表示范围，最大值65，默认值10，s表示精确度，最大值为30  
		DECIMAL(M) =  DECIMAL(M,0)  
		DECIMAL(5,2)，取值范围：-999.99 ~ 999.99.
			
