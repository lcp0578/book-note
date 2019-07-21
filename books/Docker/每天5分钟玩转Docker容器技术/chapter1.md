## 第1章 鸟瞰容器生态系统
- 容器生态系统
	1. 容器核心技术
		- 容器规范（Open Container Initiative: OCI组织）
			- runtime spec
			- image format spec
		- 容器runtime(runtime是容器真正运行的地方。runtime需要跟操作系统kernel紧密协作，为容器提供运行环境)
			- lxc（Linux上老牌的容器runtime。Docker最初采用lxc作为runtime）
			- runc（Docker自己开发的容器runtime，符合OCI规范，也是现在Docker的默认runtime）
			- rkt （CoreOS开发的容器runtime,符合OCI规范）
		- 容器管理工具
			- lxd
			- docker engine
				- deamon
				- cli
			- rkt cli
		- 容器定义工具
			- docker image(Docker容器的模板，runtime依据docker image创建容器)
			- dockerfile（包含若干命令的文本文件，可以通过这些命令创建出docker image）
			- ACI(App Container Image)（与docker image类似，它是由CoreOS开发的rkt容器的image格式）
		- Registries（统一存放image的仓库）
			- Docker Registry
			- Docker Hub
			- Quay.io
		- 容器OS（专门运行容器的操作系统，与常规OS相比，容器OS通常体积更小，启动更快，通常效率会更高）
			- CoreOS
			- atomic
			- ubuntu core
	2. 容器平台技术
		- 容器编排引擎(所谓编排orchestration，通常包括容器管理、调度、集群定义和服务发现等)
			- docker swarm
			- kubernetes
			- mesos + marathon
		- 容器管理平台
			- Rancher
			- ContainerShip
		- 基于容器的PaaS
			- Deis
			- Flynn
			- Dokku
	3. 容器支持技术
		- 容器网络(管理容器与容器、容器与其他实体之间的连通性和隔离性)
			- docker network
			- flannel
			- weave
			- calico
		- 服务发现
			- etcd
			- consul
			- zookeeper
		- 监控
			- docker ps/top/stats
			- docker stats API
			- sysdig
			- cAdvisor/Heapster
			- Weave Scope
		- 数据管理
			- Rex-Ray
		- 日志管理
			- docker logs
			- logspout
		- 安全性
			- OpenSCAP
- [在CentOS上安装Docker CE](https://github.com/lcp0578/cheat-sheets/blob/master/src/Docker/install_centos.md)
- 运行第一个容器

		# docker run -d -p 8080:80 httpd
        // 将容器的80端口映射到host的8080端口 
- 镜像下载加速

			# curl -sSL https://get.daocloud.io/daotools/set_mirror.sh | sh -s http://xxxxxxx.m.daocloud.io
            docker version >= 1.12
            {"registry-mirrors": ["http://xxxxxxx.m.daocloud.io"]}
            Success.
            You need to restart docker to take effect: sudo systemctl restart docker 
            # systemctl restart docker.service
