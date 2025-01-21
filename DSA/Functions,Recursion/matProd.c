#include <stdio.h>

#define MAX 100

// Function to read a matrix from the user
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to check if matrices are compatible for multiplication
int areMatricesCompatible(int rows1, int cols1, int rows2, int cols2) {
    return (cols1 == rows2);
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;  // Initialize the result matrix element
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];

    // Reading dimensions for the first matrix
    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    // Reading the first matrix
    readMatrix(mat1, rows1, cols1);

    // Reading dimensions for the second matrix
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Reading the second matrix
    readMatrix(mat2, rows2, cols2);

    // Displaying both matrices
    displayMatrix(mat1, rows1, cols1);
    displayMatrix(mat2, rows2, cols2);

    // Checking if the matrices can be multiplied
    if (areMatricesCompatible(rows1, cols1, rows2, cols2)) {
        printf("Matrices are compatible for multiplication.\n");

        // Multiplying the matrices
        multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);

        // Displaying the result matrix
        printf("Resultant Matrix:\n");
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Matrices are not compatible for multiplication.\n");
    }

    return 0;
}
