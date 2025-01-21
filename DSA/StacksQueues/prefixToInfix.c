#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#include <stdio.h>
#include <string.h>

int main() {
    char opr[100] = "expression";
    
    strcat(opr, (char[]){'(', '\0'});  // Append '('
    printf("Result: %s\n", opr);

    strcat(opr, (char[]){')', '\0'});  // Append ')'
    printf("Result: %s\n", opr);

    return 0;
}


// Stack structure to store strings
typedef struct {
    char *data[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push a string onto the stack
void push(Stack *s, char *str) {
    s->data[++(s->top)] = str;
}

// Pop a string from the stack
char *pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to convert prefix to infix
void prefixToInfix(char *prefix) {
    Stack stack;
    initialize(&stack);
    char symbol;
    int length = strlen(prefix);

    // Iterate over the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        symbol = prefix[i];

        // If the symbol is an operand, push it onto the stack
        if (isalnum(symbol)) {
            char *operand = (char *)malloc(2 * sizeof(char));
            operand[0] = symbol;
            operand[1] = '\0';
            push(&stack, operand);
        } else {
            // If the symbol is an operator, pop two operands, create a new expression, and push it back
            char *operand1 = pop(&stack);
            char *operand2 = pop(&stack);

            // Allocate memory for the new expression
            char *expr = (char *)malloc(strlen(operand1) + strlen(operand2) + 4 * sizeof(char));

            // Create the infix expression: "(operand1 operator operand2)"
            strcpy(expr, "(");
            strcat(expr, operand1);
            strcat(expr, &symbol);
            strcat(expr, operand2);
            strcat(expr, ")");

            // Push the new expression back onto the stack
            push(&stack, expr);
        }
    }

    // The final expression is the result
    printf("Infix expression: %s\n", pop(&stack));
}

int main() {
    char prefix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    prefixToInfix(prefix);
    return 0;
}
