package main

import (
	"fmt"
)

type PointerList struct {
	first, current  *Cell
	currentPosition int
	elementCount    int
}

func NewPointerList() *PointerList {
	L := &PointerList{}
	L.elementCount = 0
	L.currentPosition = -1
	L.first = nil
	L.current = nil
	return L
}

func (L *PointerList) isEmpty() bool {
	return L.elementCount == 0
}

func (L *PointerList) insert(value int, position int) {
	if L.isEmpty() {
		L.elementCount++
		L.first = new(Cell)
		L.current = L.first

		L.currentPosition = 0
		L.current.value = value
		L.current.next = nil

	} else if position >= L.end() {

		L.current = L.first
		for L.current.next != nil {
			L.current = L.current.next
		}
		L.elementCount++
		L.current.next = new(Cell)
		L.current.next.next = nil
		L.current = L.current.next
		L.current.value = value
		L.currentPosition = L.end()

	} else {
		newCell := new(Cell)
		newCell.value = value
		L.current = L.first
		L.currentPosition = 0
		for L.current.next != nil {
			if L.currentPosition == position {
				break
			}
			L.current = L.current.next
			L.currentPosition++
		}
		newCell.next = L.current.next
		L.current.next = newCell
		L.current = newCell
		L.currentPosition++
		L.elementCount++
	}

}
func (L *PointerList) locate(value int) int {
	L.current = L.first
	L.currentPosition = 0
	for L.current != nil {
		if L.current.value == value {
			return L.currentPosition
		}
		L.current = L.current.next
		L.currentPosition++
	}
	return L.end()

}
func (L *PointerList) retrieve(position int) int {
	L.current = L.first
	L.currentPosition = 0
	for L.current != nil {
		if L.currentPosition == position {
			return L.current.value
		}
		L.current = L.current.next
		L.currentPosition++
	}
	return -1
}

func (L *PointerList) print() {
	if !L.isEmpty() {
		for i := 0; i < L.end(); i++ {
			fmt.Print(L.retrieve(i), " ")
		}
	}
	fmt.Print("\n")
}

func (L *PointerList) del(position int) {
	if position == 0 {
		L.current = L.first.next
		L.first = L.current
	} else if position >= L.end() {
		return
	} else {
		L.current = L.first
		L.currentPosition = 0
		for L.current != nil {
			if L.currentPosition == position-1 {
				if L.current.next == nil {

					L.currentPosition--
					L.elementCount--
					L.current.next = nil
					return
				} else {

					L.elementCount--
					L.current.next = L.current.next.next
					return
				}
			}
			L.current = L.current.next
			L.currentPosition++
		}
	}
}
func (L *PointerList) end() int {
	return L.elementCount
}

func (L *PointerList) getCurrentPosition() int {
	return L.currentPosition
}

func (L *PointerList) retrieveFromEnd(k int) int {
	L.current = L.first
	L.currentPosition = 0
	for L.current != nil {
		if L.currentPosition+k == L.end()-1 {
			return L.current.value
		}
		L.current = L.current.next
		L.currentPosition++
	}
	return -1
}

func (L *PointerList) deleteCenter() {
	L.del(L.elementCount / 2)
}

func (L *PointerList) sortAround(x int) {
	k := 0
	l := 0
	for k < L.end() && l < L.end() {
		tmp := L.retrieve(L.end() - 1)

		if tmp < x {
			L.del(L.end() - 1)
			L.insert(tmp, k)
			k++
			l++
		} else if tmp > x {
			L.del(L.end() - 1)
			l++
			L.insert(tmp, l)
		} else {
			l++
		}
	}
}
