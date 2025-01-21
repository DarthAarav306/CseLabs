#include<stdio.h>
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int small = arr[i];
        int index = i;  // Initialize index to i
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < small) {
                small = arr[j];
                index = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
