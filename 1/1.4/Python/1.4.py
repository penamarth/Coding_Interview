def all_perms(elements):
    if len(elements) <= 1:
        yield elements
    else:
        for perm in all_perms(elements[1:]):
            for i in range(len(elements)):
                yield perm[:i] + elements[0:1] + perm[i:]


def isPalindrom(s: str) -> bool:
    for i in range(int(len(s)/2)):
        if s[i] != s[len(s) -1 -i]:
            return False
    return True


def isPalindromAnagram(s: str) -> bool:
    s = s.replace(" ", "")

    for permutation in all_perms(s):
        if isPalindrom(permutation):
            print("Palindrom found: {}".format(permutation))
            return True
    return False

if __name__ == '__main__':
    print(isPalindromAnagram("ar"))
    print(isPalindromAnagram("ara"))
    print(isPalindromAnagram("raa"))
    print(isPalindromAnagram("ar "))
    print(isPalindromAnagram("a ra"))
    print(isPalindromAnagram("r aa"))
