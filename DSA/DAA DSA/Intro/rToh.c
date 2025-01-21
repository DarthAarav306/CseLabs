#include <stdio.h>

void toh(int n, char source, char temp, char destination, int *moveCount)
{
    if (n == 1)
    {
        (*moveCount)++; // Increment the move count
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    toh(n - 1, source, destination, temp, moveCount);               // Move n-1 disks to temp
    (*moveCount)++;                                                 // Increment the move count
    printf("Move disk %d from %c to %c\n", n, source, destination); // Move nth disk to destination
    toh(n - 1, temp, source, destination, moveCount);               // Move n-1 disks from temp to destination
}

int main()
{
    int n;
    int moveCount = 0; // Initialize move count to 0

    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\n");

    toh(n, 'A', 'B', 'C', &moveCount);

    printf("\nTotal moves required: %d\n", moveCount); // Output the total number of moves
    return 0;
}
