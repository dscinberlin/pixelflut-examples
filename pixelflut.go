package main

import "net"
import "fmt"

func main() {

	// connect to this socket
	conn, err := net.Dial("tcp", "35.234.105.190:1234")
	if err != nil {
		fmt.Println(err)
	}
	for x := 0; x < 1920; x++ {
		for y := 0; y < 1080; y++ {
			fmt.Fprintf(conn, "CC %d %d 0000FF\n", x, y)
		}
	}
}