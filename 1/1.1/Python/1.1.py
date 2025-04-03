def isCharsOccurOnce(string : str) -> bool:
    for c in string:
        if string.count(c) > 1:
            return False
    return True


if __name__ == '__main__':
    print(isCharsOccurOnce("abc"))
    print(isCharsOccurOnce("aabbcc"))
