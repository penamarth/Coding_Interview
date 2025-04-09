#include <iostream>
#include <string>

std::string compressString(std::string s) {
    std::string compressed = "";
    int counter = 1;
    std::string prev_c = "";
    for (char c : s) {
        if (c == prev_c[0])
            counter += 1;
        else {
            compressed += prev_c + std::to_string(counter);
            counter = 1;
            prev_c = c;
        }
    }
    compressed +=  s.back() + std::to_string(counter);
    compressed = compressed.substr(1);

    if (compressed.length() >= s.length())
        return s;
    else
        return compressed;
}

int main()
{
    std::cout << compressString("abc") << std::endl;
    std::cout << compressString("aabc") << std::endl;
    std::cout << compressString("Aabc") << std::endl;
    std::cout << compressString("aaaabbbcc") << std::endl;
    std::cout << compressString("aaAabbBcc") << std::endl;
    std::cout << compressString("aaAabbbBcc") << std::endl;
    std::cout << compressString("aaAabbbbBcc") << std::endl;
    std::cout << compressString("aaAabbbbbBcc") << std::endl;
    std::cout << compressString("aaAabbbbbbBcc") << std::endl;
}

