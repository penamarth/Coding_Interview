package main

type List interface {
	isEmpty() bool
	insert(value int, position int)
	locate(value int) int
	retrieve(position int) int
	print()
	del(position int)
	end() int
	getCurrentPosition() int
}
