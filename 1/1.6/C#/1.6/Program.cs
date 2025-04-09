String compressString(String s){
    String compressed = "";
    int counter = 1;
    String prev_c = "";
    foreach( char c in s) {
        if (c.ToString() == prev_c)
            counter += 1;
        else {
            compressed = compressed + prev_c + counter.ToString();
            counter = 1;
            prev_c = "" + c;
         }
    }
    compressed = compressed + s[s.Length - 1] + counter.ToString();
    compressed = compressed.Substring(1);

    if(compressed.Length >= s.Length)
        return s;
    else
        return compressed;
}


Console.WriteLine(compressString("abc"));
Console.WriteLine(compressString("aabc"));
Console.WriteLine(compressString("Aabc"));
Console.WriteLine(compressString("aaaabbbcc"));
Console.WriteLine(compressString("aaAabbBcc"));
Console.WriteLine(compressString("aaAabbbBcc"));
Console.WriteLine(compressString("aaAabbbbBcc"));
Console.WriteLine(compressString("aaAabbbbbBcc"));
Console.WriteLine(compressString("aaAabbbbbbBcc"));