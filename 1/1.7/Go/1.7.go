package main

import (
	"fmt"
)

type Color int

const (
	R Color = iota + 1
	G
	B
	A
)

type Pixel struct {
	R rune
	G rune
	B rune
	A rune
}

func rotateRight(Pic [][]Pixel) {
	N := len(Pic)
	for i := 0; i < N/2; i++ {
		for j := 0; j <= N/2; j++ {
			tmp := Pic[i][j]
			Pic[i][j] = Pic[N-1-j][i]
			Pic[N-1-j][i] = Pic[N-1-i][N-1-j]
			Pic[N-1-i][N-1-j] = Pic[j][N-1-i]
			Pic[j][N-1-i] = tmp
		}
	}
}
func printPic(Pic [][]Pixel, c Color) {
	for i := 0; i < len(Pic); i++ {
		for j := 0; j < len(Pic); j++ {
			switch c {
			case R:
				fmt.Print(string(Pic[i][j].R) + " ")
			case G:
				fmt.Print(string(Pic[i][j].G) + " ")
			case B:
				fmt.Print(string(Pic[i][j].B) + " ")
			case A:
				fmt.Print(string(Pic[i][j].A) + " ")
			}

		}
		fmt.Print("\n")
	}
	fmt.Print("\n")
}

func main() {
	picture := [][]Pixel{
		{{' ', 'O', ' ', ' '}, {' ', '*', ' ', ' '}, {'*', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', 'O', ' ', ' '}, {'*', 'O', '*', ' '}, {'*', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', '*', ' ', ' '}, {' ', '*', ' ', ' '}, {'*', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {'*', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', 'O', ' ', ' '}, {'*', 'O', ' ', ' '}, {'*', 'O', ' ', ' '}, {'*', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
	}

	printPic(picture, R)

	printPic(picture, G)

	rotateRight(picture)

	printPic(picture, R)

	printPic(picture, G)

	rotateRight(picture)

	printPic(picture, R)

	printPic(picture, G)

	rotateRight(picture)

	printPic(picture, R)

	printPic(picture, G)

	rotateRight(picture)

	printPic(picture, R)

	printPic(picture, G)

	picture = [][]Pixel{
		{{' ', 'O', ' ', ' '}, {'*', '*', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', 'O', ' ', ' '}, {' ', 'O', '*', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', '*', ' ', ' '}, {' ', '*', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
		{{' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}, {' ', 'O', ' ', ' '}},
	}
	printPic(picture, R)

	printPic(picture, G)

	rotateRight(picture)
	printPic(picture, R)

	printPic(picture, G)

}
