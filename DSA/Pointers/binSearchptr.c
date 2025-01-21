#include <stdio.h>

int binsearch(int* arr, int n, int key) {
    int* lowptr = arr;             // Pointer to the first element
    int* highptr = arr + n - 1;    // Pointer to the last element
    int* midptr;

    // Binary search loop
    while (lowptr <= highptr) {
        midptr = lowptr + (highptr - lowptr) / 2;  // Calculate the middle pointer

        if (*midptr > key) {
            highptr = midptr - 1;  // Move the high pointer to the left
        } 
        else if (*midptr < key) {
            lowptr = midptr + 1;   // Move the low pointer to the right
        } 
        else {
            return (midptr - arr);  // Key found, return index
        }
    }

    return -1;  // Key not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    // Call binary search and print the result
    int index = binsearch(arr, n, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}
