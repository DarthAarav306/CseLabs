#include <stdio.h>

// Function to find all factors of a number
void primeFactorisation(int num, int factors[], int *size)
{
    int k = 0;
    for (int i = 1; i <= num / 2; i++)
    { // Find divisors
        if (num % i == 0)
        {
            factors[k] = i; // Store the factor
            k++;
        }
    }
    factors[k] = num; // Include the number itself as a factor
    *size = k + 1;    // Total number of factors
}

// Function to compute GCD using the middle school method
int gcdMiddleSchool(int m, int n)
{
    int mFactors[m];  // Using m as an upper limit for size
    int nFactors[n];  // Using n as an upper limit for size
    int mSize, nSize; // Sizes of the factor arrays
    int gcd = 1;      // Initialize GCD

    // Get factors of m and n
    primeFactorisation(m, mFactors, &mSize);
    primeFactorisation(n, nFactors, &nSize);

    int i = 0, j = 0;

    // Find the common factors and compute the GCD
    while (i < mSize && j < nSize)
    {
        if (mFactors[i] == nFactors[j])
        {
            gcd = mFactors[i]; // Update GCD to the current common factor
            i++;
            j++;
        }
        else if (mFactors[i] < nFactors[j])
        {
            i++; // Move to the next factor of m
        }
        else
        {
            j++; // Move to the next factor of n
        }
    }

    return gcd; // Return the final GCD
}

int main()
{
    int m, n;

    // Input two numbers
    printf("Enter two positive integers: ");
    scanf("%d %d", &m, &n);

    // Compute the GCD using the middle school method
    int gcd = gcdMiddleSchool(m, n);

    // Output the result
    printf("GCD of %d and %d is: %d\n", m, n, gcd);

    return 0;
}
