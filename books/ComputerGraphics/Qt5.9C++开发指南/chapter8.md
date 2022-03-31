## 第8章 绘图
### QPainter基本绘图
- 绘图系统基于`QPainter`、`QPaintDevice`和`QPaintEngine`类。
	- `QPainter`是用户来进行绘图操作的类
	- `QPaintDevice`是一个可以使用`QPainter`进行绘图的抽象的二维界面
	- `QPaintEngine`给`QPainter`提供在不同设备上绘图的接口
- 一般的绘图设备包括`QWidget`、`QPixmap`、`QImage`等，这些绘图设备为`QPainter`提供一个画布。
- QPen
- QBrush
- 渐变填充
### 坐标系统和坐标变换
- QPainter提供了一些坐标变换的功能，通过平移、旋转等坐标变换，得到一个逻辑坐标系统，使用逻辑坐标系统在某些时候绘图更方便。
### Graphics View绘图架构
- Graphics View架构主要由3个部分组成，即场景、视图和图形项。