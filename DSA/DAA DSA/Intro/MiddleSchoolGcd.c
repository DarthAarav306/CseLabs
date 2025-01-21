#include <stdio.h>

// Function to compute the prime factorization of a number
void primeFactorization(int num, int factors[], int *size)
{
    int i = 2;     // Start from the smallest prime number
    *size = 0;     // Initialize the count of prime factors
    int count = 0; // Count operations in prime factorization

    while (num > 1)
    {
        count++; // Increment the operation count
        if (num % i == 0)
        {
            factors[(*size)++] = i; // Store the factor
            num /= i;               // Reduce the number
        }
        else
        {
            i++; // Move to the next number
        }
    }
    printf("Prime factorization took %d operations.\n", count);
}

// Function to compute GCD using middle school method
int gcdMiddleSchool(int m, int n)
{
    int factorsM[100], sizeM; // Prime factors of m
    int factorsN[100], sizeN; // Prime factors of n
    int gcd = 1;              // Initialize GCD as 1

    // Get prime factorizations
    printf("Finding prime factors of %d:\n", m);
    primeFactorization(m, factorsM, &sizeM);
    printf("Finding prime factors of %d:\n", n);
    primeFactorization(n, factorsN, &sizeN);

    // Find common factors
    int count = 0; // Count operations in finding common factors
    int i = 0, j = 0;
    while (i < sizeM && j < sizeN)
    {
        count++; // Increment operation count
        if (factorsM[i] == factorsN[j])
        {
            gcd *= factorsM[i]; // Multiply common factor to GCD
            i++;
            j++;
        }
        else if (factorsM[i] < factorsN[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    printf("Finding common factors took %d operations.\n", count);
    return gcd;
}

int main()
{
    int m, n;

    // Input two numbers
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &m, &n);

    // Ensure non-negative inputs
    if (m < 0)
        m = -m;
    if (n < 0)
        n = -n;

    // Compute GCD using middle school method
    int result = gcdMiddleSchool(m, n);

    // Output the result
    printf("The GCD of %d and %d is: %d\n", m, n, result);

    return 0;
}
