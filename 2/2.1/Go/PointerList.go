package main

import (
	"fmt"
)

type PointerList struct {
	first, current, last *Cell
	currentPosition      int
	elementCount         int
}

func NewPointerList() *PointerList {
	L := &PointerList{}
	L.elementCount = 0
	L.currentPosition = -1
	L.first = nil
	L.current = nil
	L.last = nil
	return L
}

func (L *PointerList) isEmpty() bool {
	return L.elementCount == 0
}

func (L *PointerList) insert(value int, position int) {
	if L.isEmpty() {
		L.elementCount++
		L.first = new(Cell)
		L.last = L.first
		L.current = L.last
		L.currentPosition = 0
		L.current.value = value
		L.current.next = nil
		L.current.previous = nil
	} else if position >= L.end() {
		L.current = L.last
		L.currentPosition = L.end()
		L.last = new(Cell)
		L.last.value = value
		L.last.next = nil
		L.last.previous = L.current
		L.current.next = L.last
		L.elementCount++
		L.current = L.last
	} else {
		newCell := new(Cell)
		newCell.value = value
		newCell.previous = L.current
		newCell.next = L.current.next
		L.current.next.previous = newCell
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
			fmt.Print(L.retrieve(i))
		}
	}
	fmt.Print("\n")
}

func (L *PointerList) del(position int) {
	if position == 0 {
		L.current = L.first.next
		L.first = L.current
	} else {
		L.current = L.first
		L.currentPosition = 0
		for L.current != nil {
			if L.currentPosition == position {
				if L.current.next == nil {
					L.current = L.current.previous
					L.currentPosition--
					L.elementCount--
					L.current.next = nil
					return
				} else {
					L.current.next.previous = L.current.previous
					L.current.previous.next = L.current.next
					L.elementCount--
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
