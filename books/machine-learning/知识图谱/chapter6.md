## 第6章 知识计算
- 知识计算(Knowledge Computing)是指在图论的指导下，使用图论中的定理、推论、模型、算法，以及相应的工具来计算、处理、分析、理解和挖掘知识图谱的方法。
- 图论基础知识
- 谱图理论(Spectral Graph Theory)
	- 在谱图理论中，通过图的邻接矩阵（或者拉普拉斯矩阵等）表示将图转化为矩阵，并使用矩阵和代数的方法，通过特征多项式、特征值和特征向量来研究图的性质。
- 遍历与最短路径算法
	- 广度优先搜索
		- 广度优先搜索算法是一种分层搜索的过程，每前进一步，就访问一批顶点。
	- 深度优先搜索
	- Dijkstra单源最短路径
		- Dijkstra单源最短路径算法是对广度优先搜索算法的推广。
	- 最短路径快速算法
		- Bellman-Ford算法是一个经典的算法，能够求解具有负权值的图的单源最短路径，其基本原理是搜索所有的边，并跟踪搜索过程中所找到的最短路径。
	- Floyd算法
		- Floyd算法又称Floyd-Warshall算法，用于寻找图中所有顶点对间的最短路径。
- 中心性
	- 中心性(Centrality)是通过图的结构信息来评估顶点或边的重要性的指标。
	- 度中心性
		- 度中心性(Degree Centrality)通过顶点的度数--顶点的边的数量--来衡量一个顶点在图中的重要性。
	- 亲密中心性
		- 亲密中心性(Closeness Centrality)是用距离来衡量顶点在图中的重要性的指标。
	- 中介中心性
		- 中介中心性(Betweenness Centrality)是衡量点活边被访问的频繁程序的指标。
	- 特征向量中心性
		- 特征向量中心性(Eigenvector Centrality)是谱图理论的研究内容之一，是基于图的邻接矩阵的谱特征来计算的中心性度量指标。
	- PageRank
		- PageRank是Google搜索引擎的核心算法，由Google公司的创始人提出。
		- PageRank考虑了顶点的邻接顶点的中心性，衡量了顶点的传递方向的影响，其本质上与特征向量中心性一样，是基于邻接矩阵的特征向量的一种度量，可以认为是另一种特征向量中心性。
- 社区检测
	- 模块度
	- GN社区检测算法
	- Louvain社区检测算法
- 知识计算工具与系统
	- 图数据库计算框架
	- 分布式图计算引擎
		- Spark GraphX
		- Apache Giraph
	- 图分析工具包
		- NetworkX
		- igraph
		- SNAP
		- JGraphT