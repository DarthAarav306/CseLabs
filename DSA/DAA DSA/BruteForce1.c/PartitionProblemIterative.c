#include <stdio.h>

// Function to check if a partition exists using bitwise subset generation
int canPartitionIterative(int arr[], int n)
{
    int totalSum = 0;

    // Compute total sum
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // If sum is odd, partition is impossible
    if (totalSum % 2 != 0)
        return 0;

    int target = totalSum / 2;
    int subsetCount = 1 << n; // 2^n subsets

    // Iterate through all subsets using bitwise representation
    for (int mask = 0; mask < subsetCount; mask++)
    {
        int subsetSum = 0;

        // Construct subset based on bits in the mask
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j)) // If j-th bit is set, include arr[j] in subset
                subsetSum += arr[j];
        }

        // If any subset has sum = target, partitioning is possible
        if (subsetSum == target)
            return 1;
    }
    return 0;
}

int main()
{
    int arr[] = {3, 1, 5, 9, 12}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartitionIterative(arr, n))
        printf("Partition is possible\n");
    else
        printf("Partition is NOT possible\n");

    return 0;
}
