#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure to store strings
typedef struct {
    char* data[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Push a string onto the stack
void push(Stack* s, char* str) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->data[++(s->top)] = str;
    }
}

// Pop a string from the stack
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        return s->data[(s->top)--];
    }
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to concatenate three strings manually
char* concatenate(char* operand1, char* operand2, char operator) {
    int len1 = strlen(operand1);
    int len2 = strlen(operand2);
    
    // Allocate memory for the new string
    char* result = (char*)malloc((len1 + len2 + 2) * sizeof(char));  // +2 for operator and null terminator
    
    // Copy operand1 to result
    strcpy(result, operand1);
    
    // Concatenate operand2
    strcat(result, operand2);
    
    // Concatenate operator
    result[len1 + len2] = operator;
    result[len1 + len2 + 1] = '\0';  // Null-terminate the string
    
    return result;
}

// Function to convert prefix to postfix
void prefixToPostfix(char* prefix) {
    Stack stack;
    initialize(&stack);
    int length = strlen(prefix);

    // Reverse the prefix expression
    reverse(prefix);

    for (int i = 0; i < length; i++) {
        // If the character is an operand, push it onto the stack
        if (isalnum(prefix[i])) {
            // Allocate memory for the operand and push it onto the stack
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(&stack, operand);
        } else {
            // If the character is an operator
            char* operand1 = pop(&stack);
            char* operand2 = pop(&stack);

            // Manually concatenate the strings
            char* result = concatenate(operand1, operand2, prefix[i]);

            // Push the result back to the stack
            push(&stack, result);
        }
    }

    // The final postfix expression will be on top of the stack
    char* postfix = pop(&stack);
    printf("Postfix Expression: %s\n", postfix);
}

// Main function
int main() {
    char prefix[MAX];
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}
