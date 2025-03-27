#include <stdio.h>  // For printf and scanf
#include <math.h>   // For sqrt and pow

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

void printmatrix(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // A function that helps you to print the matrix.

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

float determinant(float matrix[MAX_SIZE][MAX_SIZE], int n)
{
    float det = 0;
    float submatrix[MAX_SIZE][MAX_SIZE];

    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    else
    {
        int sign = 1; // Precompute sign instead of using pow(-1, x)
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += sign * matrix[0][x] * determinant(submatrix, n - 1);
            sign = -sign; // Alternate sign
        }
    }
    return det;
}

void diag(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to extract the diagonal elements of the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = (i == j) ? matrix[i][j] : 0;
        }
    }
}

void eye(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // Create an identity matrix by setting diagonal elements to 1 and the rest to 0
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void flipdu(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to flip the matrix vertically (upside down)
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = matrix[row - 1 - i][j];
        }
    }
}

void fliplr(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to flip the matrix from left to right
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = matrix[i][column - j - 1];
        }
    }
}

void inv(float matrix[2][2])
{
    // A function to calculate the inverse of a 2x2 matrix

    float det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    if (det == 0)
    {
        printf("The matrix is singular, hence it's inverse does not exist.\n");
    }

    else
    {
        float temp = matrix[0][0];
        matrix[0][0] = matrix[1][1];
        matrix[1][1] = temp;
        matrix[0][1] = -matrix[0][1];
        matrix[1][0] = -matrix[1][0];
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrix[i][j] = matrix[i][j] / det;
            }
        }
    }
}

void prod(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[1][MAX_SIZE])
{
    // A function to multiply the elements of each column of the matrix
    for (int j = 0; j < column; j++)
    {
        result[0][j] = 1; // Initialize the product for this column
        for (int i = 0; i < row; i++)
        {
            result[0][j] *= matrix[i][j];
        }
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
    // A function to rotate the matrix 90 degrees counterclockwise
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[column - j - 1][i] = matrix[i][j];
        }
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
                result[i][j] = 0; // Assign 0 instead of the original value
            }
            else
            {
                result[i][j] = sqrt(matrix[i][j]);
            }
        }
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

void triu(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[MAX_SIZE][MAX_SIZE])
{
    // A function to create an upper triangular matrix
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
    // A function to create a lower triangular matrix
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

void zeros(float matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    // Make a matrix and declare all elements to zero
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}
