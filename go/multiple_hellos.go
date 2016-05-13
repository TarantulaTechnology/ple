package main

import "fmt"

func generateMessages(ch chan string, n int) {
	for i := 0; i < n; i++ {
		ch <- "Hello"
	}
	close(ch)
}

func main() {
	messages := make(chan string)
	go generateMessages(messages, 3)
	for message := range messages {
		fmt.Println(message)
	}
}
