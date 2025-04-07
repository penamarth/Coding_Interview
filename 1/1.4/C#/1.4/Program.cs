IEnumerable<String> all_perms(String elements) {
    if (elements.Length <= 1)
        yield return elements;
    else { 
        foreach(String perm in all_perms(elements[1..])){
            for( int i=0; i < elements.Length; i++){
                yield return perm[..i] + elements[0..1] + perm[i..];
            }
        }
    }
}

Boolean isPalindrom(String s){
    for( int i = 0; i < s.Length / 2; i++) { 
        if(s[i] != s[s.Length - 1 - i])
            return false;
    }
    return true;
}

Boolean isPalindromAnagram(String s)
{
    s = s.Replace(" ", "");

    foreach (String permutation in all_perms(s)) {
        if (isPalindrom(permutation)) {
            Console.WriteLine("Palindrom found: {0}", permutation);
            return true;
        }    
    }
    return false;
}


Console.WriteLine(isPalindromAnagram("ar"));
Console.WriteLine(isPalindromAnagram("ara"));
Console.WriteLine(isPalindromAnagram("raa"));
Console.WriteLine(isPalindromAnagram("ar "));
Console.WriteLine(isPalindromAnagram("a ra"));
Console.WriteLine(isPalindromAnagram("r aa"));
Console.WriteLine(isPalindromAnagram("r ara"));
