### 1.2 高扩展性  
Nginx的设计极具扩展性，它完全是由多个不同功能、不同层次、不同类型且耦合度极低的模块组成。  
### 1.3.2 使用Nginx的必备软件
1. GCC编译器 (GUN Compiler Collection)
2. PERE库 (Perl Compatible Regular Expressions)
3. zlib库
4. OpenSSL开发库

### 1.3.4 Linux内核参数的优化
修改/etc/sysctl.conf来更改内核参数，然后执行sysctl -p 命令，使上述修改生效。

### 1.6 Nginx的命令行控制
- 另行指定配置文件的启动方式   

	/user/local/nginx/sbin/nginx -c /tmp/nginx.conf

- 测试配置信息是否有误
	
	/user/local/nginx/sbin/nginx -t
- 快速停止服务  
	
	/user/local/nginx/sbin/nginx -s stop

- “优雅”地停止服务  
	
	/user/local/nginx/sbin/nginx -s quit

- 使运行中的Nginx重新读取配置并生效
	
	/user/local/nginx/sbin/nginx -s reload