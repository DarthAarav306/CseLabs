#include <stdio.h>

// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n, int *operationCount)
{
    (*operationCount)++; // Increment operation count for every function call

    if (n == 0)
    {
        return 0; // Base case: F(0) = 0
    }
    if (n == 1)
    {
        return 1; // Base case: F(1) = 1
    }

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1, operationCount) + fibonacci(n - 2, operationCount);
}

int main()
{
    int n;
    int operationCount = 0; // To count the number of recursive calls

    // Input the value of n
    printf("Enter the value of n to find the nth Fibonacci number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid input! n must be a non-negative integer.\n");
        return 1;
    }

    // Compute the nth Fibonacci number
    int result = fibonacci(n, &operationCount);

    // Output the result and operation count
    printf("The %dth Fibonacci number is: %d\n", n, result);
    printf("Total recursive calls made: %d\n", operationCount);

    return 0;
}
