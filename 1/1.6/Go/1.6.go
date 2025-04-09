package main

import (
	"fmt"
	"strconv"
)

func compressString(s string) string {
	compressed := ""
	counter := 1
	prev_c := ""
	for _, c := range []rune(s) {
		if string(c) == prev_c {
			counter += 1
		} else {
			compressed = compressed + prev_c + strconv.Itoa(counter)
			counter = 1
			prev_c = string(c)
		}
	}
	compressed += string(s[len(s)-1]) + strconv.Itoa(counter)
	compressed = compressed[1:]

	if len(compressed) >= len(s) {
		return s
	} else {
		return compressed
	}
}

func main() {
	fmt.Println(compressString("abc"))
	fmt.Println(compressString("aabc"))
	fmt.Println(compressString("Aabc"))
	fmt.Println(compressString("aaaabbbcc"))
	fmt.Println(compressString("aaAabbBcc"))
	fmt.Println(compressString("aaAabbbBcc"))
	fmt.Println(compressString("aaAabbbbBcc"))
	fmt.Println(compressString("aaAabbbbbBcc"))
	fmt.Println(compressString("aaAabbbbbbBcc"))
}
