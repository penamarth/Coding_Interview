enum Color {
    R,
    G,
    B,
    A;
}

class Pixel
{
    char R;
    char G;
    char B;
    char A;
    public Pixel(char R, char G, char B, char A){
        this.R = R; this.G = G; this.B = B; this.A = A;
    }
}

public class Prog {
    static void rotateRight(Pixel[][] Pic)
    {
        int N = Pic.length;
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

    static void printPic(Pixel[][] Pic, Color c)
    {
        for (int i = 0; i < Pic.length; i++) {
            for (int j = 0; j < Pic[0].length; j++) {
                switch (c) {
                    case R:
                        System.out.print(Pic[i][j].R + " ");
                        break;
                    case G:
                        System.out.print(Pic[i][j].G + " ");
                        break;
                    case B:
                        System.out.print(Pic[i][j].B + " ");
                        break;
                    case A:
                        System.out.print(Pic[i][j].A + " ");
                        break;
                }
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        int N = 5;
        Pixel[][] picture = new Pixel[N][N];
        picture[0][0] = new Pixel('0',' ', ' ', ' ');picture[0][1] = new Pixel('2',' ', ' ', ' ');picture[0][2] = new Pixel('3','*', ' ', ' ');picture[0][3] = new Pixel('4',' ', ' ', ' ');picture[0][4] = new Pixel('5',' ', ' ', ' ');
        picture[1][0] = new Pixel('1',' ', ' ', ' ');picture[1][1] = new Pixel('0','*', ' ', ' ');picture[1][2] = new Pixel('0','*', ' ', ' ');picture[1][3] = new Pixel('0',' ', ' ', ' ');picture[1][4] = new Pixel('0',' ', ' ', ' ');
        picture[2][0] = new Pixel('0',' ', ' ', ' ');picture[2][1] = new Pixel('0',' ', ' ', ' ');picture[2][2] = new Pixel('0','*', ' ', ' ');picture[2][3] = new Pixel('0',' ', ' ', ' ');picture[2][4] = new Pixel('0',' ', ' ', ' ');
        picture[3][0] = new Pixel('0',' ', ' ', ' ');picture[3][1] = new Pixel('0',' ', ' ', ' ');picture[3][2] = new Pixel('0','*', ' ', ' ');picture[3][3] = new Pixel('0',' ', ' ', ' ');picture[3][4] = new Pixel('0',' ', ' ', ' ');
        picture[4][0] = new Pixel('0',' ', ' ', ' ');picture[4][1] = new Pixel('0','*', ' ', ' ');picture[4][2] = new Pixel('0','*', ' ', ' ');picture[4][3] = new Pixel('0','*', ' ', ' ');picture[4][4] = new Pixel('0',' ', ' ', ' ');


        printPic(picture, Color.R);
        printPic(picture, Color.G);

        rotateRight(picture);

        printPic(picture, Color.R);
        printPic(picture, Color.G);
    }
}
