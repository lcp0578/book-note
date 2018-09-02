## 第1章 PHP基础架构
- PHP简介
- 安装与调试
	- 此书使用的php版本为7.0.12
	- 安装命令
		
			tar  zxvf php-7.0.12.tar.gz
			cd php-7.0.12
			./configure --prefix=/usr/local/php7 --enable-debug --enable-fpm

-  php7的主要变化
	1. 抽象语法树
	2. Native TLS(线程局部存储)
	3. 指定函数参数、返回值类型
	4. zval结构的变化
	5. 异常处理
	6. HashTable的变化
	7. 执行器
	8. 新的参数解析方式
- php的构成
- 生命周期