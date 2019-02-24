## 第4章 处理请求
- 处理请求的示例

        package main

        import (
            "net/http"
            "fmt"
            "io/ioutil"
        )

        func headers(w http.ResponseWriter, r *http.Request){
            h := r.Header
            fmt.Fprintln(w, h)
            fmt.Fprintln(w, h["Accept-Encoding"])
        }

        func body(w http.ResponseWriter, r *http.Request){
            len := r.ContentLength
            body := make([]byte, len)
            r.Body.Read(body)
            fmt.Fprintln(w, string(body))
        }

        func process(w http.ResponseWriter, r *http.Request) {
            r.ParseForm()
            fmt.Fprintln(w, r.Form)
            fmt.Fprintln(w, r.MultipartForm)
        }

        func formValue(w http.ResponseWriter, r *http.Request){
            fmt.Fprintln(w, r.FormValue("key"))
            fmt.Fprintln(w, r.PostFormValue("key2"))
        }

        func file(w http.ResponseWriter, r *http.Request) {
            r.ParseMultipartForm(1024)
            fileHeader := r.MultipartForm.File["uploaded"][0]
            file, err := fileHeader.Open()
            if err == nil {
                data, err := ioutil.ReadAll(file)
                if err == nil  {
                    fmt.Fprintln(w, string(data))
                }
            }
        }

        func writeHtml(w http.ResponseWriter, r *http.Request) {
            str := `<html><body>Go Web</body></html>`
            w.Write([]byte(str))
        }

        func write501(w http.ResponseWriter, r *http.Request){
            w.WriteHeader(501)
            fmt.Fprintln(w, "no such service")
        }

        func write302(w http.ResponseWriter, r *http.Request) {
            w.Header().Set("Location", "https://baidu.com")
            w.WriteHeader(302)
        }

        func main() {
            server := http.Server{
                Addr: "127.0.0.1:8080",
            }
            http.HandleFunc("/headers", headers)
            http.HandleFunc("/body", body)
            http.HandleFunc("/process", process)
            server.ListenAndServe()
        }