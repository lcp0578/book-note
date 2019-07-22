## 第2章 容器核心知识概述
- Docker将集装箱思想运用到软件打包上，为代码提供了一个基于容器的标准化运输系统。
- Docker可以将任何应用及其依赖打包成一个轻量级、可移植、自包含的容器。
##### 容器的优势
- 对于开发人员：Build Once、Run Anywhere
- 对于运维人员：Configure Once、Run Anything

##### Docker架构
- Docker客户端： Client
	- `docker build`
	- `docker pull`
	- `docker run`
- Docker服务端：Docker daemon
	- Docker daemon是服务器组件，以Linux后台服务的方式运行。
	- Docker daemon运行在Docker host上，负责创建、运行、监控容器，构建、存储镜像。
- Docker镜像：Image
	- Dcoker镜像看成只读模板，通过它可以创建Docker容器。
- Registry
	- Registry是存放Docker镜像的仓库，Registry分私有和公有两种。
- Docker容器：Container
	- Docker容器就是Docker镜像的运行实例。
	- 用户可以通过CLI(Docker)或时API启动、停止、移动或删除容器。

##### 查看状态

        # systemctl status docker.service
        ● docker.service - Docker Application Container Engine
           Loaded: loaded (/usr/lib/systemd/system/docker.service; disabled; vendor preset: disabled)
           Active: active (running) since 日 2019-07-21 10:09:01 CST; 7h ago
             Docs: https://docs.docker.com
         Main PID: 10076 (dockerd)
            Tasks: 128
           Memory: 1.7G
           CGroup: /system.slice/docker.service
                   ├─10076 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
                   ├─12725 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 8010 -container-ip 172.18.0.2 -container-port 8010
                   ├─12763 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 3000 -container-ip 172.18.0.3 -container-port 3000
                   ├─12827 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 32768 -container-ip 172.18.0.4 -container-port 2379
                   ├─12873 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 32769 -container-ip 172.18.0.5 -container-port 2379
                   ├─12973 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 32770 -container-ip 172.18.0.7 -container-port 2379
                   ├─13008 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 9090 -container-ip 172.18.0.8 -container-port 9090
                   ├─14117 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 10080 -container-ip 172.18.0.12 -container-port 10080
                   ├─14136 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 4000 -container-ip 172.18.0.12 -container-port 4000
                   ├─14155 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 8080 -container-ip 172.18.0.13 -container-port 8080
                   ├─14195 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 7077 -container-ip 172.18.0.13 -container-port 7077
                   └─14635 /usr/bin/docker-proxy -proto tcp -host-ip 0.0.0.0 -host-port 38081 -container-ip 172.18.0.14 -container-port 38081

        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.708165186+08:00" level=info msg="pickfirstBalancer: HandleSubConnStateChange: 0xc4200cb9e0, READY" module=grpc
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.721654697+08:00" level=info msg="[graphdriver] using prior storage driver: overlay2"
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.725307241+08:00" level=info msg="Graph migration to content-addressability took 0.00 seconds"
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.726230931+08:00" level=info msg="Loading containers: start."
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.838340825+08:00" level=info msg="Default bridge (docker0) is assigned with an IP address 172.17.0.0/16. Daemon option --bip can be used to se...rred IP address"
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.877466106+08:00" level=info msg="Loading containers: done."
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.922971544+08:00" level=info msg="Docker daemon" commit=0dd43dd graphdriver(s)=overlay2 version=18.09.8
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.923097174+08:00" level=info msg="Daemon has completed initialization"
        7月 21 10:09:01 localhost.localdomain dockerd[10076]: time="2019-07-21T10:09:01.935472204+08:00" level=info msg="API listen on /var/run/docker.sock"
        7月 21 10:09:01 localhost.localdomain systemd[1]: Started Docker Application Container Engine.
        Hint: Some lines were ellipsized, use -l to show in full.
##### 查看images

    # docker images
    REPOSITORY            TAG                 IMAGE ID            CREATED             SIZE
    pingcap/tikv          latest              d2991e8b9840        23 hours ago        361MB
    pingcap/tidb          latest              bcf7806d9f5d        32 hours ago        80MB
    pingcap/tispark       latest              2092257993e1        2 days ago          864MB
    pingcap/pd            latest              8052357687b7        5 days ago          80.3MB
    httpd                 latest              ee39f68eb241        8 days ago          154MB
    grafana/grafana       6.0.1               ffd9c905f698        4 months ago        241MB
    hello-world           latest              fce289e99eb9        6 months ago        1.84kB
    pingcap/tidb-vision   latest              e9b25d9f7bdb        14 months ago       47.6MB
    prom/prometheus       v2.2.1              cc866859f8df        16 months ago       113MB
    prom/pushgateway      v0.3.1              434efa6ed9db        2 years ago         13.3MB
- 查看运行的容器

        # docker ps // 或 docker container ls
        CONTAINER ID        IMAGE                        COMMAND                  CREATED             STATUS              PORTS                                               NAMES
        f2ae40f77358        pingcap/tispark:latest       "/opt/spark/sbin/sta…"   6 hours ago         Up 6 hours          0.0.0.0:38081->38081/tcp                            tidb-docker-compose_tispark-slave0_1
        395e39ea219f        pingcap/tispark:latest       "/opt/spark/sbin/sta…"   6 hours ago         Up 6 hours          0.0.0.0:7077->7077/tcp, 0.0.0.0:8080->8080/tcp      tidb-docker-compose_tispark-master_1
        fe1d98a504b1        pingcap/tidb:latest          "/tidb-server --stor…"   6 hours ago         Up 6 hours          0.0.0.0:4000->4000/tcp, 0.0.0.0:10080->10080/tcp    tidb-docker-compose_tidb_1
        3d47dfa108c1        pingcap/tikv:latest          "/tikv-server --addr…"   6 hours ago         Up 6 hours          20160/tcp                                           tidb-docker-compose_tikv0_1
        acdc104bb785        pingcap/tikv:latest          "/tikv-server --addr…"   6 hours ago         Up 6 hours          20160/tcp                                           tidb-docker-compose_tikv2_1
        ec840203c4e8        pingcap/tikv:latest          "/tikv-server --addr…"   6 hours ago         Up 6 hours          20160/tcp                                           tidb-docker-compose_tikv1_1
        6a2c9cb04c6a        pingcap/pd:latest            "/pd-server --name=p…"   6 hours ago         Up 6 hours          2380/tcp, 0.0.0.0:32770->2379/tcp                   tidb-docker-compose_pd1_1
        89d240939499        prom/prometheus:v2.2.1       "/bin/prometheus --l…"   6 hours ago         Up 6 hours          0.0.0.0:9090->9090/tcp                              tidb-docker-compose_prometheus_1
        3ae197ddc6b3        pingcap/pd:latest            "/pd-server --name=p…"   6 hours ago         Up 6 hours          2380/tcp, 0.0.0.0:32769->2379/tcp                   tidb-docker-compose_pd0_1
        d825406e04e9        prom/pushgateway:v0.3.1      "/bin/pushgateway --…"   6 hours ago         Up 6 hours          9091/tcp                                            tidb-docker-compose_pushgateway_1
        48c6c54bcd65        pingcap/pd:latest            "/pd-server --name=p…"   6 hours ago         Up 6 hours          2380/tcp, 0.0.0.0:32768->2379/tcp                   tidb-docker-compose_pd2_1
        0a5e8f002ee5        pingcap/tidb-vision:latest   "/bin/sh -c 'sed -i …"   6 hours ago         Up 6 hours          80/tcp, 443/tcp, 2015/tcp, 0.0.0.0:8010->8010/tcp   tidb-docker-compose_tidb-vision_1
        04aaee643b04        grafana/grafana:6.0.1        "/run.sh"                6 hours ago         Up 6 hours          0.0.0.0:3000->3000/tcp                              tidb-docker-compose_grafana_1

##### docker命令

        $ docker

        Usage:	docker [OPTIONS] COMMAND

        A self-sufficient runtime for containers

        Options:
              --config string      Location of client config files (default "/Users/lcp0578/.docker")
          -D, --debug              Enable debug mode
          -H, --host list          Daemon socket(s) to connect to
          -l, --log-level string   Set the logging level ("debug"|"info"|"warn"|"error"|"fatal") (default "info")
              --tls                Use TLS; implied by --tlsverify
              --tlscacert string   Trust certs signed only by this CA (default "/Users/lcp0578/.docker/ca.pem")
              --tlscert string     Path to TLS certificate file (default "/Users/lcp0578/.docker/cert.pem")
              --tlskey string      Path to TLS key file (default "/Users/lcp0578/.docker/key.pem")
              --tlsverify          Use TLS and verify the remote
          -v, --version            Print version information and quit

        Management Commands:
          checkpoint  Manage checkpoints
          config      Manage Docker configs
          container   Manage containers
          image       Manage images
          network     Manage networks
          node        Manage Swarm nodes
          plugin      Manage plugins
          secret      Manage Docker secrets
          service     Manage services
          stack       Manage Docker stacks
          swarm       Manage Swarm
          system      Manage Docker
          trust       Manage trust on Docker images
          volume      Manage volumes

        Commands:
          attach      Attach local standard input, output, and error streams to a running container
          build       Build an image from a Dockerfile
          commit      Create a new image from a container's changes
          cp          Copy files/folders between a container and the local filesystem
          create      Create a new container
          deploy      Deploy a new stack or update an existing stack
          diff        Inspect changes to files or directories on a container's filesystem
          events      Get real time events from the server
          exec        Run a command in a running container
          export      Export a container's filesystem as a tar archive
          history     Show the history of an image
          images      List images
          import      Import the contents from a tarball to create a filesystem image
          info        Display system-wide information
          inspect     Return low-level information on Docker objects
          kill        Kill one or more running containers
          load        Load an image from a tar archive or STDIN
          login       Log in to a Docker registry
          logout      Log out from a Docker registry
          logs        Fetch the logs of a container
          pause       Pause all processes within one or more containers
          port        List port mappings or a specific mapping for the container
          ps          List containers
          pull        Pull an image or a repository from a registry
          push        Push an image or a repository to a registry
          rename      Rename a container
          restart     Restart one or more containers
          rm          Remove one or more containers
          rmi         Remove one or more images
          run         Run a command in a new container
          save        Save one or more images to a tar archive (streamed to STDOUT by default)
          search      Search the Docker Hub for images
          start       Start one or more stopped containers
          stats       Display a live stream of container(s) resource usage statistics
          stop        Stop one or more running containers
          tag         Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE
          top         Display the running processes of a container
          unpause     Unpause all processes within one or more containers
          update      Update configuration of one or more containers
          version     Show the Docker version information
          wait        Block until one or more containers stop, then print their exit codes

        Run 'docker COMMAND --help' for more information on a command.