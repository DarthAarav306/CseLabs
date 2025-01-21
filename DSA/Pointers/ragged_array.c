#include<stdio.h>
#include<stdlib.h>
int main() {
    int m;
    printf("Enter number of rows for the ragged array: ");
    scanf("%d", &m);

    // Allocate memory for rows
    int** ra = (int**)malloc(m * sizeof(int*));
    if (ra == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Input elements for each row
    for (int i = 0; i < m; i++) {
        int n;
        printf("Enter number of columns for row %d: ", (i + 1));
        scanf("%d", &n);

        // Allocate memory for each row (n columns + 1 for storing the size)
        ra[i] = (int*)malloc((n + 1) * sizeof(int));
        if (ra[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i + 1);
            // Free previously allocated memory before exiting
            for (int k = 0; k < i; k++) {
                free(ra[k]);
            }
            free(ra);
            return -1;
        }

        // Store the number of columns in the first element of the row
        ra[i][0] = n;

        // Input elements for the row
        printf("Enter %d elements for row %d: ", n, (i + 1));
        for (int j = 1; j <= n; j++) {
            scanf("%d", &ra[i][j]);
        }
    }

    // Displaying the ragged array
    printf("\nThe ragged array is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= ra[i][0]; j++) {
            printf("%d ", ra[i][j]);  // Adding space between elements for better readability
        }
        printf("\n");
    }

    // Freeing the allocated memory
    for (int i = 0; i < m; i++) {
        free(ra[i]);
    }
    free(ra);

    return 0;
}
