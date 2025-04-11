import java.util.HashSet;
import java.util.Random;
import java.util.ArrayList;
import java.util.Set;

public class Prog {
    static void removeNills(ArrayList<ArrayList<Integer>> matrix)
    {
        Set<Integer> rowsToDelete = new HashSet<Integer>();
        Set<Integer> colsToDelete = new HashSet<Integer>();
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.get(0).size(); j++) {
                if (matrix.get(i).get(j) == 0) {
                    rowsToDelete.add(i);
                    colsToDelete.add(j);
                }
            }
        }
        while (!rowsToDelete.isEmpty())
        {
            Integer x = rowsToDelete.iterator().next();

            matrix.remove((int)x);

            rowsToDelete.remove(x);

            Set<Integer> newRowsToDelete = new HashSet<Integer>();
            for (int row : rowsToDelete)
            {
                if (row > x)
                    newRowsToDelete.add(row - 1);
                else
                    newRowsToDelete.add(row);
            }
            rowsToDelete = newRowsToDelete;

        }

        while (!colsToDelete.isEmpty())
        {
            int y = colsToDelete.iterator().next();

            for (int i = 0; i < matrix.size(); i++) {
                matrix.get(i).remove(y);
            }

            colsToDelete.remove(y);

            Set<Integer> newColsToDelete = new HashSet<Integer>();

            for (int col : colsToDelete)
            {
                if (col > y)
                    newColsToDelete.add(col - 1);
                else
                    newColsToDelete.add(col);
            }
            colsToDelete = newColsToDelete;
        }

    }

    static void printMatrix(ArrayList<ArrayList<Integer>> matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.get(0).size(); j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }
    public static void main(String[] args) {

        Random rand = new Random();

        int N = 5, M = 10;

        ArrayList<ArrayList<Integer>> matrix = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < N; i++)
        {
            matrix.add(new ArrayList<>());
            for (int j = 0; j < M; j++) {
                matrix.get(i).add(rand.nextInt(10));
            }
        }

        printMatrix(matrix);
        removeNills(matrix);
        printMatrix(matrix);
    }
}
