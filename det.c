#include <stdio.h>
#include <math.h>

void getelementsmatrix(float matrix[25][25], int n)
{
    // A function that helps you to get elements of matrix from the user and initialze it.

    printf("Please enter the elements of the matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printmatrix(float matrix[25][25], int n)
{
    // A function that helps you to print the matrix.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }

        printf("\n");
    }
}

float determinant(float matrix[25][25], int n)
{
    float det = 0;
    float submatrix[25][25];

    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    else
    {
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
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}

int main()
{

    // creat a matrix with maximum elelments of 25 x 25
    float matrix[25][25];
    int n;
    scanf("%d", &n);
    printf("Enter the size of the matrix (n x n): ");

    getelementsmatrix(matrix, n);
    printmatrix(matrix, n);
    printf("detrminant is: %.3f", determinant(matrix, n));

    return 0;
}