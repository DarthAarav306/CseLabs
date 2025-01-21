#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int n;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}
