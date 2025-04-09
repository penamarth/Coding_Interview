bool areOneStepAway(string s1, string s2)
{
    if (s1 == s2)
        return true;

    if (s1.Length == s2.Length)
    {
        int count = 0;

        for (int i = 0; i < s1.Length; i++)
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
    else if (s1.Length - s2.Length == 1)
    {
        foreach (char c in s2)
        {
            if (!s1.Contains(c))
                return false;
        }
        return true;
    }
    else if (s2.Length - s1.Length == 1)
    {
        foreach (char c in s1)
        {
            if (!s2.Contains(c))
                return false;
        }
        return true;
    }
    return false;
}

Console.WriteLine(areOneStepAway("hello", "hello"));
Console.WriteLine(areOneStepAway("hello", "hell"));
Console.WriteLine(areOneStepAway("hello", "help"));
Console.WriteLine(areOneStepAway("hellu", "hello"));
Console.WriteLine(areOneStepAway("helloo", "hello"));
Console.WriteLine(areOneStepAway("hellooo", "hello"));
