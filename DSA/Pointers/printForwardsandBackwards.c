#include <stdio.h>

int main() {
    int n;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *p;

    // Print the array in forward direction
    printf("Array in forward direction: ");
    for (p = arr; p != arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // Print the array in backward direction
    printf("Array in backward direction: ");
    // Move the pointer back to the last element
    for (p = arr + n - 1; p >= arr; p--) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
