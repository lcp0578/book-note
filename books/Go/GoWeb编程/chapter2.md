## 第2章 ChitChat论坛
- multiplexer 多路复用器
- net/http与html/template包的基础使用

		package main
        import (
            "net/http"
            "html/template"
        )

        func main() {
            mux := http.NewServeMux()
            files := http.FileServer(http.Dir("/public"))
            mux.Handle("/static/", http.StripPrefix("/static/", files))
            mux.HandleFunc("/", index)
            server := &http.Server{
                Addr: "0.0.0.0:8080",
                Handler: mux,
            }

            server.ListenAndServe()
        }

        func index(w http.ResponseWriter, r *http.Request) {
            files := []string{
                "templates/layout.html",
                "templates/navbar.html",
                "templates/index.html",
            }

            templates := template.Must(template.ParseFiles(files...))
            threads, err := data.Threads();
            if err == nil {
                templates.ExecuteTemplate(w, "layout", threads)
            }
        }