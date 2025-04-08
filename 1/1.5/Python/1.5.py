def areOneStepAway(s1: str, s2: str) -> bool:
    if s1 == s2:
        return True
    if len(s1) == len(s2):
        count = 0
        for i,c in enumerate(s1):
            if c != s2[i]:
                count = count + 1
        if count == 1:
            return True
        else:
            return False
    elif len(s1) - len(s2) == 1 and all(x in s1 for x in s2 ):
        return True
    elif len(s2) - len(s1) == 1 and all(x in s2 for x in s1 ):
        return True
    else:
        return False


if __name__ == '__main__':
    print(areOneStepAway('hello','hello'))
    print(areOneStepAway('hello','hell'))
    print(areOneStepAway('hello','help'))
    print(areOneStepAway('hellu','hello'))
    print(areOneStepAway('helloo','hello'))
    print(areOneStepAway('hellooo','hello'))