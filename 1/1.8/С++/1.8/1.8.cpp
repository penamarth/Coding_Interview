#include <iostream>
#include <vector>
#include <set>

void removeNills(std::vector<std::vector<int>> &matrix)
{
    std::set<int> rowsToDelete;
    std::set<int> colsToDelete;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                rowsToDelete.insert(i);
                colsToDelete.insert(j);
            }
        }
    }
    while (!rowsToDelete.empty())
    {
        int x = *rowsToDelete.begin();

        matrix.erase(matrix.begin() + x);

        rowsToDelete.erase(x);

        std::set<int> newRowsToDelete;
        for (int row : rowsToDelete)
        {
            if (row > x)
                newRowsToDelete.insert(row - 1);
            else
                newRowsToDelete.insert(row);
        }
        rowsToDelete = newRowsToDelete;

    }

    while (!colsToDelete.empty())
    {
        int y = *colsToDelete.begin();

        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].erase(matrix[i].begin() + y);
        }

        colsToDelete.erase(y);

        std::set<int> newColsToDelete;

        for (int col : colsToDelete)
        {
            if (col > y)
                newColsToDelete.insert(col - 1);
            else
                newColsToDelete.insert(col);
        }
        colsToDelete = newColsToDelete;
    }
           
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
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

