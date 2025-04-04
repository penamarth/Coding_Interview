package main

import (
	"fmt"
	"strings"
)

func URIWhitespace(s string) string {
	return strings.ReplaceAll(strings.TrimSpace(s), " ", "%20")
}

func main() {
	fmt.Println(URIWhitespace("NoSpace"))
	fmt.Println(URIWhitespace("With Space"))
	fmt.Println(URIWhitespace("Many Spaces In Line"))
	fmt.Println(URIWhitespace(" StartWithSpace"))
	fmt.Println(URIWhitespace("EndWithSpace "))
	fmt.Println(URIWhitespace(" Start With Space And Multiple Spaces"))
	fmt.Println(URIWhitespace("End With Space And Multiple Spaces "))
	fmt.Println(URIWhitespace(" All In Spaces "))
}
