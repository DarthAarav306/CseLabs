#include<stdio.h>

int len(char* str) {
    if (*str == '\0') {
        return 0; // Base case: end of string
    }
    return 1 + len(str + 1); // Recursive case: count this character and proceed
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    printf("\nLength of string is %d\n", len(str));
    return 0;
}
