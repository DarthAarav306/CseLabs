#include <stdio.h>
#include <stdlib.h>

void read(int** mat, int m, int n) {
    printf("Enter elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", (*(mat + i) + j));  // Using pointer notation
        }
    }
}

void display(int** mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(mat + i) + j));  // Using pointer notation
        }
        printf("\n");
    }
}

int** multiply(int** mat1, int** mat2, int m1, int n1, int m2, int n2) {
    // Check if the matrices can be multiplied
    if (n1 != m2) {
        printf("Matrices cannot be multiplied due to dimension mismatch.\n");
        return NULL;
    }

    // Create the result matrix
    int** mat3 = (int**)malloc(m1 * sizeof(int*));
    for (int i = 0; i < m1; i++) {
        mat3[i] = (int*)malloc(n2 * sizeof(int));
    }

    // Perform multiplication
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            *(*(mat3 + i) + j) = 0;  // Initialize the element
            for (int k = 0; k < n1; k++) {
                *(*(mat3 + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);  // Using pointer notation
            }
        }
    }

    return mat3;  // Return the resulting matrix
}

int main() {
    int m1, n1, m2, n2;

    printf("Enter rows and columns for matrix 1: ");
    scanf("%d %d", &m1, &n1);

    int** mat1 = (int**)malloc(m1 * sizeof(int*));
    for (int i = 0; i < m1; i++) {
        mat1[i] = (int*)malloc(n1 * sizeof(int));
    }

    printf("Enter rows and columns for matrix 2: ");
    scanf("%d %d", &m2, &n2);

    int** mat2 = (int**)malloc(m2 * sizeof(int*));
    for (int i = 0; i < m2; i++) {
        mat2[i] = (int*)malloc(n2 * sizeof(int));
    }

    printf("Reading for matrix 1:\n");
    read(mat1, m1, n1);

    printf("Reading for matrix 2:\n");
    read(mat2, m2, n2);

    printf("Displaying matrix 1:\n");
    display(mat1, m1, n1);

    printf("Displaying matrix 2:\n");
    display(mat2, m2, n2);

    int** mat3 = multiply(mat1, mat2, m1, n1, m2, n2);

    if (mat3 != NULL) {
        printf("Resulting matrix after multiplication:\n");
        display(mat3, m1, n2);

        // Freeing the memory for mat3
        for (int i = 0; i < m1; i++) {
            free(mat3[i]);
        }
        free(mat3);
    }

    // Free the memory for mat1 and mat2
    for (int i = 0; i < m1; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < m2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    return 0;
}
