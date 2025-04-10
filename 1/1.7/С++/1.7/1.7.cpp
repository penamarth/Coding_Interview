#include <iostream>
#include <vector>

enum Color {R,G,B,A};

struct Pixel {
    char R;
    char G;
    char B;
    char A;
};

void rotateRight(std::vector<std::vector<Pixel>> &Pic)
{
    int N = Pic.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < 1.0 * N / 2; j++) {
            Pixel tmp = Pic[i][j];
            Pic[i][j] = Pic[N - 1 - j][i];
            Pic[N - 1 - j][i] = Pic[N - 1 - i][N - 1 - j];
            Pic[N - 1 - i][N - 1 - j] = Pic[j][N - 1 - i];
            Pic[j][N - 1 - i] = tmp;
        }
    }
}

void printPic(const std::vector<std::vector<Pixel>> &Pic, Color c)
{
    for (int i = 0; i < Pic.size(); i++) {
        for (int j = 0; j < Pic.size(); j++) {
            switch (c) {
            case R:
                std::cout << Pic[i][j].R << " ";
                break;
            case G:
                std::cout << Pic[i][j].G << " ";
                break;
            case B:
                std::cout << Pic[i][j].B << " ";
                break;
            case A:
                std::cout << Pic[i][j].A << " ";
                break;
            }
            
        }
        std::cout << std::endl;
    }  
}

int main()
{

    std::vector<std::vector<Pixel>> picture = { 
        {{'0',' ','0','0'},{'1',' ','0','0'},{'3','*','0','0'},{'0',' ','0','0'},{'0',' ','0','0'}},
        {{'0',' ','0','0'},{'2','*','0','0'},{'4','*','0','0'},{'0',' ','0','0'},{'0',' ','0','0'}},
        {{'0',' ','0','0'},{'5',' ','0','0'},{'6','*','0','0'},{'0',' ','0','0'},{'0',' ','0','0'}},
        {{'0',' ','0','0'},{'0',' ','0','0'},{'0','*','0','0'},{'0',' ','0','0'},{'0',' ','0','0'}},
        {{'0',' ','0','0'},{'0','*','0','0'},{'0','*','0','0'},{'0','*','0','0'},{'0',' ','0','0'}}
    };

    printPic(picture, R);
    std::cout << std::endl;
    printPic(picture, G);
    std::cout << std::endl;

    rotateRight(picture);

    printPic(picture, R);
    std::cout << std::endl;
    printPic(picture, G);
    std::cout << std::endl;

    rotateRight(picture);

    printPic(picture, R);
    std::cout << std::endl;
    printPic(picture, G);
    std::cout << std::endl;

    picture = {
        {{' ','O',' ',' '},{'*','*',' ',' '},{' ','O',' ',' '},{' ','O',' ',' '}},
        {{' ','O',' ',' '},{' ','O','*',' '},{' ','O',' ',' '},{' ','O',' ',' '}},
        {{' ','*',' ',' '},{' ','*',' ',' '},{' ','O',' ',' '},{' ','O',' ',' '}},
        {{' ','O',' ',' '},{' ','O',' ',' '},{' ','O',' ',' '},{' ','O',' ',' '}}

    };
    printPic(picture, R);
    std::cout << std::endl;
    printPic(picture, G);
    std::cout << std::endl;
    rotateRight(picture);
    printPic(picture, R);
    std::cout << std::endl;
    printPic(picture, G);
    std::cout << std::endl;
}
