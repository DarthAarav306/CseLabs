#include<stdio.h>

void reverse(int* p, int n)
{
    for(int i = 0; i < n / 2; i++)
    {
        int temp = *(p + i);
        *(p + i) = *(p + n - i - 1);  // Corrected this line
        *(p + n - i - 1) = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse(arr, n);

    printf("Reversed array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
