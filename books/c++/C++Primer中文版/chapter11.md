## 第11章 关联容器
#### 关联容器类型
- 按关键字有序保存元素
	- `map` 关联数组；保存关键字-值对
	- `set` 关键字即值，即只保存关键字的容器
	- `multimap` 关键字可重复出现的map
	- `multiset` 关键字可重复出现的set
- 无序集合
	- `unordered_map` 用哈希函数组织的map
	- `unordered_set` 用哈希函数组织的set
	- `unordered_multimap` 哈希组织的map;关键字可以重复出现
	- `unordered_multiset` 哈希组织的set;关键字可以重复出现
#### 关联容器概述
- `pair`类型
#### 关联容器操作

set<string>::value_type v1;//v1是一个string
set<string>::key_type v2;//v2是一个string
map<string, int>::value_tpe v3;//v3是一个pair<const string，int>
map<string, int>::key_type v4; //v4是一个string
map<string, int>::mapped_type v5; //v5是一个int