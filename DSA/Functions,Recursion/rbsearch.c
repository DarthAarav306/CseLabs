#include <stdio.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        // Check if the key is at mid
        if (arr[mid] == key)
            return mid;

        // If key is smaller, search the left half
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        // Otherwise, search the right half
        return binarySearch(arr, mid + 1, high, key);
    }

    // Key not found
    return -1;
}

int main() {
    int n, key;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read the sorted array elements
    printf("Enter %d sorted elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Output the result
    if(result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
