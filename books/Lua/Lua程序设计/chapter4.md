## 4 字符串
- Lua语言中字符串是不可变值(immutable value)

		$ cat gsub.lua
        a = "one string"
        b = string.gsub(a, "one", "another")
        print(a)
        print(b)
        $ lua gsub.lua
        one string
        another string
- 长度操作符(length operator) (#)
- 连接操作符（..）

		$ cat string.lua
		a = "hello"
        print(#a)
        print(#"good bye")

        print("hello" .. "world")
        print("result is" .. 3)
        b = a .. "world"
        print(a)
        print(b)
        $ lua string.lua
        5
        8
        helloworld
        result is3
        hello
        helloworld
- 可以使用一对双引号或单引号来声明字符串常量(literal string)
- 多行字符串
	
    	page = [[
        	<html>
            	<body>
                </body>
            </html>
        ]]
- 显示地将一个字符串转换成数值`tonumber`
- 测试

		$ lua
        Lua 5.3.5  Copyright (C) 1994-2018 Lua.org, PUC-Rio
        > string.rep("abc", 3)
        abcabcabc
        > string.reverse("A Long Line!")
        !eniL gnoL A
        > string.lower("A Long Line!")
        a long line!
        > string.upper("A Long Line!")
        A LONG LINE!
        > s = "[in brackets]"
        > string.sub(s, 2, -2)
        in brackets
        > string.sub(s, 1, 1)
        [
        > string.sub(s, -1, -1)
        ]
        >
        > print(string.char(97))
        a
        > i = 99;print(string.char(i, i+1, i+2))
        cde
        > print(string.byte("abc"))
        97
        > print(string.byte("abc", 2))
        98
        > print(string.byte("abc", -1))
        99
        >
        > print(string.byte("abc", 1, 2))
        97	98
        >
        > string.format("x = %d, y = %d", 10, 20)
        x = 10, y = 20
        > string.format("x = %x", 200)
        x = c8
        > string.format("x = 0x%X", 200)
        x = 0xC8
        > string.format("x = %f", 200)
        x = 200.000000
        > tag, title = "h1", "a title"
        > string.format("<%s>%s</%s>", tag, title, tag)
        <h1>a title</h1>
        >
        > string.format("pi = %.4f", math.pi)
        pi = 3.1416
        > d = 25; m = 6; y = 2019
        > string.format("%02d/%02d/%04d", d, m, y)
        25/06/2019
        >
        > string.find("hello world", "wor")
        7	9
        > string.find("hello world", "war")
        nil
        >
        > string.gsub("hello world", "l", ".")
        he..o wor.d	3
        > string.gsub("hello world", "ll", ".")
        he.o world	1
        > string.gsub("hello world", "a", ".")
        hello world	0
        >
- Unicode编码
	- 函数`reverse`,`upper`,`lower`,`byte`,`char`不适用与UTF-8字符串
	- `string.format`、`string.rep`适用UTF-8字符串（格式选项`%c`除外）
	- 函数`string.len`,`string.sub`可以用于UTF-8字符串，其中索引以字节为单位而不是以字符为单位。
	- `utf8.len()`
	- `utf8.char()`和`utf8.codepoint`
	- `utf8.codes`