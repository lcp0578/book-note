## 第四章 mysql、mysqladmin和mysqldump

- 创建数据库
	
		mysqladmin -u root -p create dbname
		Password: *****
- 删除数据库

		mysqladmin -u root -p drop dbname
		Password: *****
- 修改密码

		mysqladmin -u root -p password "new password"
		Password: old password
- 备份数据库

		mysqldump -u root -p dbname [tablename] > backup.sql
		Password: ****
- 导入备份数据库
		
		mysql -u root -p dbname < backup.sql
		Password: ****
		