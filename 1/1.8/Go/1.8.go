package main

import (
	"fmt"
	"maps"
	"math/rand"
	"strconv"
)

func removeNills(matrix *[][]int) {

	rowsToDelete := make(map[int]bool)
	colsToDelete := make(map[int]bool)

	for i := 0; i < len(*matrix); i++ {
		for j := 0; j < len((*matrix)[0]); j++ {
			if (*matrix)[i][j] == 0 {
				rowsToDelete[i] = true
				colsToDelete[j] = true
			}
		}
	}
	for len(rowsToDelete) > 0 {
		var x int
		for k := range maps.Keys(rowsToDelete) {
			x = k
			break
		}

		*matrix = append((*matrix)[:x], (*matrix)[x+1:]...)

		delete(rowsToDelete, x)

		newRowsToDelete := make(map[int]bool)
		for row, _ := range rowsToDelete {
			if row > x {
				newRowsToDelete[row-1] = true
			} else {
				newRowsToDelete[row] = true
			}
		}
		rowsToDelete = newRowsToDelete

	}

	for len(colsToDelete) > 0 {
		var y int
		for k := range maps.Keys(colsToDelete) {
			y = k
			break
		}

		for i := 0; i < len(*matrix); i++ {
			(*matrix)[i] = append((*matrix)[i][:y], (*matrix)[i][y+1:]...)
		}

		delete(colsToDelete, y)

		newColsToDelete := make(map[int]bool)

		for col, _ := range colsToDelete {
			if col > y {
				newColsToDelete[col-1] = true
			} else {
				newColsToDelete[col] = true
			}
		}
		colsToDelete = newColsToDelete
	}

}

func printMatrix(matrix [][]int) {

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			fmt.Print(strconv.Itoa(matrix[i][j]) + " ")
		}
		fmt.Print("\n")
	}
	fmt.Print("\n")
}

func main() {

	N := 5
	M := 10

	var matrix [][]int

	for i := 0; i < N; i++ {
		matrix = append(matrix, []int{})
		for j := 0; j < M; j++ {
			matrix[i] = append(matrix[i], rand.Intn(10))
		}
	}

	printMatrix(matrix)
	removeNills(&matrix)
	printMatrix(matrix)

}
