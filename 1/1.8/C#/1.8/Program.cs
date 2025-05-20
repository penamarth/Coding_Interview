using System;
using System.Collections.Generic;

void removeNills(List<List<int>> matrix)
{
    HashSet<int> rowsToDelete = new HashSet<int>();
    HashSet<int> colsToDelete = new HashSet<int>();

    for (int i = 0; i < matrix.Count; i++)
    {
        for (int j = 0; j < matrix[0].Count; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowsToDelete.Add(i);
                colsToDelete.Add(j);
            }
        }
    }
    while (rowsToDelete.Count > 0)
    {
        int x = rowsToDelete.ElementAt(0);

        matrix.RemoveAt(x);

        rowsToDelete.Remove(x);

        HashSet<int> newRowsToDelete = new HashSet<int>();
        foreach (int row in rowsToDelete)
        {
            if (row > x)
                newRowsToDelete.Add(row - 1);
            else
                newRowsToDelete.Add(row);
        }
        rowsToDelete = newRowsToDelete;

    }

    while (colsToDelete.Count > 0)
    {
        int y = colsToDelete.ElementAt(0);

        for (int i = 0; i < matrix.Count; i++)
        {
            matrix[i].RemoveAt(y);
        }

        colsToDelete.Remove(y);

        HashSet<int> newColsToDelete = new HashSet<int>();

        foreach (int col in colsToDelete)
        {
            if (col > y)
                newColsToDelete.Add(col - 1);
            else
                newColsToDelete.Add(col);
        }
        colsToDelete = newColsToDelete;
    }
           
}

void printMatrix(List<List<int>> matrix)
{
    for (int i = 0; i < matrix.Count; i++)
    {
        for (int j = 0; j < matrix[0].Count; j++)
        {
            Console.Write(matrix[i][j] + " ");
        }
        Console.Write("\n");
    }
    Console.Write("\n");
}


Random rnd = new Random();

int N = 5, M = 10;

List<List<int>> matrix = new List<List<int>>();

for (int i = 0; i < N; i++)
{
    matrix.Add(new List<int>());
    for (int j = 0; j < M; j++)
    {
        matrix[i].Add(rnd.Next(0, 9));
    }
}

printMatrix(matrix);
removeNills(matrix);
printMatrix(matrix);
