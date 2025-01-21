#include <stdio.h>
#include <stdlib.h>

// Selection Sort function with operation count
void selectionSort(int *a, unsigned int n)
{
    unsigned int i, j, min;
    int temp;
    int opcount = 0; // Introduce operation count

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            ++opcount; // Increment operation count for every comparison
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        // Swap a[i] and a[min]
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("\nOperation Count: %d\n", opcount);
}

int main()
{
    int *a;
    int i, n = 5; // Initial input size

    // Generate worst-case input and run the experiment for 4 trials
    for (int j = 0; j < 4; j++)
    {
        a = (int *)malloc(sizeof(int) * n);

        // Generate a worst-case input (descending order)
        for (int k = 0; k < n; k++)
        {
            a[k] = n - k;
        }

        // Print initial elements
        printf("Elements before sorting: ");
        for (i = 0; i < n; i++)
        {
            printf("%d   ", a[i]);
        }

        // Perform Selection Sort
        selectionSort(a, n);

        // Print sorted elements
        printf("Elements after selection sort: ");
        for (i = 0; i < n; i++)
        {
            printf("%d   ", a[i]);
        }
        printf("\n");

        // Free allocated memory
        free(a);

        // Increase the input size for the next iteration
        n = n + 5;
    }

    return 0;
}
