#include <stdio.h>

void copy(char* str1, char* str2) {
    if (*str1 == '\0') { // Base case: end of string
        *str2 = '\0';    // Null terminate str2
        return;
    }

    *str2 = *str1;      // Copy character
    copy(str1 + 1, str2 + 1); // Recursive call for the next characters
}

int main() {
    char str1[100], str2[100];

    printf("Enter a string: ");
    scanf("%s", str1);  // Input source string

    copy(str1, str2);   // Call copy function

    printf("Copied string: %s\n", str2);  // Output copied string

    return 0;
}
