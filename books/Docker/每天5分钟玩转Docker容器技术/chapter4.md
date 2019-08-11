## 第4章 Docker容器
- `docker run -d ubuntu` 参数-d以后台方式启动容器。
- 两种进入容器的方法
	- `docker attach [CONTAINER ID]` CONTAINER ID可以通过docker ps查看
	- `docker exec -it [CONTAINER ID] [COMMAND]` 常用的命令 `docker exec -it [CONTAINER ID] bash|sh`
		PS: -it以交互模式打开pseudo-TTY,执行bash
- attach VS exec
	- attach直接进入容器启动命令的终端，不会启动新的进程。执行exit后，容器停止，退出attch终端使用ctrl+q。
	- exec则是在容器中打开新的终端，并且可以启动新的进程。执行exit后，退出终端，容器继续运行。
	- 如果想直接在终端中查看启动命令的输出，用attach，其他情况使用exec。
	- 如果只为了查看启动命令的输出，可以使用`docker logs -f [CONTAINTER ID]`命令。