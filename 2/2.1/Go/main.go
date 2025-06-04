package main

func purge(L List) {
	var p, q int
	p = 0
	for p != L.end() {
		q = p + 1
		for q != L.end() {
			if L.retrieve(p) == L.retrieve(q) {
				L.del(q)
			} else {
				q++
			}
		}
		p++
	}
}

func main() {
	L := NewPointerList()
	L.insert(1, 0)
	L.insert(2, L.end())
	L.insert(2, L.end())
	L.insert(3, L.end())

	L.print()
	purge(L)

	L.print()

	L = new(PointerList)
	L.insert(1, 0)
	L.insert(1, L.end())
	L.insert(2, L.end())
	L.insert(3, L.end())

	L.print()
	purge(L)

	L.print()

	L = new(PointerList)
	L.insert(1, 0)
	L.insert(2, L.end())
	L.insert(3, L.end())
	L.insert(3, L.end())

	L.print()
	purge(L)

	L.print()
}
