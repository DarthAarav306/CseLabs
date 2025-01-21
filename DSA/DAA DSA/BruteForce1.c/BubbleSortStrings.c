#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to swap two strings
void swap(char str1[], char str2[])
{
    char temp[MAX_LENGTH];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Bubble Sort for strings
void bubbleSort(char arr[][MAX_LENGTH], int n, long long *operation_count)
{
    *operation_count = 0; // Initialize operation count

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // Optimization to stop if already sorted

        for (int j = 0; j < n - i - 1; j++)
        {
            (*operation_count)++; // Counting string comparisons

            if (strcmp(arr[j], arr[j + 1]) > 0)
            { // Lexicographical comparison
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break; // Stop if no swaps in a pass
    }
}

// Function to print an array of strings
void printArray(char arr[][MAX_LENGTH], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}

// Main function
int main()
{
    int n;
    char arr[MAX_STRINGS][MAX_LENGTH];
    long long operation_count;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]); // Reading strings without spaces
    }

    bubbleSort(arr, n, &operation_count);

    printf("\nSorted Strings:\n");
    printArray(arr, n);

    printf("\nTotal comparisons performed: %lld\n", operation_count);

    return 0;
}
