// #include<stdio.h>

// // Function to reverse the string using recursion
// void reverseString(char* str, int index) {
//     // Base case: If the end of the string is reached
//     if (str[index] == '\0') {
//         return;
//     }

//     // Recursive call to move to the next character
//     reverseString(str, index + 1);

//     // Print the current character after the recursive call
//     printf("%c", str[index]);
// }

// int main() {
//     char str[100];

//     printf("Enter a line of text: ");
//     fgets(str, sizeof(str), stdin);  // Read a line of text including spaces

//     printf("Reversed text: ");
//     reverseString(str, 0);  // Start reversing from the first character
//     printf("\n");

//     return 0;
// }
#include<stdio.h>
#include<string.h>

// Recursive function to print the string in reverse
void rreverse(char* str, int n) {
    if (n == 0) {
        return;  // Base case: if the string length is 0, stop recursion
    }
    printf("%c", *(str + (n - 1)));  // Print the last character
    rreverse(str, n - 1);  // Recursive call to reverse the rest of the string
}

int main() {
    char str[100];
    
    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);  // Using scanf to read the string without spaces
    
    int len = strlen(str);  // Get the length of the string

    // Call the recursive function to print the string in reverse
    printf("Reversed string: ");
    rreverse(str, len);
    
    return 0;
}
void rReverse(char* str, int index) {
    if (str[index] == '\0') {
        return; // Base case: When you reach the end of the string, return.
    }
    rReverse(str, index + 1); // Recursive call with the next index.
    printf("%c", str[index]); // Print the character after returning from the recursive call.
}



void reverse(char* str, int index) {
    if (index < 0) { // Base case: If index goes below 0, stop recursion
        return;
    }
    printf("%c", str[index]); // Print the current character
    reverse(str, index - 1);  // Recursive call for the remaining string
}

// Recursive function to reverse a string in place
void reverseInPlace(char* str, int left, int right) {
    if (left >= right) {
        return; // Base case: Stop when the pointers meet or cross
    }

    // Swap characters at the left and right indices
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // Recursive call to reverse the inner part of the string
    reverseInPlace(str, left + 1, right - 1);
}