#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapCount = 0, compCount = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            compCount++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }

    printf("Comparisons: %d | Swaps: %d\n", compCount, swapCount);
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

void generateRandomCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (n * 10); // Random number between 0 and 10*n
    }
}

int main()
{
    int *bestCase, *worstCase, *randomCase;
    int size[] = {10, 50, 100, 200, 500, 1000};
    int numTests = sizeof(size) / sizeof(size[0]);

    srand(time(0));

    printf("Bubble Sort Experimental Analysis\n");
    printf("Size\tBest Case Comparisons\tWorst Case Comparisons\tRandom Case Comparisons\n");

    for (int i = 0; i < numTests; i++)
    {
        int n = size[i];

        bestCase = (int *)malloc(sizeof(int) * n);
        worstCase = (int *)malloc(sizeof(int) * n);
        randomCase = (int *)malloc(sizeof(int) * n);

        printf("For N = %d:\n", n);

        generateBestCase(bestCase, n);
        printf("Best Case: ");
        bubbleSort(bestCase, n);

        generateWorstCase(worstCase, n);
        printf("Worst Case: ");
        bubbleSort(worstCase, n);

        // Random Case
        generateRandomCase(randomCase, n);
        printf("Random Case: ");
        bubbleSort(randomCase, n);

        printf("\n");

        free(bestCase);
        free(worstCase);
        free(randomCase);
    }

    return 0;
}
