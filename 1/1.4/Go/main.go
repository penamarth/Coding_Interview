package main

import (
	"fmt"
	"strings"
)

func all_perms(elements string) <-chan string {
	ch := make(chan string)
	go func() {
		if len(elements) <= 1 {
			ch <- elements
		} else {
			for perm := range all_perms(elements[1:]) {
				for i := 0; i < len(elements); i++ {
					ch <- perm[:i] + elements[0:1] + perm[i:]
				}
			}
		}
		close(ch)
	}()
	return ch
}

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func isPalindromeAnagram(s string) bool {
	s = strings.ReplaceAll(s, " ", "")

	for permutation := range all_perms(s) {
		if isPalindrome(permutation) {
			fmt.Println("Palindrome found: " + permutation)
			return true
		}
	}
	return false
}

func main() {
	fmt.Println(isPalindromeAnagram("ar"))
	fmt.Println(isPalindromeAnagram("ara"))
	fmt.Println(isPalindromeAnagram("raa"))
	fmt.Println(isPalindromeAnagram("ar "))
	fmt.Println(isPalindromeAnagram("a ra"))
	fmt.Println(isPalindromeAnagram("r aa"))
	fmt.Println(isPalindromeAnagram("r ara"))
}
