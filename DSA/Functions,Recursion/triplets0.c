#include<stdio.h>

void findTriplets(int* arr, int n) {
    int found = 0; // Flag to check if any triplet is found
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {  // Ensure k > j > i to avoid duplicate triplets
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("No triplets found\n");
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

    findTriplets(arr, n);

    return 0;
}
