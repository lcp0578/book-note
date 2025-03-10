## 第15章 软件可靠性基础知识
- 软件可靠性设计
	- 1、容错设计技术
		- 冗余设计
		- N版本程序设计
		- 恢复块设计（动态冗余）
		- 防卫式程序设计
	- 2、检错技术
	- 3、降低复杂度设计
- 通常在**系统配置**中可以采用相应的容错技术，通过系统的整体来提供相应的可靠性，主要有
	- 双机容错技术
	- 集群技术
		- 负载均衡是集群系统中的一项重要技术，可以提高集群系统的整体处理能力，也提高了系统的可靠性，最终目的是加快集群系统的响应速度，提高客户端访问的成功概率。
		- 比较常用的负载均衡实现技术主要有以下几种：
			- （1）基于特点软件的负载均衡。
			- （2）基于DNS的负载均衡。
			- （3）基于NAT的负载均衡。
			- （4）反向代理负载均衡。
			- （5）混合型负载均衡。