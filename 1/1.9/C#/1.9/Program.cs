using System;
bool isSubstring(String s, String substring)
{
    return s.Contains(substring);
}

bool isCiclicShift(String s1, String s2)
{
    if (s1.Length != s2.Length)
    {
        return false;
    }
    return isSubstring(s2 + s2, s1);
}

Console.WriteLine("waterbottle " + "erbottlewat " + isCiclicShift("waterbottle", "erbottlewat").ToString());
Console.WriteLine("Hello " + "oHell " + isCiclicShift("Hello", "oHell").ToString());
Console.WriteLine("Hello " + "Helloo " + isCiclicShift("Hello", "Helloo").ToString());
Console.WriteLine("Hello " + "Hoell " + isCiclicShift("Hello", "Hoell").ToString());
