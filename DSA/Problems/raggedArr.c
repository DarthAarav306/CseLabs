#include <stdio.h>
#include <stdlib.h>

// Function to create a ragged array
void Create(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter size of row %d: ", i + 1);
        int size;
        scanf("%d", &size);

        arr[i] = (int*)malloc((size + 1) * sizeof(int)); // Allocate memory for the row
        arr[i][0] = size; // Store size in the first element of the row

        printf("Enter elements for row %d: ", i + 1);
        for (int j = 1; j <= size; j++) {
            scanf("%d", &arr[i][j]); // Store elements of the row
        }
    }
}

// Recursive function to sort a single row using Bubble Sort
void Sort(int* row, int size) {
    if (size == 1) return; // Base case: Only one element in the row

    for (int i = 1; i < size; i++) { // Perform one pass of Bubble Sort
        if (row[i] > row[i + 1]) {
            int temp = row[i];
            row[i] = row[i + 1];
            row[i + 1] = temp;
        }
    }

    // Recursively sort the remaining part
    Sort(row, size - 1);
}

// Function to display the ragged array
void Display(int** arr, int n) {
    printf("Ragged Array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i][0]; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for the ragged array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the ragged array
    int** raggedArray = (int**)malloc(n * sizeof(int*));

    // Create the ragged array
    Create(raggedArray, n);

    printf("Before Sorting:\n");
    Display(raggedArray, n);

    // Sort each row of the ragged array
    for (int i = 0; i < n; i++) {
        Sort(raggedArray[i], raggedArray[i][0]);
    }

    printf("After Sorting:\n");
    Display(raggedArray, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(raggedArray[i]);
    }
    free(raggedArray);

    return 0;
}
