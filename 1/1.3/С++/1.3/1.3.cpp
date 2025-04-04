#include <iostream>
#include <regex>

std::string URIWhitespace(std::string s)
{
    s = std::regex_replace(s, std::regex("\s+$"), "");
    s = std::regex_replace(s, std::regex("^\s+"), "");
    s = std::regex_replace(s, std::regex(" "), "%20");
    return s;
}

int main()
{
    std::cout << URIWhitespace("NoSpace") << std::endl;
    std::cout << URIWhitespace("With Space") << std::endl;
    std::cout << URIWhitespace("Many Spaces In Line") << std::endl;
    std::cout << URIWhitespace(" StartWithSpace") << std::endl;
    std::cout << URIWhitespace("EndWithSpace ") << std::endl;
    std::cout << URIWhitespace(" Start With Space And Multiple Spaces") << std::endl;
    std::cout << URIWhitespace("End With Space And Multiple Spaces ") << std::endl;
    std::cout << URIWhitespace(" All In Spaces ") << std::endl;
}
