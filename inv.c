#include <stdio.h>

void getelementsmatrix(float matrix[2][2])
{
    // A function that helps you to get elements of matrix from the user and initialze it.

    printf("Please enter the elements of the matrix: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printmatrix(float matrix[2][2])
{
    // A function that helps you to print the matrix.

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }

        printf("\n");
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

int main()
{
    // creat a matrix 2 x 2
    float matrix[2][2];

    getelementsmatrix(matrix);
    printmatrix(matrix);
    inv(matrix);
    printmatrix(matrix);
    return 0;
}