## 第五章 Go语言的类型系统
- 值的类型给编译器提供两部分信息：
	- 第一部分：需要分配多少内存给这个值（即值的规模）
	- 第二部分：这段内存表示什么
- 有些类型的内部表示与编译代码的机器的体系结构有关。
- 对数值类型来说，零值是0；对于字符串来说，零值是空字符串；对于布尔类型，零值是false。
- 声明一个结构类型
	
    	type user struct {
        	name string
            email string
            ext int
            privileged bool
        }
        // 声明user类型的变量
        var bill user
        //使用结构的字面变量来声明一个结构类型的变量
        lisa := user{
        	name: "Lisa",
            email: "Lisa@email.com",
            ext: 123,
            privileged: true,
        }
        //不使用字段名，创建结构类型的值（值的顺序很重要）
        lisa := user{"Lisa", "Lisa@email.com", 123, true}
        // 使用其他的结构类型声明字段
        type admin struct {
        	person user
            level string
        }
- 方法  
	- 方法能给用户定义的类型添加新的行为。
    
            // notify使用值接收者实现了一个方法
            func (u user) notify{

            }
            // changeEmail使用指针接受者实现了一个方法
            func (u *user) changeEmail(email string) {
                u.email = email
            }
	- 如果使用值接收声明方法，调用时会使用这个值的一个副本来执行；而指针接受者使用实际值来调用方法。
- 类型的本质
	- 内置类型：数值类型、字符串类型和布尔类型
	- 引用类型：切片、映射、通道和函数类型。
	- 结构类型：用来描述一组数值，这组数组的本质既可以是原始的，也可以是非原始的。
- 接口
	- 多态是指代码可以根据类型的具体实现才去不同行为的能力。
	- 方法集
	
    		values             Methods Receivers
            -------------------------------------
            T                   （t T）
            *T                   (t T) and (t *T)
       - T类型的值的方法集只包含值接收者声明的方法。
       - 而指向T类型的指针的方法集既包含值接收者声明的方法，也包含指针接收者声明的方法。
       - 因为并不是总能获取一个值的地址，所以值的方法集只包括了使用值接收者实现的方法。
- 嵌入类型 
       