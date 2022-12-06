## 第8章 绘图
### QPainter基本绘图
- 绘图系统基于`QPainter`、`QPaintDevice`和`QPaintEngine`类。
	- `QPainter`是用户来进行绘图操作的类
	- `QPaintDevice`是一个可以使用`QPainter`进行绘图的抽象的二维界面
	- `QPaintEngine`给`QPainter`提供在不同设备上绘图的接口
- 一般的绘图设备包括`QWidget`、`QPixmap`、`QImage`等，这些绘图设备为`QPainter`提供一个画布。
- QPainter绘图的主要属性
	- 用QPainter在绘图设备上绘图，主要是绘制一些基本的图形元素，包括点、直线、圆形、矩形、曲线、文字等，控制这些绘图元素特性的主要是QPainter的3个属性，分别如下：
		- pen属性：是一个QPen对象，用于控制线条的颜色、宽度、线型等。
		- brush属性：是一个QBrush对象，用于设置一个区域的填充特性，可以设置填充颜色、填充方式、渐变特性等，还 可以采用图片做材质填充。
		- font属性：是一个QFont对象，用于绘制文字时，设置文字的字体样式、大小等属性。
	- 使用这3个属性基本就控制了绘图的基本特点，当然还有一些其他的功能结合使用，比如叠加模型、旋转和缩放等功能。
- QPen
- QBrush
- 渐变填充
### 坐标系统和坐标变换
- QPainter提供了一些坐标变换的功能，通过平移、旋转等坐标变换，得到一个逻辑坐标系统，使用逻辑坐标系统在某些时候绘图更方便。
### Graphics View绘图架构
- Graphics View架构主要由3个部分组成，即场景、视图和图形项。