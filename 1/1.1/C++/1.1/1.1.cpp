#include <iostream>
#include <algorithm>
#include <format>

bool isCharsOccurOnce(std::string str) {
    for(char c : str) {
        if (std::ranges::count(str, c) > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha << isCharsOccurOnce("abc") << std::endl;
    std::cout << std::boolalpha << isCharsOccurOnce("aabbcc") << std::endl;
}

