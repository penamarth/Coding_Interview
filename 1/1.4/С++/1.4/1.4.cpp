#include <iostream>
#include <string>
#include <regex>
#include "generator.hpp"

tl::generator<std::string> all_perms(std::string elements) {
	if( elements.length() <= 1 ){
		co_yield elements;
	}
	else {
		for( auto perm : all_perms(elements.substr(1))) {
			for( int i = 0;  i < elements.length(); i++) {
				std::string res = perm.substr(0, i) + elements.substr(0, 1) + perm.substr(i);
				co_yield res;
			}
		}
	}
}

bool isPalindrome(std::string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if( s[i] != s[s.length() - 1 - i]){
			return false;
		}
	}
	return true;
}

bool isPalindromeAnagram(std::string s) {
	s = std::regex_replace(s, std::regex(" "), "");

	for(std::string permutation : all_perms(s)) {
		if( isPalindrome(permutation)) {
			std::cout << "Palindrome found: " + permutation << std::endl;
				return true;
		}
	}
	return false;
}

int main()
{
	std::cout << isPalindromeAnagram("ar") << std::endl;
	std::cout << isPalindromeAnagram("ara") << std::endl;
	std::cout << isPalindromeAnagram("raa") << std::endl;
	std::cout << isPalindromeAnagram("ar ") << std::endl;
	std::cout << isPalindromeAnagram("a ra") << std::endl;
	std::cout << isPalindromeAnagram("r aa") << std::endl;
	std::cout << isPalindromeAnagram("r ara") << std::endl;
}
