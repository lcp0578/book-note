## 第3章 字符串、向量和数组
- string表示可变长的字符序列。
- vector存放的是某种给定类型对象的可变长序列。
	- vector是一个类模板
	- 对于类模板来说，我们通过提供一些额外信息来指定模板到底实例化成什么样的类，需要提供哪些信息由模板决定。提供信息的方式总是这样的：即在模板名字后面跟一对尖括号，在括号内放上信息。
	
    		vector<int> ivec;
            vector<Sales_item> Sales_vec;
            vector<vector<string>> file;