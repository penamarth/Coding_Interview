def URIWhitespace(s: str) -> str:
    return s.strip().replace(" ", "%20")


if __name__ == '__main__':
    print(URIWhitespace("NoSpace"))
    print(URIWhitespace("With Space"))
    print(URIWhitespace("Many Spaces In Line"))
    print(URIWhitespace(" StartWithSpace"))
    print(URIWhitespace("EndWithSpace "))
    print(URIWhitespace(" Start With Space And Multiple Spaces"))
    print(URIWhitespace("End With Space And Multiple Spaces "))
    print(URIWhitespace(" All In Spaces "))
