## 第二章 TCP/IP基础知识
### 2.1 TCP/IP背景及历史
### 2.2 TCP/IP的标准化
**RFC** (Request For Comment) TCP/IP的规范。
RFC官网:[www.rfc-editor.org](http://www.rfc-editor.org/)  

RFC中文:[man.chinaunix.net/develop/rfc/default.htm](http://man.chinaunix.net/develop/rfc/default.htm)  

### 2.3 互联网基础知识
<table cellspacing="0" border="0">
    <tr>
        <th>OSI参考模型</th>
		<th>TCP/IP分层模型</th>
		<th></th>
    </tr>
    <tr>
        <td>应用层</td>
		<td rowspan="3">
		应用层<br>
		DNS,URI,HTML,HTTP,<br> 
		TLS/SSL,SMTP,POP,IMAP,<br>
		MIME,TELNET,SSH,FTP,<br>
		SNMP,MIB,SIP,RTP,LDAP
		</td>
        <td rowspan="3">应用程序</td>
    </tr>
	 <tr>
        <td>表示层</td>
    </tr>
 	<tr>
        <td>会话层</td>
    </tr>
 	<tr>
        <td>传输层</td>
		<td>传输层<br>
		TCP,UDP,UDP-Lite,SCTP,DCCP
		</td>
		<td rowspan="2">操作系统</td>
    </tr>
 	<tr>
        <td>网络层</td>
		<td>互联网层<br>ARP,IP,ICMP</td>
    </tr>
    <tr>
        <td>数据链路层</td>
		<td>网卡层</td>
		<td rowspan="2">设备驱动程序与网络接口</td>
    </tr>
    <tr>
        <td>物理层</td>
		<td>（硬件）</td>
    </tr>
</table>