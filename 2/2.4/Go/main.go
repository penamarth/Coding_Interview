package main

func main() {
	L := NewPointerList()
	L.insert(3, 0)
	L.insert(5, L.end())
	L.insert(8, L.end())
	L.insert(5, L.end())
	L.insert(10, L.end())
	L.insert(2, L.end())
	L.insert(1, L.end())

	L.print()

	L.sortAround(5)

	L.print()
}
