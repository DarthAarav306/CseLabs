#include <stdio.h>
#include <stdbool.h>

// Function to check if a given string is a palindrome
bool Palindrome(char* str) {
    char *start = str;                   // Pointer to the beginning of the string
    char *end = str;                     // Pointer to the end of the string

    // Move the end pointer to the last character of the string
    while (*end != '\0') {
        end++;
    }
    end--; // Move one step back to skip the null terminator

    // Compare characters from the start and end of the string
    while (start < end) {
        if (*start != *end) {
            return false;                // If characters don't match, it's not a palindrome
        }
        start++;                         // Move the start pointer forward
        end--;                           // Move the end pointer backward
    }

    return true;                         // If all characters match, it's a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (Palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
