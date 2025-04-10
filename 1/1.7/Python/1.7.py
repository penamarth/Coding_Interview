from enum import Enum


class Color(Enum):
    R = 1
    G = 2
    B = 3
    A = 4


class Pixel:
    def __init__(self, R, G, B, A):
        self.R = R
        self.G = G
        self.B = B
        self.A = A


def rotateRight(Pic):
    N = len(Pic)
    for i in range(int(N/2)):
        for j in range(int(N/2)+1):
            tmp = Pic[i][j]
            Pic[i][j] = Pic[N-1-j][i]
            Pic[N-1-j][i] = Pic[N-1-i][N-1-j]
            Pic[N-1-i][N-1-j] = Pic[j][N-1-i]
            Pic[j][N-1-i] = tmp


def printPic(Pic, c: Color):
    for i in range(len(Pic)):
        for j in range(len(Pic)):
            match c:
                case Color.R:
                     print(Pic[i][j].R + " ", end="")
                case Color.G:
                    print(Pic[i][j].G + " ", end="")
                case Color.B:
                    print(Pic[i][j].B + " ", end="")
                case Color.A:
                    print(Pic[i][j].A + " ", end="")

        print("\n", end="")
    print("\n", end="")


if __name__ == '__main__':
    picture = [
        [Pixel(' ', 'O', ' ', ' '), Pixel(' ', '*', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', 'O', ' ', ' '), Pixel('*', 'O', '*', ' '), Pixel('*', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', '*', ' ', ' '), Pixel(' ', '*', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', 'O', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel('*', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
    ]

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    rotateRight(picture)

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    rotateRight(picture)

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    rotateRight(picture)

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    rotateRight(picture)

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    picture = [
        [Pixel(' ', 'O', ' ', ' '), Pixel('*', '*', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', '*', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', '*', ' ', ' '), Pixel(' ', '*', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
        [Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' '), Pixel(' ', 'O', ' ', ' ')],
    ]

    printPic(picture, Color.R)
    printPic(picture, Color.G)

    rotateRight(picture)

    printPic(picture, Color.R)
    printPic(picture, Color.G)
