#include <stdio.h>

// Recursive function to check if a subset with given sum exists
int isPartitionPossible(int arr[], int n, int index, int currentSum, int targetSum)
{
    // If we find a subset with sum = targetSum, return true
    if (currentSum == targetSum)
        return 1;

    // If we go out of bounds or exceed sum, return false
    if (index >= n || currentSum > targetSum)
        return 0;

    // Recursive case:
    // 1. Include the current element in subset
    // 2. Exclude the current element from subset
    return isPartitionPossible(arr, n, index + 1, currentSum + arr[index], targetSum) ||
           isPartitionPossible(arr, n, index + 1, currentSum, targetSum);
}

// Function to check if the array can be partitioned
int canPartition(int arr[], int n)
{
    int totalSum = 0;

    // Compute total sum
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // If total sum is odd, we cannot partition it into equal subsets
    if (totalSum % 2 != 0)
        return 0;

    // Use recursion to check if subset sum = totalSum/2 exists
    return isPartitionPossible(arr, n, 0, 0, totalSum / 2);
}

int main()
{
    int arr[] = {3, 1, 5, 9, 12}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n))
        printf("Partition is possible\n");
    else
        printf("Partition is NOT possible\n");

    return 0;
}
