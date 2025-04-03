bool isAnagram(String string1, String string2)
{
    if (string1.Length != string2.Length)
    {
        return false;
    }

    foreach (char c in string1)
    {
        if (string1.Count(x => x == c) != string2.Count(x => x == c))
            return false;
    }
    return true;
}

Console.WriteLine(isAnagram("hello", "hell"));
Console.WriteLine(isAnagram("hello", "ehllo"));
