## 第3章 打包和工具链 
- 包
	- 同一目录下的所有.go文件必须声明为同一个包名。
	- Go开发者创建的包会在GOPATH环境变量指定的目录里查找。GOPATH指定的这些目录就是开发者的个人工作空间。
- 函数init
	- 每个包可以包含任意多个init函数，所有被编译发现的init函数都会在mian韩式之前执行。
	- init函数用在设置包、初始化变量或者其他要在程序运行之前优先完成的引导工作。
- 使用Go的工具
	
        go build hello.go //执行编译
        go clean hello.go //清理
        go run hello.go //先构建再执行
        go vet test.go //检测代码常见错误
        go fmt -w dir //代码格式化
- Go文档
	- 命令查看
		
            $ go doc net
            package net // import "net"

            Package net provides a portable interface for network I/O, including TCP/IP,
            UDP, domain name resolution, and Unix domain sockets.

            Although the package provides access to low-level networking primitives,
            most clients will need only the basic interface provided by the Dial,
            Listen, and Accept functions and the associated Conn and Listener
            interfaces. The crypto/tls package uses the same interfaces and similar Dial
            and Listen functions.
	- 浏览文档
	
    		$ godoc -http=:6060 //用浏览器访问:http://localhost:6060即可查看文档
- 依赖管理
	- godep
	- gb
