#include <stdio.h>

#define MAX_SIZE 25 // Define maximum matrix size

void eye(float matrix[MAX_SIZE][MAX_SIZE], int row, int column) {
    // Create an identity matrix by setting diagonal elements to 1 and the rest to 0
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j){
                matrix[i][j] = 1;
            } 
            else {
                matrix[i][j] = 0;
            }
        }
    }
}

void printmatrix(const char *label, float matrix[MAX_SIZE][MAX_SIZE], int row, int column) {
    // A function to print the matrix with a label for better visualization
    printf("%s:\n", label);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%.4f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Add a blank line for better readability
}

void prod(float matrix[MAX_SIZE][MAX_SIZE], int row, int column, float result[1][MAX_SIZE]) {
    // A function to multiply the elements of each column of the matrix
    for (int j = 0; j < column; j++) {
        result[0][j] = 1; // Initialize the product for this column
        for (int i = 0; i < row; i++) {
            result[0][j] *= matrix[i][j];
        }
    }
}

int main() {
    // This program creates an identity matrix of the specified size and prints it
    // Create a matrix with a maximum size of MAX_SIZE x MAX_SIZE
    float matrix[MAX_SIZE][MAX_SIZE];
    int row, column;

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &column);

    if (row > MAX_SIZE || column > MAX_SIZE) {
        printf("Error: The matrix size exceeds the maximum allowed size of %d x %d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    eye(matrix, row, column);
    printmatrix("Original Matrix", matrix, row, column);

    return 0;
}