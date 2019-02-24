## 第5章 内容展示
- 模板引擎
	- 无逻辑模板引擎(logic-less template engine)
	- 嵌入逻辑的模板引擎(embedded logic template engine)
- 标准库
	- text/template
	- html/template
	
    		func process(w http.ResponseWriter, r *http.Request){
                t, _ := template.ParseFiles("tmpl.html")
                t, _ = template.ParseGlob("*.html")
                t = template.Must(template.ParseFiles("tmpl.html"))
                t.Execute(w, "hello word")
            }

- 模板动作
	- 条件动作

			{{ if arg }}
            some content
            {{ end }}
            
            {{ if arg }}
            come content
            {{ else }}
            other content
            {{ end }}
	- 迭代动作

			{{ range array }}
            element {{ . }}
            {{ end }}
            //带有备选结构的迭代动作
            {{ range . }}
            	{{ . }}
            {{ else }}
            Nothing
            {{ end }}
	- 设置动作

			{{ with "world" }}
            Now dot is {{ . }}
            {{ end }}
	- 包含动作

			{{ template "menu.html"}}
- 参数、变量和管道
	- 参数是模板中的一个值
	- 变量
	
    		{{ range $key, $value := . }}
            The key is {{ $key }} and the value is {{ $value }}
            {{ end }}
    - 管道
    
    		{{ 12.3456 | printf "%.2f"}}
- 自定义函数

			funcMap := template.FuncMap{ "fdate": formatDate}
            t := template.New("tmpl.html).Funcs(funcMap)
            //通过管道使用自定义函数
            {{ . | fdate}}
            // 通过传递参数的方式
            {{ fdate . }}
- 上下文感知（content aware）
	- 根据动作所在的位置，同样的内容输入将产生不同的输出结果
- 不对HTML进行转义

        func process(w http.ResponseWriter, r *http.Request){
            t = template.Must(template.HTML("tmpl.html"))
            t.Execute(w, "hello word")
        }