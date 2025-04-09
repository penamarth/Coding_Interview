def compressString(s: str) -> str:
    compressed = ""
    counter = 1
    prev_c = ''
    for c in s:
        if c == prev_c:
            counter = counter + 1
        else:
            compressed = compressed + prev_c + str(counter)
            counter = 1
            prev_c = c
    compressed = compressed + s[-1] + str(counter)
    compressed = compressed[1:]

    if len(compressed) >= len(s):
        return s
    else:
        return compressed


if __name__ == '__main__':
    print(compressString("abc"))
    print(compressString("aabc"))
    print(compressString("Aabc"))
    print(compressString("aaaabbbcc"))
    print(compressString("aaAabbBcc"))
    print(compressString("aaAabbbBcc"))
    print(compressString("aaAabbbbBcc"))
    print(compressString("aaAabbbbbBcc"))
    print(compressString("aaAabbbbbbBcc"))

    