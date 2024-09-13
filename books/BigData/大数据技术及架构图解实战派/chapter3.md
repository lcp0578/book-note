## 第3章 海量数据存储
- 海量数据存储的演进之路
	- Hadoop中的HDFS（Hadoop Distributed File System,分布式文件系统），它可以解决海量数据存储的问题，但是其最大的缺点是不支持单挑数据的修改操作，因为它毕竟不熟数据库。
	- HBase是一个基于HDFS分布式NoSQL数据库。这意味着，HBase可以利用HDFS的海量数据存储能力，并支持修改操作。但HBase并不是关系型数据库，所以它无法支持传统的SQL语法。
	- Kudu介于HDFS和HBase之间，支持数据修改，也支持基于SQL的统计分析。
		- Kudu不及HDFS批处理速度快，也不及HBase随机读写能力强。
		- 但是，在 SQL统计分析场景下，Kudu比HBase的批处理速度快；在实时写入或更新的场景下，Kudu比HDFS的随机读写能力强。