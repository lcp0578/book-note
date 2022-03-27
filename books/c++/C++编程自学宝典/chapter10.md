## 第10章 诊断和调试
- 条件编译

		#ifdef TEST
			cout << "TEST defined" << endl;
		#else
			cout << "TeST not defined" << endl;
		#endif
		
		#if TEST < 0
			cout << "negative " << endl;
		#elif TEST > 0
			coun << "positive " << endl;
		#else
			cout << "zero or undefined << " endl;
		#endif
- pragma指令
- 添加通知消息
- 调试程序的编译器开关
- 预处理器标识符
- 生成诊断信息
- 断言
#### C++异常