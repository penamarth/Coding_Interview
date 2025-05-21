#include <iostream>

bool isSubstring(std::string string, std::string substring) {
    return string.contains(substring);
}

bool isCiclicShift(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    return isSubstring(s2 + s2, s1);
}

int main()
{
    std::cout << "waterbottle " << "erbottlewat " << std::boolalpha << isCiclicShift("waterbottle", "erbottlewat") << std::endl;
    std::cout << "Hello " << "oHell " << std::boolalpha << isCiclicShift("Hello", "oHell") << std::endl;
    std::cout << "Hello " << "Helloo " << std::boolalpha << isCiclicShift("Hello", "Helloo") << std::endl;
    std::cout << "Hello " << "Hoell " << std::boolalpha << isCiclicShift("Hello", "Hoell") << std::endl;
}
