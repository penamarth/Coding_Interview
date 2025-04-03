#include <iostream>
#include <algorithm>

bool isAnagram(std::string string1, std::string string2)
{
    if (string1.length() != string2.length())
    {
        return false;
    }

    for(char c : string1)
    {
        if (std::ranges::count(string1, c) != std::ranges::count(string2, c))
            return false;
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha << isAnagram("hello", "hell") << std::endl;
    std::cout << std::boolalpha << isAnagram("hello", "ehllo") << std::endl;
}
