#include <stdio.h>
#include <string.h>

// Function definition here
int isPalin(char str[], int low, int high) {
    if (low == high) {
        return 1;
    }
    if (low > high) {
        return 1;
    }
    if (str[low] != str[high]) {
        return 0;
    }
    return isPalin(str, low + 1, high - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalin(str, 0, strlen(str) - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
