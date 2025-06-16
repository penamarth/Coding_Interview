package main

import (
	"fmt"
)

func main() {
	L := NewPointerList()
	L.insert(1, 0)
	L.insert(2, L.end())
	L.insert(3, L.end())
	L.insert(4, L.end())
	L.insert(5, L.end())
	L.insert(6, L.end())
	L.insert(7, L.end())

	L.print()

	fmt.Println(L.retrieveFromEnd(0))
	fmt.Println(L.retrieveFromEnd(1))
	fmt.Println(L.retrieveFromEnd(2))
	fmt.Println(L.retrieveFromEnd(3))
	fmt.Println(L.retrieveFromEnd(4))
	fmt.Println(L.retrieveFromEnd(5))
	fmt.Println(L.retrieveFromEnd(6))
	fmt.Println(L.retrieveFromEnd(7))
}
