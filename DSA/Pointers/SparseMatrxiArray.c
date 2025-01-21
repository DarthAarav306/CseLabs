#include <stdio.h>

#define MAX 100  // Maximum non-zero elements

// Function to represent a sparse matrix using a triplet array
void sparseToTriplet(int matrix[4][5], int rows, int cols, int triplet[3][MAX], int *size) {
    *size = 0;  // Initialize the number of non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[0][*size] = i;          // Row index
                triplet[1][*size] = j;          // Column index
                triplet[2][*size] = matrix[i][j]; // Value
                (*size)++;
            }
        }
    }
}

// Function to display the triplet array
void displayTriplet(int triplet[3][MAX], int size) {
    printf("Row  Column  Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d      %d       %d\n", triplet[0][i], triplet[1][i], triplet[2][i]);
    }
}

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int triplet[3][MAX]; // To store the triplet representation
    int size; // Number of non-zero elements

    // Convert the sparse matrix to triplet form
    sparseToTriplet(matrix, 4, 5, triplet, &size);

    // Display the triplet array
    displayTriplet(triplet, size);

    return 0;
}
