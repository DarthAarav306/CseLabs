#include <stdio.h>

void insert(int arr[], int pos, int n, int ele) {
    // Shift elements to the right from the position
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the element at the specified position
    arr[pos] = ele;
}

void delete(int arr[], int pos, int n) {
    // Shift elements to the left from the position
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

