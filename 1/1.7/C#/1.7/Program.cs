void rotateRight(Pixel[][] Pic)
{
    int N = Pic.Length;
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < 1.0 * N / 2; j++)
        {
            Pixel tmp = Pic[i][j];
            Pic[i][j] = Pic[N - 1 - j][i];
            Pic[N - 1 - j][i] = Pic[N - 1 - i][N - 1 - j];
            Pic[N - 1 - i][N - 1 - j] = Pic[j][N - 1 - i];
            Pic[j][N - 1 - i] = tmp;
        }
    }
}

void printPic(Pixel[][] Pic, Color c)
{
    for (int i = 0; i < Pic.Length; i++)
    {
        for (int j = 0; j < Pic.Length; j++)
        {
            switch (c)
            {
                case Color.R:
                    Console.Write(Pic[i][j].R + " ");
                    break;
                case Color.G:
                    Console.Write(Pic[i][j].G + " ");
                    break;
                case Color.B:
                    Console.Write(Pic[i][j].B + " ");
                    break;
                case Color.A:
                    Console.Write(Pic[i][j].A + " ");
                    break;
            }

        }
        Console.Write("\n");
    }
}

Pixel[][] picture = [
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = '*', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = '*', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = '*', B = ' ', A = ' ' }, new() { R = ' ', G = '*', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' } ,new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }]
    ];


printPic(picture, Color.R);
Console.Write("\n");
printPic(picture, Color.G);
Console.Write("\n");

rotateRight(picture);

printPic(picture, Color.R);
Console.Write("\n");
printPic(picture, Color.G);
Console.Write("\n");

rotateRight(picture);

printPic(picture, Color.R);
Console.Write("\n");
printPic(picture, Color.G);
Console.Write("\n");

rotateRight(picture);

printPic(picture, Color.R);
Console.Write("\n");
printPic(picture, Color.G);
Console.Write("\n");

rotateRight(picture);

printPic(picture, Color.R);
Console.Write("\n");
printPic(picture, Color.G);
Console.Write("\n");

picture = [
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = '*', G = '*', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = '*', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = '*', B = ' ', A = ' ' }, new() { R = ' ', G = '*', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' } ,new() { R = ' ', G = 'O', B = ' ', A = ' ' }],
         [new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }, new() { R = ' ', G = 'O', B = ' ', A = ' ' }]
    ];
printPic(picture, Color.R);
Console.Write("\n"); ;
printPic(picture, Color.G);
Console.Write("\n");
rotateRight(picture);
printPic(picture, Color.R);
Console.Write("\n"); ;
printPic(picture, Color.G);
Console.Write("\n");


enum Color { R, G, B, A };

class Pixel
{
    public char R { get; set; }
    public char G { get; set; }
    public char B { get; set; }
    public char A { get; set; }
}