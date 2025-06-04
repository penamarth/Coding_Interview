package main

type Cell struct {
	value          int
	previous, next *Cell
}
