#include <stdio.h>

void primeSieve(int n)
{
    int prime[100]; // Declare an array for marking primes

    // Initialize all elements to 1 (assume all are prime initially)
    for (int i = 0; i < 100; i++)
    {
        prime[i] = 1; // Explicitly set all elements to 1
    }

    // Mark non-prime numbers
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == 1)
        { // If i is prime
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0; // Mark all multiples of i as not prime
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        { // If i is prime
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    primeSieve(n);

    return 0;
}
