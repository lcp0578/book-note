## 第4章 常用界面设计组件
### 字符串与输入输出
- QLabel
- QLineEdit
- QString
	- QString的常用功能
		- `append()`和`prepend()`
		- `toUpper()`和`toLower()`
		- `count()`、`size()`和`length()`
		- `trimmed()`和`simplified()`
		- `indexOf()`和`lastIndexOf()`
		- `isNull()`和`isEmpty()`
		- `contains()`
		- `endsWith()`和`startsWith()`
		- `left()`和`right()`
		- `section()`
### SpinBox的使用
### 其他数值输入和显示组件
- `QSlider`滑动条
- `QScrollBar`卷滚条
- `QProgressBar`进度条
- `QDial`表盘式数值输入组件
- `QLCDNumber`模仿LCD数字的显示组件，可以显示整数或浮点数，显示整数时可以不同进制显示。
### 时间日期与定时器
- `QTime`:时间数据类型，仅表示时间，如15:20:58
- `QDate`:日期数据类型，仅表示日期，如2022-3-28
- `QDateTime`:日期时间数据类型，表示日期和时间，如：2022-03-28 08:17:56
- `QTimeEdit`:编辑和显示时间的组件。
- `QDateEdit`:编辑和显示日期的组件。
- `QDateTimeEdit`:编辑和显示日期时间的组件。
- `QCalendarWidget`:一个用日历形式选择日期的组件。
- `QTimer`:定时器类。
### QComboBox和QPlainTextEdit
- `QComboBox`下拉列表框组件类
- `QPlainTextEdit`多行文本编辑器
### QListWidget和QToolButton
- Item Views基于模型/视图(Model/View)结构，视图(View)与模型数据(Model Data)关联实现数据的显示和编辑。包括`QListView`、`QTreeView`、`QtableView`、`QColumnView`等。
- Item Widgets是直接将数据存储在每一个项里。包括`QListWidget`、`QTreeWidget`和`QTableWidget`。
### QTreeWidget和QDockWidget
- `QTreeWidget`类是创建和管理目录树结构的类。
- `QDockWidget`是可以在`QMainWindow`窗口停靠，或在桌面上层浮动的界面组件。
### QTableWidget的使用
- `QTableWidget`是Qt中的表格类组件类。