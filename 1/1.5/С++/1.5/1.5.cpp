#include <iostream>
#include <string>

bool areOneStepAway(std::string s1, std::string s2)
{
    if (s1 == s2)
        return true;

    if (s1.length() == s2.length())
    {
        int count = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                count += 1;
            }
        }
        if (count == 1)
            return true;
        else
            return false;
    }
    else if (s1.length()- s2.length() == 1)
    {
        for(char c : s2)
        {
            if (!s1.contains(c))
                return false;
        }
        return true;
    }
    else if (s2.length() - s1.length() == 1)
    {
        for(char c : s1)
        {
            if (!s2.contains(c))
                return false;
        }
        return true;
    }
    return false;
}

int main()
{
    std::cout << areOneStepAway("hello", "hello") << std::endl;
    std::cout << areOneStepAway("hello", "hell") << std::endl;
    std::cout << areOneStepAway("hello", "help") << std::endl;
    std::cout << areOneStepAway("hellu", "hello") << std::endl;
    std::cout << areOneStepAway("helloo", "hello") << std::endl;
    std::cout << areOneStepAway("hellooo", "hello") << std::endl;
}