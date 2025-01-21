#include <stdio.h>
#include <stdio.h>

// Function to calculate GCD using Consecutive Integer Checking Method
int gcdCIC(int m, int n)
{
    int t = m < n ? m : n;  // Start with the smaller of the two numbers
    int operationCount = 0; // Initialize operation count

    // Iterate until we find the GCD
    while (m % t != 0 || n % t != 0)
    {                     // Both conditions must hold for GCD
        operationCount++; // Increment operation count for each iteration
        t--;              // Decrease t by 1
    }
    operationCount++; // Count for the final successful check

    // Print the operation count directly
    printf("Number of operations performed: %d\n", operationCount);
    return t; // Return the GCD
}

int main()
{
    int m, n, gcd;

    // Input two numbers
    printf("Enter two positive integers: ");
    scanf("%d %d", &m, &n);

    // Compute GCD using CIC method
    gcd = gcdCIC(m, n);

    // Output the results
    printf("GCD of %d and %d is: %d\n", m, n, gcd);

    return 0;
}

// Function to find GCD using Consecutive Integer Checking Method
int gcdConsecutive(int a, int b)
{
    int min = (a < b) ? a : b; // Find the smaller number
    int gcd = 1;               // Initialize GCD
    int count = 0;             // Counter for the number of iterations

    for (int i = min; i >= 1; i--)
    {
        count++; // Increment iteration count
        if (a % i == 0 && b % i == 0)
        {
            gcd = i; // Found the GCD
            break;
        }
    }

    printf("Total iterations performed: %d\n", count); // Print iteration count
    return gcd;
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
    int result = gcdConsecutive(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
