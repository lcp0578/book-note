## 第5章 Model/View结构
### 数据模型
- `QAbstractItemModel`
	- `QAbstractListModel`
		- `QStringListModel`用于处理字符串列表数据的数据模型类
	- `QAbstractProxyModel`
		- `QSortFilterProxyModel`与其他数据模型结合，提供排序和过滤功能的数据模型类
	- `QAbstractTableModel`
		- `QSqlQueryModel` 用于数据库SQL查询结果的数据模型类
			- `QSqlTableModel`用于数据块的一个数据表的数据模型类
				- `QSqlRelationTableModel`用于关系型数据表的数据模型类
	- `QStandardItemModel`标准的基于项数据模型类，每个项数据可以是任何数据类型
	- `QFileSystemModel`计算机上文件系统的数据模型类
### 视图组件
- QListView:用于显示单列的列表数据，适用于一维数据的操作。
- QTreeView:用于显示树状结构数据，适用于树状结构数据的操作。
- QTableView:用于显示表格状数据，适用于二维表格型数据的操作。
- QColumnView:用多个QListView显示树状层次结构，树状结构的一层用一个QListView显示。
- QHeaderView:提供行表头或列表头的视图组件，如QTableView的行表头和列表头。
### QFileSystemModel
### QStringListModel
### QStandardItemModel
