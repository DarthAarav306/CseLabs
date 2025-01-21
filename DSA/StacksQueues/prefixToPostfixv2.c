#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char* stack[MAX];  // Stack now holds strings (char pointers)
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char* ele) {
    if (isFull(s)) {
        printf("\nStack is full");
    } else {
        s->stack[++(s->top)] = ele;
    }
}
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("\nStack is empty");
        return NULL;  // Return NULL if stack is empty
    } else {
        return s->stack[(s->top)--];
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    char expr[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        // If the character is an operand
        if (isalnum(expr[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));  // 2 chars: operand + '\0'
            operand[0] = expr[i];
            operand[1] = '\0';
            push(&stack, operand);
        }
        // If the character is an operator
        else if (!isalnum(expr[i])) {
            char* op1 = pop(&stack);
            char* op2 = pop(&stack);

            // Convert the operator to a string
            char operator[2];
            operator[0] = expr[i];
            operator[1] = '\0';

            // Concatenate op1, op2, and operator directly to op1
            strcat(op1, op2);        // Append op2 to op1
            strcat(op1, operator);   // Append operator to op1

            // Push the result back onto the stack
            push(&stack, op1);

            // Free temporary operand op2
            free(op2);
        }
    }

    // The final postfix expression is at the top of the stack
    char* postfix = pop(&stack);
    printf("Postfix expression: %s\n", postfix);

    // Free the postfix expression
    free(postfix);

    return 0;
}
