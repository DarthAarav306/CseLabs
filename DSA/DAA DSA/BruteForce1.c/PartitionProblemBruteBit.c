#include <stdio.h>
#include <math.h>

// Function to print a subset
void printSubset(int arr[], int n, int subsetMask, int *operationCount)
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        (*operationCount)++;              // Count the operation for checking each bit
        if ((subsetMask & (1 << i)) != 0) // Check if the i-th element is in the subset
        {
            printf("%d ", arr[i]);
        }
    }
    printf("}\n");
}

// Function to find a valid partition using the power set
int findPartition(int arr[], int n, int *operationCount)
{
    int totalSum = 0;
    int i, j;

    // Compute the total sum of the set
    for (i = 0; i < n; i++)
    {
        totalSum += arr[i];
        (*operationCount)++; // Count the operation for each addition
    }

    // If the sum is odd, partitioning is impossible
    if (totalSum % 2 != 0)
    {
        return 0; // No partition possible
    }

    int targetSum = totalSum / 2;
    int totalSubsets = pow(2, n); // Total subsets = 2^n

    // Generate all subsets using bitwise operations
    for (i = 0; i < totalSubsets; i++)
    {
        int subsetSum = 0;

        for (j = 0; j < n; j++)
        {
            (*operationCount)++;     // Count the operation for each bitwise operation
            if ((i & (1 << j)) != 0) // Check if the j-th element is in the subset
            {
                subsetSum += arr[j];
                (*operationCount)++; // Count the operation for each addition in subset sum
            }
        }

        // If subset sum matches target sum, print the partition
        if (subsetSum == targetSum)
        {
            printf("Partition found:\nSubset 1: ");
            printSubset(arr, n, i, operationCount);

            printf("Subset 2: ");
            printSubset(arr, n, ~i & ((1 << n) - 1), operationCount); // Elements not in subset 1

            return 1; // Partition found
        }
    }

    return 0; // No partition found
}

int main()
{
    int n, i;
    int operationCount = 0; // Initialize the operation counter

    // Input the size of the set
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the set elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Check for partition possibility
    if (findPartition(arr, n, &operationCount) == 0)
    {
        printf("The set cannot be partitioned into two subsets with equal sum.\n");
    }

    // Print the total number of operations
    printf("Total operations performed: %d\n", operationCount);

    return 0;
}
