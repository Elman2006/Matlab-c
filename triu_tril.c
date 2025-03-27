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

void triu(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to creat an upper triangular matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i > j)
            {
                result[i][j] = 0;
            }
            else
            {
                result[i][j] = matrix[i][j];
            }
        }
    }
}

void tril(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to creat a lower triangular matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i < j)
            {
                result[i][j] = 0;
            }
            else
            {
                result[i][j] = matrix[i][j];
            }
        }
    }
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    float triu_matrix[MAX_SIZE][MAX_SIZE];
    float tril_matrix[MAX_SIZE][MAX_SIZE];
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

    triu(matrix, row, column, triu_matrix);
    printmatrix("Upper Triangular Matrix:", triu_matrix, row, column);

    tril(matrix, row, column, tril_matrix);
    printmatrix("Lower Triangular Matrix:", tril_matrix, row, column);

    return 0;
}