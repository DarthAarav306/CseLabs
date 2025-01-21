#include <stdio.h>

int binarySearch(int *arr, int n, int key) {
    int *low = arr;
    int *high = arr + n - 1;

    while (low <= high) {
        int *mid = low + (high - low) / 2;

        if (*mid == key) {
            return mid - arr; // Returning the index of the key
        } else if (*mid < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // If the key is not found
}

int main() {
    int n, key;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read the elements of the array (must be sorted)
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
