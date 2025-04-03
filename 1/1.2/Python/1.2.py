def isAnagram(string1: str, string2: str) -> bool:
    if len(string1) != len(string2):
        return False

    for c in string1:
        if string1.count(c) != string2.count(c):
            return False

    return True


if __name__ == '__main__':
    print(isAnagram("hello", "hell"))
    print(isAnagram("hello", "ehllo"))