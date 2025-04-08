package main

import (
	"fmt"
	"strings"
)

func areOneStepAway(s1 string, s2 string) bool {
	if s1 == s2 {
		return true
	}
	if len(s1) == len(s2) {
		count := 0
		for i, c := range []rune(s1) {
			if c != ([]rune(s2))[i] {
				count = count + 1
			}
		}
		if count == 1 {
			return true
		} else {
			return false
		}
	} else if len(s1)-len(s2) == 1 {
		for _, c := range []rune(s2) {
			if !strings.Contains(s1, string(c)) {
				return false
			}
		}
		return true
	} else if len(s2)-len(s1) == 1 {
		for _, c := range []rune(s1) {
			if !strings.Contains(s2, string(c)) {
				return false
			}
		}
		return true
	}
	return false
}

func main() {
	fmt.Println(areOneStepAway("hello", "hello"))
	fmt.Println(areOneStepAway("hello", "hell"))
	fmt.Println(areOneStepAway("hello", "help"))
	fmt.Println(areOneStepAway("hellu", "hello"))
	fmt.Println(areOneStepAway("helloo", "hello"))
	fmt.Println(areOneStepAway("hellooo", "hello"))
}
