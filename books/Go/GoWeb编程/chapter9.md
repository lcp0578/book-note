##  第9章 发挥Go的并发优势
- 并发指的是同时处理多项任务，而并行是指的同时执行多项任务。
- goroutine对线程的多路复用。
- WaitGroup等待组

        package main
        import (
            "sync"
            "time"
            "fmt"
        )

        func printNumber(wg *sync.WaitGroup){
            for i := 0; i< 10; i++{
                time.Sleep(1 * time.Microsecond)
                fmt.Printf("%d", i)
            }
            wg.Done()
        }

        func printLetters(wg *sync.WaitGroup){
            for i := 'A'; i < 'A' + 10; i++ {
                time.Sleep(1 * time.Microsecond)
                fmt.Printf("%c", i)
            }
            wg.Done()
        }

        func main(){
            var wg sync.WaitGroup
            wg.Add(2)
            go printNumber(&wg)
            go printLetters(&wg)
            wg.Wait()
        }