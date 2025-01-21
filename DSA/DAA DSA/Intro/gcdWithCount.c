#include <stdio.h>

// Function to compute GCD using Euclid's Algorithm and count operations
int gcdWithCount(int a, int b)
{
    int count = 0; // Initialize operation count
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
        count++; // Increment operation count
    }
    printf("Total operations performed: %d\n", count); // Print operation count
    return a;
}

int main()
{
    int num1, num2;

    // Input two integers
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    // Ensure non-negative inputs
    if (num1 < 0)
        num1 = -num1;
    if (num2 < 0)
        num2 = -num2;

    // Call the GCD function and display the result
    int result = gcdWithCount(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
