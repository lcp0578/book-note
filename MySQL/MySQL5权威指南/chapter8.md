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
	- 日期与时间
		- DATE '2017-08-27' 格式的日期值，取值范围1000-01-01~9999-12-31(3个字节)
		- TIME '16:33:59' 格式的时间值，取值范围：+838:59:59(3个字节)
		- DATETIME '2017-08-27 16：33：59'格式的DATE和TIME组合
		- YEAR 年份，取值范围： 100~2155(1个字节)
		- TIMESTAMP 这个类型的字段会在数组记录的其他字段被修改时，自动刷新。  
		PS：对日期和时间顺序进行的合法检查由MySQL系统变量sql_mode控制。
	- 字符串
		- CHAR(n) 固定长度的字符串，最多255个字符
		- VARCHAR(n) 可变长度的字符串，MySQL 4.1及以前 n < 256;MySQL 5.0.3 及以后 n < 65535
		- TINYTEXT 可变长度的字符串，最多255个字符
		- TEXT 可变长度的字符串，最多(2<sup>16</sup> - 1) 个字符
		- MEDIUMTEXT 可变长度的字符串，最多(2<sup>24</sup> - 1) 个字符
		- LONGTEXT 可变长度的字符串，最多(2<sup>32</sup> - 1) 个字符  
		PS: 如果给CHAR和VARCHAR类型的数据都加上可选的BINARY 属性，MySQL会把他们视同BLOB数据来处理，排序的时候可以把字母的大小写区分开。
	- 二进制数据（BLOB， binary large object）
		- BIT(n) 二进制数据，n是二进制位的个数（最大可取值64）
		- TINYTBLOB 可变长度的字符串，最多255个字符
		- BLOB 可变长度的字符串，最多(2<sup>16</sup> - 1) 个字符
		- MEDIUMBLOB 可变长度的字符串，最多(2<sup>24</sup> - 1) 个字符
		- LONGBLOB 可变长度的字符串，最多(2<sup>32</sup> - 1) 个字符 
	- 特有数据类型
		- ENUM 字符串的排列集合，最多可以有65535个成员
		- SET 字符串的组合集合，最多可以有255个成员
		- GEOMETRY、POINT等 二位地理数据对象
- MySQL数据列的选项和属性
	- NULL 数据列中可以包含NULL值（这是默认的设置）
	- NOT NULL 不允许包含NULL值
	- DEFAULT xxx 如果输入时没有给出一个具体的值，则使用xxx作为默认值
	- DEFAULT CURRENT_TIMESTAMP 仅适用与TIMESTAMP数据列，在创建新纪录时保存当前时间
	- ONE UPDATE CURRENT_TIMESTAMP 仅适用与TIMESTAMP数据列，在修改纪录时保存当前时间
	- PRIMARY KEY 主键
	- AUTO_INCREMENT 仅适用于正数类型的数据列
	- UNSIGNED 本地数据列里的数据都将是无符号整数
		