#include <stdio.h>
#include <stdlib.h>

// Bubble Sort function with operation count
void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    int comparisonCount = 0, swapCount = 0;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // To check if swapping happened
        for (j = 0; j < n - i - 1; j++)
        {
            comparisonCount++; // Count comparisons
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
                swapped = 1;
            }
        }
        // If no swap happened, array is already sorted (best case)
        if (swapped == 0)
        {
            break;
        }
    }

    printf("\nArray Size: %d | Comparisons: %d | Swaps: %d\n", n, comparisonCount, swapCount);
}

void generateBestCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}

void generateWorstCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}

int main()
{
    int *bestCase, *worstCase;
    int size[] = {10, 50, 100, 200, 500, 1000}; // Test sizes
    int numTests = sizeof(size) / sizeof(size[0]);

    printf("Bubble Sort Experimental Analysis\n");
    printf("Size\tBest Case Comparisons\tWorst Case Comparisons\n");

    for (int i = 0; i < numTests; i++)
    {
        int n = size[i];

        bestCase = (int *)malloc(sizeof(int) * n);
        worstCase = (int *)malloc(sizeof(int) * n);

        // Best Case (Already Sorted)
        generateBestCase(bestCase, n);
        printf("Best Case: ");
        bubbleSort(bestCase, n);

        // Worst Case (Reverse Sorted)
        generateWorstCase(worstCase, n);
        printf("Worst Case: ");
        bubbleSort(worstCase, n);

        printf("\n");

        free(bestCase);
        free(worstCase);
    }

    return 0;
}
