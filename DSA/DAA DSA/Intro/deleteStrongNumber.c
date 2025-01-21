#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

// Function to check if a number is a strong number
int isStrongNumber(int num)
{
    int sum = 0, temp = num;

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return sum == num;
}

// Recursive function to delete strong numbers from the array
int deleteStrongNumbers(int arr[], int n, int index)
{
    // Base case: If we reach the end of the array
    if (index == n)
    {
        return n; // Return the new size of the array
    }

    // Check if the current number is a strong number
    if (isStrongNumber(arr[index]))
    {
        // Shift all elements to the left
        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        // Reduce the size of the array and recursively check the current index
        return deleteStrongNumbers(arr, n - 1, index);
    }

    // Move to the next element
    return deleteStrongNumbers(arr, n, index + 1);
}

int main()
{
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Delete strong numbers from the array
    int newSize = deleteStrongNumbers(arr, n, 0);

    // Output the modified array
    printf("Array after deleting strong numbers:\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
