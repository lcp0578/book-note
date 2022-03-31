## 第6章 对话框与多窗体设计
### 标准对话框
- QFileDialog 文件对话框
- QColorDialog 颜色对话框
- QFontDialog 字体对话框
- QInputDialog 输入对话框
- QMessageBox 消息框
### 多窗体应用程序设计
- `QObject`
	- `QWindow`通过底层的窗口系统表示一个窗口的类，一般作为一个父容器的嵌入式窗体，不作为独立窗体。
	- `QWidget` 在没有指定父容器时，可作为独立的窗口，指定父容器后可以作为容器的内部组件。
		- `QDialog`用于设计对话框，以独立窗口显示。
		- `QMainWindow`用于设计才有菜单栏、工具栏、状态栏的主窗口，一般以独立窗口显示。
		- `QSplashScreen`用作应用程序启动时的splash窗口，没有边框。
		- `QMdiSubWindow`用于为`QMdiArea`提供一个子窗体，用MDI(多文档)应用程序的设计。
		- `QDesktopWidget`具有多个显卡和多个显示器的系统具有多个桌面，这类提供用户桌面信息，如屏幕个数、每个屏幕的大小等。
### MDI应用程序设计
- 多文档界面(Multi-document Interface, MDI)
### Splash与登录窗口