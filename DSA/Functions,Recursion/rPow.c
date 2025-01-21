#include <stdio.h>

// Recursive function to compute x raised to the power y
double power(double x, int y) {
    if (y == 0) {
        return 1;  // Base case: any number raised to 0 is 1
    } else if (y > 0) {
        return x * power(x, y - 1);  // Recursive case for positive exponent
    } else {
        return 1 / power(x, -y);  // Recursive case for negative exponent
    }
}

int main() {
    double x;
    int y;

    printf("Enter the base (x): ");
    scanf("%lf", &x);

    printf("Enter the exponent (y): ");
    scanf("%d", &y);

    double result = power(x, y);

    printf("%.2lf raised to the power %d is %.2lf\n", x, y, result);

    return 0;
}
