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

// Function to concatenate three strings manually
char* concatenate(char* operator, char* operand1, char* operand2) {
    int len1 = strlen(operand1);
    int len2 = strlen(operand2);
    
    // Allocate memory for the new string
    char* result = (char*)malloc((len1 + len2 + 2) * sizeof(char));  // +2 for operator and null terminator
    
    // Copy operator to result
    result[0] = operator[0];
    result[1] = '\0';
    
    // Concatenate operand1 and operand2
    strcat(result, operand1);
    strcat(result, operand2);
    
    return result;
}

// Function to convert postfix to prefix
void postfixToPrefix(char* postfix) {
    Stack stack;
    initialize(&stack);
    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        // If the character is an operand, push it onto the stack
        if (isalnum(postfix[i])) {
            // Allocate memory for the operand and push it onto the stack
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(&stack, operand);
        } else {
            // If the character is an operator
            char* operand2 = pop(&stack);
            char* operand1 = pop(&stack);

            // Manually concatenate the strings
            char operator[2] = {postfix[i], '\0'};
            char* result = concatenate(operator, operand1, operand2);

            // Push the result back to the stack
            push(&stack, result);
        }
    }

    // The final prefix expression will be on top of the stack
    char* prefix = pop(&stack);
    printf("Prefix Expression: %s\n", prefix);
}

// Main function
int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    postfixToPrefix(postfix);

    return 0;
}
