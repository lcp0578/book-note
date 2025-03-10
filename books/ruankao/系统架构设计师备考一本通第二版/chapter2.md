## 第2章 系统配置和性能评价
- 评价计算机的主要性能指标有
	- 时钟频率（主频）
	- 运算速度
	- 运算精度
	- 内存的存储容量
	- 存储器的存取周期
	- 数据处理速率(Processing Data Rate)
	- 吞吐率
	- 各种响应时间
	- 各种利用率
	- RASIS特性（即可靠性、可用性、可维护性、完整性和安全性）
	- 平均故障响应时间
	- 兼容性
	- 可扩充性
	- 性能价格比
- 衡量数据库管理系统的主要性能指标包括数据库本身和管理系统两部分。
	- 具体有：
		- 数据库的大小
		- 数据库中表的数量
		- 单个表的大小
		- 表中允许记录（行）数量
		- 单个记录（行）的大小
		- 表上所允许的索引数量
		- 数据库中所允许的索引数量
		- 最大并发事务处理能力
		- 负载均衡能力
		- 最大连接数
- 性能评价的常用方法
	- 时钟频率法。
		- 一般来讲，主频越高，速度越快。
	- 指令执行速度法。
		- 计量单位KIPS、MIPS。
	- 等效指令速度法。
		- 统计各类指令在程序中所占的比例并进行折算，是一种固定比例法。
	- 数据处理速率法。
		- 采用计算PDR值来衡量机器性能，PDR值越大，机器性能越好。PDR与每条指令和每个操作数的平均位数以及每条指令的平均运算速度有关。
- 基准程序法(Benchmark)
	- 把应用程序中用得最多、最频繁的那部分核心程序作为评价计算机性能的标准程序，称为基准测试程序。
	- 基准程序法是目前被用户一致承认的测试性能较好方法，基准程序多种多样，包括：
		- 整数测试程序。
			- 同一厂家的机器，采用相同的体系结构，用相同的基准程序测试，得到的MIPS值越大，一般说明机器速度越快。
		- 浮点测试程序。
			- 测量指标MFLOPS(Million Floating-point Operations Per Second)（理论峰值浮点速度）
		- SPEC基准程序(SPEC Benchmark)
			- 重点面向处理器性能的基准程序集，将被测计算机的执行时间标准化，即被测计算机的执行时间除以一个参考处理器的执行时间。
		- TPC基准程序。
			- 用于测评计算机在事务处理、数据库处理、企业管理与决策支持系统等方面性能。
				- TPC-C是为在线事务处理(On-line Transaction Processing, OLTP)的基准程序。
				- TPC-D是决策支持的基准程序。
				- TPC-E是为大型企业信息服务的基准程序。
- 阿姆达尔定律
	- 主要用于系统性能改进的计算中。
	- 阿姆达尔定律是指计算机系统中对某一部件采用某种更快的执行方式所获得的系统性能改变程度，取决于这种方式被使用的频率，或所占总执行时间的比例。

	$$加速比= \frac{不使用增强部件时完成整个任务的时间}{使用增强部件时完成整个任务的时间}$$

	$$总加速比= \frac{原来的执行时间}{新的执行时间}=\frac{1}{[(1-增强比例)+\frac{增强比例}{增强加速比}]}$$