def isSubstring(string: str, substring: str) -> bool:
    if substring in string:
        return True
    else:
        return False

def isCiclicShift(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return False
    return isSubstring(s2+s2, s1)

if __name__ == '__main__':
    print("waterbottle", "erbottlewat", isCiclicShift("waterbottle", "erbottlewat"))
    print("Hello", "oHell", isCiclicShift("Hello", "oHell"))
    print("Hello", "Helloo", isCiclicShift("Hello", "Helloo"))
    print("Hello", "Hoell", isCiclicShift("Hello", "Hoell"))

