## 第8章 应用测试
- testing包需要与go test命令以及源代码中所有以`_test.go`后缀结尾的测试文件一同使用。
- 为了测试源代码，用户需要在测试文件中创建具有以下格式的测试函数，其中Xxx可以是任意字母以及数字的组合，但是首字符必须是大写的英文字母。

		func TestXxx(*testing.T) { ... }
- testing.T结构拥有几个非常有用的函数
	- Log -- 将给定的文本记录到错误日志里面，与`fmt.Println`类似
	- Logf -- 根据给定的格式，将给定的文本记录到错误日志里面，与`fmt.Printf`类似
	- Fail -- 将测试函数标记为“已失败”，但允许测试函数继续执行
	- FailNow -- 将测试函数标记为“已失败”并停止执行测试函数
	- 除了以上4个函数，还提供了一些便利函数(convenience function)
	
    	|     | Log | Logf |
        |-----|------|--------|
        |Fail | <font color="#00dd00">Error</font> | <font color="#00dd00">Errorf</font> |
        |FailNow | <font color="#00dd00">Fatal</font> | <font color="#00dd00">Fatalf</font> |