#include <stdio.h>

// Function to compute floor(sqrt(n)) using basic arithmetic
int computeFloorSqrt(int n)
{
    int x = 1;          // Start from 1
    int operations = 0; // Operation counter

    while (x * x <= n)
    {
        x++;          // Increment x
        operations++; // Increment operation count
    }

    printf("Total operations performed: %d\n", operations);
    return x - 1; // Return the largest integer whose square is <= n
}

int main()
{
    int n;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Input must be a positive integer.\n");
        return 1;
    }

    // Compute the floor of the square root of n
    int result = computeFloorSqrt(n);

    // Output the result
    printf("The floor of the square root of %d is: %d\n", n, result);

    return 0;
}
