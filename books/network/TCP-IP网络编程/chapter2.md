## 第二章 套接字类型与协议设置
- 协议族(Protocol Family)
	- PF_INET IPv4互联网协议族
	- PF_INET6 IPv6互联网协议族
	- PF_LOCAL 本地通信UNIX协议族
	- PF_PACKET 底层套接字的协议族
	- PF_IPX IPX Novell协议族
- 套接字类型
	- 面向连接的套接字(SOCK_STREAM)，可靠的、按序传递的、基于字节的面向连接的数据传输方式。
	- 面向消息的套接字(SOCK_DGRAM)，不可靠的、不按序传递的、以数据的高速传输为目的的套接字。
