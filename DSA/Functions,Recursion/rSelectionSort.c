#include<stdio.h>

void rselectionSort(int arr[], int start, int n) {
    // Base case: If starting index is the last index, sorting is done
    if (start >= n - 1) {
        return;
    }

    int smallIndex = start;
    for (int j = start + 1; j < n; j++) {
        if (arr[j] < arr[smallIndex]) {
            smallIndex = j;
        }
    }

    // Swap the found minimum element with the first element of the unsorted part
    int temp = arr[start];
    arr[start] = arr[smallIndex];
    arr[smallIndex] = temp;

    // Recursively sort the remaining array
    rselectionSort(arr, start + 1, n);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rselectionSort(arr, 0, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


