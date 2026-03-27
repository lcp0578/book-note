## 第2章 理解基础模型

### 训练数据

- AI模型的表现取决于其训练数据的质量。

### 建模

- 模型架构
  - Transformer架构
    - 基于Transformer的语言推理过程包括以下两个步骤：
      - 预填充。模型并行输入token。这一步创建生成第一个输出token所需的中间状态。该中间状态包括所有输入token对应的键向量和值向量。
      - 解码。模型逐个生成输出token。
    - 注意力机制。注意力机制是Transformer架构的核心，注意力机制允许模型在生成每个输出token时权衡不同输入token的重要性。
  - Transformer模块。
    - Transformer架构由多个Transformer模块组成。具体内容因模型而异，但通常，每个Transformer模块都包含一个注意力模块和一个MLP（multi-layer perceptron，多层感知机）模块。
- 模型规模
  - 模型数据集中的token总数与训练token数并不等同。
  - 衡量模型规模的三个关键指标如下：
    - 参数量：代表模型的学习能力。
    - 训练token数：代表模型学习到的知识量。
    - FLOPs：代表训练成本。FLOP（floating point operation, 浮点运算次数）
- 规模法则：构建算力最优的模型
  - 模型性能取决于模型规模和数据集规模；
  - 更多的模型和更大的数据集需要更多的算力；
  - 算力是有成本的。
- 给定算力预算，用于计算最佳模型规模和数据集大小的法则称为**Chinchilla规模法则**（Chinchilla scaling law）。
- 规模外推
  - **参数**是模型在训练过程中学习得到的，而**超参数**则由用户设定，用于配置模型并控制模型的学习方式。
  - 用于配置模型的超参数包括层数、模型维度和词表大小等；用于控制模型学习方式的超参数包括批次大小（batch size）、训练轮次、学习率（learning rate）、每层初始方差（per-layer initial variance）等。
  - 模型外推（scaling extrapolation，也称超参数迁移，hyperparameter transferring），旨在预测哪些超参数能使大模型获得最佳性能。