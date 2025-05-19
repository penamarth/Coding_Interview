import random

def removeNills(matrix):
    rowsToDelete = set()
    colsToDelete = set()

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:
                rowsToDelete.add(i)
                colsToDelete.add(j)
              
    
    while len(rowsToDelete) > 0:
    
        x = rowsToDelete.pop()
        matrix.pop(x)
        
        newRowsToDelete = set()
        for row in rowsToDelete:
            if row > x:
                newRowsToDelete.add(row - 1)
            else:
                newRowsToDelete.add(row)
        
        rowsToDelete = newRowsToDelete

    while len(colsToDelete) > 0:
    
        y = colsToDelete.pop()

        for i in range(len(matrix)):
            matrix[i].pop(y)
        
        newColsToDelete = set()

        for col in colsToDelete:
            if col > y:
                newColsToDelete.add(col - 1)
            else:
                newColsToDelete.add(col)
        
        colsToDelete = newColsToDelete
    

def  printMatrix(matrix) :
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            print(str(matrix[i][j]) + " ", end="")
        
        print("\n", end="")
    print("\n", end="")


if __name__ == '__main__':    
 
    N = 5
    M = 10
    matrix = [[0 for _ in range(M)] for _ in range(N)]

    for i in range(N):
        for j in range(M):
            matrix[i][j] = random.randint(0,9)
        
    printMatrix(matrix)
    removeNills(matrix)
    printMatrix(matrix)
