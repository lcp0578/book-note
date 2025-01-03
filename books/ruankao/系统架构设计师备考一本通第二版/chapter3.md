## 第3章 操作系统知识
- 操作系统有3个重要作用
	- 第一：管理计算机中运行的程序和分配各种软硬件资源；
	- 第二：为用户提供友善的人机界面；
	- 第三：为应用程序的开发和运行提供一个高效率的平台。
- 操作系统的4个特征
	- 并发性
	- 共享性
	- 虚拟性
	- 不确定性
- 操作系统的功能
	- 进程管理。
		- 实质上是对处理机的执行“时间”进行管理，采用多道程序等技术将CPU的时间合理地分配给每个任务，主要包括进程控制、进程同步、进程通信和进程调度。
	- 文件管理。
		- 文件管理主要包括文件存储空间管理、目录管理、文件的读/写管理和存取控制。
	- 存储管理。
		- 存储管理是对主存储器“空间”进行管理，主要包括存储分配与回收、存储保护、地址映像（变换）和主存扩充。
	- 设备管理。
		- 设备管理实质是对硬件设备的管理，包括对输入/输出设备的分配、启动、完成和回收。
	- 作业管理。
		- 作业管理包括任务、界面管理、人机交互、图形界面、语音控制和虚拟现实等。
- 操作系统的分类
	- 批处理操作系统
		- 单道批处理和多道批处理（主机与外设可并行）。
	- 分时操作系统
		- 一个计算机系统与多个终端设备连接。分时操作系统是将CPU的工作时间划分为许多很短的时间片，轮流为各个终端的用户服务。
		- 分时操作系统是将CPU的工作时间划分为许多很短的时间片，轮流为各个终端的用户服务。
	- 实时操作系统。
		- 实时是指计算机对外来信息能够以足够快的速度进行处理，并在被控对象允许的时间范围内作出快速反应。
		- 实时操作系统对交互能力要求不高，但要求可靠性有保障。
		- 为了提高系统的响应时间，对随机发生的外部事件应及时作出响应并对其进行处理。
	- 网络操作系统
		- 使联网计算机能方便而有效地共享网络资源，为网络用户提供各种服务的软件和有关协议的集合。
		- 功能主要包括
			- 高效、可靠的网络通信；
			- 对网络中共享资源的有效管理；
			- 提供电子邮件、文件传输、共享硬盘和打印机等服务；
			- 网络安全管理；
			- 提供互操作能力。
		- 三种模式为：
			- 集中式
			- 客户端/服务器模式
			- 对等模式
	- 分布式操作系统
		- 由多个分散的计算机连接而成的计算机系统，系统中的计算机无主次之分，任意两台计算机可以通过通信交互信息。
		- 通常，为分布式计算机系统配置的操作系统称为分布式操作系统，是网络操作系统的更高级形式。
	- 微型计算机操作系统
		- 简称微机操作系统，常用的有Windows、Mac OS、Linux。
	- 嵌入式操作系统
		- 运行在嵌入式智能芯片环境中，对整个智能芯片以及它所操作、控制的各种部件装置等资源进行统一协调、处理、指挥和控制。
		- 其主要特点如下：
			- 微型化。从性能和成本角度考虑，希望占用的资源和系统代码量少，如内存少、字长短、运行速度有限、能源少（用小型电池）。
			- 可定制。从减少成本和缩短研发周期考虑，要求嵌入式操作系统能运行在不同的微处理器平台上，能针对硬件变化进行结构与功能上的配置，以满足不同的应用需要。
			- 实时性。嵌入式操作系统主要应用于过程控制、数据采集、传输通信、多媒体信息及管件要害领域需要迅速响应的场合，所以对实时性要求较高。
			- 可靠性。系统构件、模块和体系结构必须达到应有的可靠性，对关键要害应用还要提供容错和防故障措施。
			- 易移植性。为了提高系统的易移植性，通常采用硬件抽象层(Hardware Abstraction Level, HAL)和板级支撑包(Board Support Package, BSP)的底层设计技术。
	- 微内核操作系统
		- 微内核，顾名思义，就是尽可能地将内核做得很小，只将最为核心必要的东西放入内核中，其他能独立的东西都放入用户进程中，这样，系统就被分为了用户态和内核态。