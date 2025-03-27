#include <stdio.h>
#include <math.h>

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
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_sqrt(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to calculate the square root of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] < 0)
            {
                printf("Error: Cannot calculate the square root of a negative number at row %d, column %d.\n", i + 1, j + 1);
                result[i][j] = matrix[i][j]; // Keep the original value
            }
            else
            {
                result[i][j] = sqrt(matrix[i][j]);
            }
        }
    }
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    float result_matrix[MAX_SIZE][MAX_SIZE];
    int row, column;

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &column);

    if (row > MAX_SIZE || column > MAX_SIZE)
    {
        printf("Error: Maximum matrix size is %d x %d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    getelementsmatrix(matrix, row, column);
    printmatrix("Original Matrix", matrix, row, column);

    matrix_sqrt(matrix, row, column, result_matrix);
    printmatrix("Matrix After Square Root", result_matrix, row, column);

    return 0;
}