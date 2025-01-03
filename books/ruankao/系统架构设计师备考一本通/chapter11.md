## 第11章 软件架构设计
- 架构风格汇总
<table>
	<tr>
		<th colspan="2">架构风格名</th>
		<th>常考关键字及实例</th>
		<th>简介</th>
	</tr>
	<tr>
		<td rowspan="2">数据流</td>
		<td>批处理</td>
		<td rowspan="2"> 传统编译器，每个阶段产生的结果作为下一个阶段的输入，区别在于整体</td>
		<td>一个接一个，以整体为单位</td>
	</tr>
	<tr>
		<td>过滤器</td>
		<td>一个接一个，前一个的输出是后一个的输入</td>
	</tr>
	<tr>
		<td rowspan="3">调用/返回</td>
		<td>主程序/子程序</td>
		<td></td>
		<td>显式调用，主程序直接调用子程序</td>
	</tr>
	<tr>
		<td>面向对象</td>
		<td> </td>
		<td>对象是构件，通过对象调用封装的方法和属性</td>
	</tr>
	<tr>
		<td>层次结构</td>
		<td></td>
		<td>分层，每层最多影响其上下两层，有调用关系</td>
	</tr>
	<tr>
		<td rowspan="2">独立构件</td>
		<td>进程通信</td>
		<td></td>
		<td>进程间独立的消息传递，同步和异步方式</td>
	</tr>
	<tr>
		<td>事件驱动(隐式调用)</td>
		<td> 事件触发推动动作，如程序语言的语法高亮、语法错误提示</td>
		<td>不直接调用，通过事件驱动</td>
	</tr>
	<tr>
		<td rowspan="2">虚拟机</td>
		<td>解释器</td>
		<td rowspan="2">自定义流程，按流程执行，规则随时改变，灵活定义，业务灵活组合机器人</td>
		<td>解释自定义的规则，解释引擎、存储区、数据结构</td>
	</tr>
	<tr>
		<td>规则系统</td>
		<td>规则集、规则解释器、选择器和工作内容，用于DSS和人工智能、专家系统</td>
	</tr>
	<tr>
		<td rowspan="3">仓库</td>
		<td>数据库</td>
		<td rowspan="3">现代编辑器的集成开发环境(IDE),以数据为中心。又称为数据共享风格</td>
		<td>中央共享数据源，独立处理单元</td>
	</tr>
	<tr>
		<td>超文本</td>
		<td>网状链接，多用于互联网</td>
	</tr>
	<tr>
		<td>黑板</td>
		<td>语音识别、知识推理等问题复杂、解空间很大、求解过程不确定的这一类软件系统，黑板、知识源、控制</td>
	</tr>
	<tr>
		<td>闭环</td>
		<td>过程控制</td>
		<td>汽车巡航定速，空调温度调节，设定参数，并不断调整</td>
		<td>发出控制命令并接受反馈，循环往复达到平衡</td>
	</tr>
	<tr>
		<td>C2风格</td>
		<td></td>
		<td>构件和连接件、顶部和底部</td>
		<td>通过连接件绑定在一起按照一组规则运作的并行构件网络</td>
	</tr>
</table>

- 架构描述语言
	- 架构描述语言(Architecture Description Language, ADL)是一种形式化语言，在底层语义模型的支持下，为软件系统的概念体系结构建模提供了具体语法和概念框架。
- 特定领域软件架构
	- DSSA的3个基本活动
		- 领域分析
		- 领域设计
		- 领域实现
	- 参与DSSA的4中角色人员
		- 领域专家
		- 领域分析人员
		- 领域设计人员
		- 领域实现人员
- 基于架构的软件开发(ABSD)
	- ABSD方法是架构驱动，强调业务、质量和功能需求的组合驱动架构设计。
- 软件架构评估
	- 质量属性
		- 性能：指系统的相应能力，即要经过多长时间才能对某个事件作出响应，或者在某段时间内系统所能处理的事件的个数。
			- 如响应时间、吞吐量，
			- 设计策略有优先级队列、增加计算资源、减少计算开销、引入并发机制、采用资源调度等。
		- 可靠性：是软件系统在应用或系统错误面前，在意外或错误使用的情况下维持软件系统的功能特性的基本能力。
			- 如MTTF、MTBF。
			- 设计策略有心跳、Ping/Echo、冗余、选举。
		- 安全性：是指系统在向合法用户提供服务的同时能够阻止非授权用户使用的企图或拒绝服务的能力。
			- 如保密性、完整性、不可抵赖性、可控性。
			- 设计策略有入侵检测、用户认证、用户授权、追踪审计。
		- 可修改性：指能够快速地以较高的性能价格比对系统进行变更的能力。通常以某些具体的变更为基准，通过考查这些变更的代价衡量。
			- 设计策略有接口-实现分类、抽象、信息隐藏。
		- 功能性：是系统所能完成所期望的工作的能力。
			- 一项任务的完成需要系统中许多或大多数构件的相互协作。
		- 可变性：指体系结构经扩充或变更而成为新体系结构的能力。
			- 这种新体系结构应该符合预先定义的规则，在某些具体方面不同于原有体系结构。
			- 当要将某个体系结构作为一系列相关产品的基础时，可变性是很重要的。
		- 互操作性：作为系统组成部分的软件不是独立存在的，经常与其他系统或自身环境相互作用。
			- 为了支持互操作性，软件体系结构必须为外部可视的功能特性和数据结构提供精心审计的软件入口。
			- 程序和用其他编程语言编写的软件系统的交互组作用就是互操作性的问题，也影响应用的软件体系结构。
	- 架构评估方式
		- 敏感点：是指为了实现某种特定的质量属性，一个或多个构件所具有的特性。
		- 权衡点：是影响多个质量属性的特性，是多个质量属性的敏感点。
		- 风险点与非风险点不是以标准专业术语形式出现的，只是一个常规概念，即可能引起风险的因素，可称为风险点。
			- 某个做法如果有隐患，有可能导致一些问题，则为风险点；
			- 而如果某件事是可行的、可接受的，则为非风险点。
	- 3种常用的评估方式
		- 基于调查问卷（检查表）的方式：类似于需求获取中的问卷调查方式，只不过是架构方面的问卷，要求评估人员对领域熟悉。
			- 评估的目的是为了评估所采用的架构是否能解决软件系统需求。
		- 基于度量的方式：指定一些定量来度量架构，如代码行数等，
			- 要制订质量属性和度量结构之间的映射，要求评估人员对架构熟悉。
		- 基于场景的方式：主要方法。
			- 首先要确定应用领域的功能和软件架构的结构之间的映射，然后要设计用于体现待评估质量属性的场景（即4+1视图中的场景），最后分析软件架构对场景的支持程度。
			- 要求评估人员即对领域熟悉，也对架构熟悉。