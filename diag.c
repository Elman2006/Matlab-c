#include <stdio.h>

#define MAX_SIZE 25 // Define maximum matrix size

void getelementsmatrix(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // A function to get the elements of the matrix from the user and initialize it
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

void diag(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to extract the diagonal elements of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == j)
            {
                result[i][j] = matrix[i][j];
            }
            else
            {
                result[i][j] = 0;
            }
        }
    }
}

int main()
{
    // This program extracts the diagonal elements of a matrix and sets all other elements to 0
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    float diagonal[MAX_SIZE][MAX_SIZE];
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

    getelementsmatrix(matrix, row, column);
    printmatrix("Original Matrix", matrix, row, column);

    diag(matrix, row, column, diagonal);
    printmatrix("Diagonal Matrix", diagonal, row, column);

    return 0;
}