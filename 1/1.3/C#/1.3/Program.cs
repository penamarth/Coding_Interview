String URIWhitespace(String s)
{
    return s.Trim().Replace(" ", "%20");
}

Console.WriteLine(URIWhitespace("NoSpace"));
Console.WriteLine(URIWhitespace("With Space"));
Console.WriteLine(URIWhitespace("Many Spaces In Line"));
Console.WriteLine(URIWhitespace(" StartWithSpace"));
Console.WriteLine(URIWhitespace("EndWithSpace "));
Console.WriteLine(URIWhitespace(" Start With Space And Multiple Spaces"));
Console.WriteLine(URIWhitespace("End With Space And Multiple Spaces "));
Console.WriteLine(URIWhitespace(" All In Spaces "));
