## 搭建Qt 5.12开发环境
- CDB(Microsoft Console Debugger) 是微软公司Windows SDK套件中的一款命令行调试工具。由于集成开发环境Qt Creator 4.8不自带调试器，因此需要为这个集成开发环境按照和配置调试器，否则无法进行单步调试。
- QCoreApplication最重要的函数是`exec()`，这个函数会开启事件循环并且进入阻塞状态。
- 快捷键：
	- F10: Step Over（不进函数）
	- F11: Step Into,（进函数）