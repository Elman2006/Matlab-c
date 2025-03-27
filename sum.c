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

void printmatrix(const char *label, float matrix[][MAX_SIZE], int row, int column)
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

void sum(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[1][MAX_SIZE])
{
    // A function to calculate the sum of each column of the matrix
    for (int j = 0; j < column; j++)
    {
        result[0][j] = 0; // Initialize the result for this column
        for (int i = 0; i < row; i++)
        {
            result[0][j] += matrix[i][j];
        }
    }
}

void sum2(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][1])
{
    // A function to calculate the sum of each row of the matrix
    for (int i = 0; i < row; i++)
    {
        result[i][0] = 0; // Initialize the result for this row
        for (int j = 0; j < column; j++)
        {
            result[i][0] += matrix[i][j];
        }
    }
}

float total_sum(float matrix[1][MAX_SIZE], int column)
{
    // A function to calculate the total sum of all elements in a 1xN matrix
    float sum = 0;
    for (int j = 0; j < column; j++)
    {
        sum += matrix[0][j];
    }
    return sum;
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    float sum_matrix[1][MAX_SIZE] = {0};  // Initialize to 0
    float sum2_matrix[MAX_SIZE][1] = {0}; // Initialize to 0
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

    // Calculate the sum of each column
    sum(matrix, row, column, sum_matrix);
    printmatrix("Sum of each column", sum_matrix, 1, column);

    // Calculate the sum of each row
    sum2(matrix, row, column, sum2_matrix);
    printmatrix("Sum of each row", sum2_matrix, row, 1);

    // Calculate the total sum of all elements
    float total = total_sum(sum_matrix, column);
    printf("Sum of all elements: %.4f\n", total);

    return 0;
}