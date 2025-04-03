package main

import (
	"fmt"
	"strings"
)

func isCharsOccurOnce(str string) bool {
	for _, c := range str {
		if strings.Count(str, string(c)) > 1 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isCharsOccurOnce("abc"))
	fmt.Println(isCharsOccurOnce("aabbcc"))
}
