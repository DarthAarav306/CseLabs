#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 50

typedef struct {
    char** Strings;
    int size;
} StringArray;

void findLongestWord(StringArray* strArray, int index, char** longestWord); //Prototype
void displayLongestWord(char* longestWord); //Prototype
int rlength(char* string); //Prototype

int main() {
    StringArray strarr;

    // Input the number of strings
    printf("Enter number of strings: ");
    scanf("%d", &strarr.size);

    // Dynamically allocate memory for the strings
    strarr.Strings = (char**)malloc(strarr.size * sizeof(char*));
    for (int i = 0; i < strarr.size; i++) {
        strarr.Strings[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
    }

    // Input strings
    printf("\nEnter %d strings: \n", strarr.size);
    for (int i = 0; i < strarr.size; i++) {
        scanf("%s", strarr.Strings[i]);
    }

    // Initialize the longest word
    char* longestword = strarr.Strings[0];
    findLongestWord(&strarr, 1, &longestword);

    // Display the longest word
    displayLongestWord(longestword);

    // Free dynamically allocated memory
    for (int i = 0; i < strarr.size; i++) {
        free(strarr.Strings[i]);
    }
    free(strarr.Strings);

    return 0;
}

// Function to find the longest word recursively
void findLongestWord(StringArray* strArray, int index, char** longestWord) {
    if (index == strArray->size) {
        return; // Base case: if index reaches size, stop recursion
    }

    if (rlength(strArray->Strings[index]) > rlength(*longestWord)) {
        *longestWord = strArray->Strings[index];  // Update the longest word
    }

    findLongestWord(strArray, index + 1, longestWord);  // Recursive call
}

// Function to display the longest word
void displayLongestWord(char* longestWord) {
    printf("The longest word is: %s\n", longestWord);
}

// Recursive function to calculate the length of a string
int rlength(char* string) {
    if (*string == '\0') {
        return 0;  // Base case: end of string
    }
    return 1 + rlength(string + 1);  // Recursive case: increment and check next character
}
