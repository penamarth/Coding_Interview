package main

import (
	"fmt"
	"strings"
)

func isAnagram(string1 string, string2 string) bool {
	if len(string1) != len(string2) {
		return false
	}

	for _, c := range string1 {
		if strings.Count(string1, string(c)) != strings.Count(string2, string(c)) {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAnagram("hello", "hell"))
	fmt.Println(isAnagram("hello", "ehllo"))
}
