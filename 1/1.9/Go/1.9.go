package main

import (
	"fmt"
	"strings"
)

func isSubstring(str string, substring string) bool {
	if strings.Contains(str, substring) {
		return true
	} else {
		return false
	}
}

func isCiclicShift(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	return isSubstring(s2+s2, s1)
}
func main() {

	fmt.Print("waterbottle ", "erbottlewat ", isCiclicShift("waterbottle", "erbottlewat"), "\n")
	fmt.Print("Hello ", "oHell ", isCiclicShift("Hello", "oHell"), "\n")
	fmt.Print("Hello ", "Helloo ", isCiclicShift("Hello", "Helloo"), "\n")
	fmt.Print("Hello ", "Hoell ", isCiclicShift("Hello", "Hoell"), "\n")

}
