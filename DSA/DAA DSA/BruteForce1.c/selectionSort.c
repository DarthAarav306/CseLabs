#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to perform selection sort and count operations
void selectionSort(int arr[], int n)
{
    int comparisonCount = 0;
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisonCount++; // Count comparisons
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap only if a smaller element is found
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;
        }
    }

    printf("Array Size: %d | Comparisons: %d | Swaps: %d\n", n, comparisonCount, swapCount);
}

// Function to generate a sorted array (Best Case)
void generateBestCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

// Function to generate a reverse sorted array (Worst Case)
void generateWorstCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

int main()
{
    int bestCase[MAX_SIZE], worstCase[MAX_SIZE];
    int size[] = {10, 50, 100, 200, 500, 1000}; // Test sizes
    int numTests = sizeof(size) / sizeof(size[0]);

    printf("Selection Sort Experimental Analysis\n");
    printf("Size\tBest Case Comparisons\tWorst Case Comparisons\n");

    for (int i = 0; i < numTests; i++)
    {
        int n = size[i];

        // Best case scenario (already sorted)
        generateBestCase(bestCase, n);
        printf("Best Case: ");
        selectionSort(bestCase, n);

        // Worst case scenario (reverse sorted)
        generateWorstCase(worstCase, n);
        printf("Worst Case: ");
        selectionSort(worstCase, n);

        printf("\n");
    }

    return 0;
}
