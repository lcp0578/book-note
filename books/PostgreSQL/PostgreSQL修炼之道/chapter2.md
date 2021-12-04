## 第2章 PostgreSQL安装与配置
- 切换到postgre用户下
	`sudo su - postgres`
- `psql`是PostgreSQL中的客户端工具。
- `\l` 列出所有数据库
- `\q` 退出psql
- 启动数据库
	`pg_ctl start -D $PGDATA`
    - $PGDATA数据目录,示例：/Library/PostgreSQL/12/data
- 关闭数据库
	`pc_ctl stop -D $PGDATA [-m SHUTDOWN-MODE]`
    - SHUTDOWN-MODE
    	- smart:等所有连接中止后，关闭数据库。
    	- fast:快速关闭数据库，断开客户端的连接，让已有事务回滚，然后正常关闭数据库。
    	- immediate:立即关闭数据库，相当于数据库进程立即停止，直接退出，下次启动数据库需要进行恢复。
- 配置文件，在`$PGDATA/postgresql.conf`