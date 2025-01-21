#include <stdio.h>

// Function to find the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: 0th Fibonacci number is 0
    }
    if (n == 1) {
        return 1; // Base case: 1st Fibonacci number is 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;
    printf("Enter the position in Fibonacci series: ");
    scanf("%d", &n);

    printf("%dth Fibonacci number is %d\n", n, fibonacci(n));

    return 0;
}
