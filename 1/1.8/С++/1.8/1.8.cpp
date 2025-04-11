#include <iostream>
#include <vector>
#include <tuple>

void removeRow(std::vector<std::vector<int>>& matrix,int col) {
    matrix.erase(matrix.begin() + col);
}

void removeCol(std::vector<std::vector<int>>& matrix, int row) {
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i].erase(matrix[i].begin() + row);
    }
}

void removeNills(std::vector<std::vector<int>> &matrix)
{
    std::vector<std::tuple<int,int>> toDelete;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                removeRow(matrix, i);
                removeCol(matrix, j);
            }
        }
    }
}

void printMatrix(std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(0));
    
    int N = 5, M = 10;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    printMatrix(matrix);
    removeNills(matrix);
    printMatrix(matrix);
}

