#include <stdio.h>

#define MAX_SIZE 25 // Define maximum matrix size

void getelementsmatrix(float matrix[MAX_SIZE][MAX_SIZE], int n)
{
    // A function that helps you to get elements of matrix from the user and initialze it.
    printf("Please enter the elements of the matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the element of row %d and column %d: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printmatrix(const char *label, float matrix[MAX_SIZE][MAX_SIZE], int n)
{
    // A function that helps you to print the matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.4f ", matrix[i][j]);
        }

        printf("\n");
    }
}

float trace(float matrix[MAX_SIZE][MAX_SIZE], int n)
{
    // A function to calculate the trace of a matrix
    float result = 0;
    for (int k = 0; k < n; k++)
    {
        result += matrix[k][k];
    }

    return result;
}

int main()
{
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // returns an error if the matrix size exceeds the maximum size
    if (n > MAX_SIZE)
    {
        printf("Error: Maximum matrix size is %d x %d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    // get the elements of the matrix from the usera and show them
    getelementsmatrix(matrix, n);
    printmatrix("Original Matrix", matrix, n);

    printf("The trace of the matrix is: %.4f\n", trace(matrix, n));

    return 0;
}
