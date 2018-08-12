## 第7章 Go Web服务
- SOAP和REST的简介
- XML
	- 解码
	
            type Post struct {
                XMLName xml.Name `xml:"post"`
                Id string `xml:"id,attr"`
                Content string `xml:"content"`
                Author Author `xml:"author"`
                Xml string `xml:",innerxml"`
                Comments []Comment `xml:"comments>comment"`
            }

            type Author struct {
                Id string `xml:"id,attr"`
                Name string `xml:",chardata"`
            }
            var post Post
            xml.Unmarshal(xmlData, &post)
            fmt.Println(post)

            decoder := xml.NewDecoder(xmlFile)
            for {
                t, err := decoder.Token()
                if err == io.EOF {
                    break
                }
                if err != nil {
                    fmt.Println("Error decoding XML into tokens:", err)
                    return
                }
                switch se := t.(type) {
                case xml.StartElement:
                    if se.Name.Local == "comment" {
                        var comment Comment
                        decoder.DecodeElement(&comment, &se)
                    }
                }
            }
	- 编码
	
    		package main
            import (
                "encoding/xml"
                "fmt"
                "io/ioutil"
            )

            type Post2 struct {
                XMLName xml.Name `xml:"post"`
                Id string `xml:"id,attr"`
                Content string `xml:"content"`
                Author Author `xml:"author"`
            }

            type Author struct {
                Id string `xml:"id,attr"`
                Name string `xml:",chardata"`
            }

            func main(){
                post := Post2 {
                    Id: "1",
                    Content: "hello lcp0578",
                    Author: Author {
                        Id: "2",
                        Name: "go web",
                    },
                }
                //output, err := xml.Marshal(&post)
                output, err := xml.MarshalIndent(&post, "", "\t")
                if err != nil {
                    fmt.Println("error marshalling to XML:", err)
                    return
                }
                //err = ioutil.WriteFile("post2.xml", output, 0644)
                err = ioutil.WriteFile("post2.xml", []byte(xml.Header + string(output)), 0644)
                if err != nil {
                    fmt.Println("Error writing XML to file:", err)
                    return
                }
            }
- JSON
	- 解码
	- 编码