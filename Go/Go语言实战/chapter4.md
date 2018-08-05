## 第四章 数组、切片和映射
- 数组  
	- 数组是一个长度固定的数据类型，用于存储一段具有相同类型的元素的的连续块。
	- 占用内存是连续分配的
	- 声明数组时需要指定内部存储的数据的类型，以及需要存储的元素的数量。一旦声明，数组里存储的数据类型和数组长度就都不能改变了。
	
			var arr [5]int //声明并设为零值
			arr := [5]int{10, 20, 30, 40, 50} 
			arr := [...]int{10, 20, 30, 40 ,50}
			arr := [5]*int{0: new(int), 1: new(int)} // 指针数组
			*arr[0] = 10
			*arr[1] = 2
			// 多维数组
			var array [4][2]int
	- 根据内存和性能来看，在函数间传递数组是一个开销很大的操作。在函数传递变量时，总是以值的方式传递的。
- 切片
	- 切片是一个很小的对象，对底层数组进行了抽象，并提供相关的操作方法。
	- 指向底层数组的指针、切片访问元素的个数（即长度）和切片允许增长到的元素个数（即容量）
	- 创建和初始化
	
    		// make创建
    		slice := make([]string, 5) //创建一个字符切片，未指定容量，长度和容量都是5
            slice := make([]int, 3, 5) //创建一个整型切片，长度3，容量5
            // 字面变量
            slice := []int{10, 20, 30}
            slice := []string{99:""} //使用空字符串初始化第100个元素
            // PS: 如果在[]运算符里指定了一个值，那么创建的就是数组而不是切片。
            var slice []int //创建nil切片
            slice := make([]int, 0) // make创建空的整型切片
            slice := []int{} //字面变量创建空的整型切片
            
            // 使用切片创建切片
            slice := []int{10, 20, 30, 40, 50}
            newSlice := slice[1:3] //长度为2，容量为4，他们共享同一段底层数组
            // PS： 如果一个切片修改了该底层数组的共享部分，另外一个切片也能感知到。
            twoSlice := slice[1:3:3] //长度为2，容量为2，如果此时调用append函数，则会与原有底层数组分离。
	- 计算长度和容量
	
    	对于底层数组容量是k的切片slice[i:j]来说：
        - 长度: j - i
        - 容量: k - i
    - 函数append总会增加新切片的长度，而容量有可能会改变，也可能不会改变，这取决于被操作的切片的可用容量。
    - 一个切片追加到另一个切片
    
    		s1 := []int{1, 2}
            s2 := []int{3, 4}
            fmt.Printf("%v\n", append(s1, s2...))
            // output[1, 2, 3, 4]
- 映射(map)
	- 映射是一种数据结构，用于存储一系列无序的键值对。
	- 无序的原因是映射的实现使用了散列表。
	- 创建和初始化
	
    		dict := make(map[string]int) //创建一个映射，键类型是string，值类型是int
            color := map[string]string{"Red": "#da1337", "Orange": "#e95a22"}
            // 创建一个映射，使用字符串切片作为值
            dict := map[int][]string}{}
            // 创建一个空映射
            colors := map[string]string{}
            colors["Red"] = "#da1337"
            // 创建一个nil映射
            var colors = map[string]string
	- 使用映射
	
    		// 获取键Blue对应的值
            value, exists := colors["Blue"]
            if exists {
            	fmt.Println(value)
            }
            // 当键不存在时，会返回该值对应的类型的零值
            value := colors["Blue"]
            if value != "" {
            	fmt.Println(value)
            }
            // 使用range迭代映射
            for key,value := range colors {
            	fmt.Printf("Key: %s Value: %s\n", key, value)
            }
            // 删除一项
            delete(colors, "Coral")
	- 在函数间传递映射  
	在函数间传递映射并不会制造出该映射的一个副本。