## 第3章 Docker镜像
- base镜像
	- 不依赖其他镜像，从scratch构建
	- 其他镜像可以以之为基础进行扩展。
	- 所以，能称作base镜像的通常都是各种Linux发行版的Docker镜像。
- Linux操作系统由内核空间和用户空间组成
	- 内核空间是kernel， Linux刚启动时会加载bootfs文件系统，之后