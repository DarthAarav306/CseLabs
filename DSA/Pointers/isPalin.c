#include <stdio.h>

int isPalin(char str[]) {
    int *p = str;
    int n = 0;

    // Calculate the length of the string
    while (p[n] != '\0') {
        n++;
    }

    // Check for palindrome
    for (int i = 0; i < n / 2; i++) {
        if (*(p + i) != *(p + n - i - 1)) {
            return -1; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (isPalin(str) == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
