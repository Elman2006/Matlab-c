#include <stdio.h>

#define MAX_SIZE 25 // Define maximum matrix size

void zeros(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // Make a matrix and decalre all elements to zero
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}

void printmatrix(const char *label, float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // A function to print the matrix with a label for better readability
    printf("%s:\n", label);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.4f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Add a blank line for better readability
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    int row, column;

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &column);

    if (row > MAX_SIZE || column > MAX_SIZE)
    {
        printf("Error: The matrix size exceeds the maximum allowed size of %d x %d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    zeros(matrix, row, column);
    printmatrix("Zeros Matrix", matrix, row, column);

    return 0;
}