package main

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

	L.deleteCenter()

	L.print()
}
