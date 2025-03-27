#include <stdio.h>

#define MAX_SIZE 25 // Define maximum matrix size

void getelementsmatrix(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // A function to get elements of the matrix from the user and initialize it
    printf("Please enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the element of row %d and column %d: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printmatrix(const char *label, float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // A function to print the matrix with a label
    printf("%s:\n", label);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rot90_clock(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to rotate the matrix 90 degrees in clock way
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[j][row - i - 1] = matrix[i][j];
        }
    }
}

void rot90_padclock(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to rotate the matrix 90 degrees in anti clock way
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[column - j - 1][i] = matrix[i][j];
        }
    }
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    float clock_way[MAX_SIZE][MAX_SIZE];
    float anticlock_way[MAX_SIZE][MAX_SIZE];
    int row, column;

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &column);

    if (row > MAX_SIZE || column > MAX_SIZE)
    {
        printf("Error: Maximum matrix size is MAX_SIZE x MAX_SIZE.\n");
        return 1;
    }

    getelementsmatrix(matrix, row, column);
    printmatrix("Original Matrix", matrix, row, column);

    rot90_clock(matrix, row, column, clock_way);
    printmatrix("Rotated Matrix", clock_way, column, row);

    rot90_padclock(matrix, row, column, anticlock_way);
    printmatrix("Rotated Matrix", anticlock_way, column, row);

    return 0;
}