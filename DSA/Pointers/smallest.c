#include<stdio.h>
#include<stdlib.h> // For malloc

int findSmallest(int* p, int n)
{
    int smallest = *p;
    for(int i = 0; i < n; i++)
    {
        if(*(p + i) < smallest)
        {
            smallest = *(p + i);
        }
    }
    return smallest;
}

int* findMax(int* arr,int n)
{
    int* max = arr;
    int* p = arr;
    for(int i=1;i<n;i++)
    {
        if(*(p+i)>*max)
        {
            max = p+i;
        }
    }
    return max;
}
int main()
{
    int* ptr;
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Corrected malloc syntax
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // Calling the function to find the smallest element
    int smallestElement = findSmallest(ptr, n);
    printf("Smallest element is %d\n", smallestElement);

    // Freeing the dynamically allocated memory
    free(ptr);

    return 0;
}
