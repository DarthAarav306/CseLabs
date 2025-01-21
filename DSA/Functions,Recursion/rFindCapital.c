#include<stdio.h>

int findFirstCapitalIndex(char* str, int index) {
    // Base case: End of string
    if (str[index] == '\0') {
        return -1; // Return -1 if no capital letter is found
    }

    // Check if the current character is a capital letter using ASCII values
    if (str[index] >= 65 && str[index] <= 90) {
        return index; // Return the index if a capital letter is found
    }

    // Recursive call to check the next character
    return findFirstCapitalIndex(str, index + 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int result = findFirstCapitalIndex(str, 0);

    if (result != -1) {
        printf("The first capital letter is at index: %d\n", result);
    } else {
        printf("No capital letter found in the string.\n");
    }

    return 0;
}
