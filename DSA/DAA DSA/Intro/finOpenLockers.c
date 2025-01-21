#include <stdio.h>
#include <math.h>

void findOpenLockers(int n)
{
    printf("Open lockers:\n");
    for (int i = 1; i * i <= n; i++)
    {
        printf("%d ", i * i); // Print all perfect squares
    }
    printf("\n");
    printf("Total open lockers: %d\n", (int)sqrt(n));
}

int main()
{
    int n;
    printf("Enter the number of lockers: ");
    scanf("%d", &n);

    findOpenLockers(n);
    return 0;
}
