bool isCharsOccurOnce(string str){
    foreach(char c in str){
        if (str.Count(x => x == c) > 1)
        {
            return false;
        }
    }
    return true;
}

Console.WriteLine(isCharsOccurOnce("abc"));
Console.WriteLine(isCharsOccurOnce("aabbcc"));
