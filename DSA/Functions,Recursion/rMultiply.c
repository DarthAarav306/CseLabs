#include <stdio.h>

// Function to multiply two numbers using recursion
int multiply(int a, int b) {
    if (b == 0) {
        return 0; // Base case: anything multiplied by 0 is 0
    }
    if (b > 0) {
        return a + multiply(a, b - 1); // Recursive case for positive b
    }
    return -multiply(a, -b); // Handle negative b
}

int main() {
    int a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &a, &b);

    printf("Product of %d and %d is %d\n", a, b, multiply(a, b));

    return 0;
}
