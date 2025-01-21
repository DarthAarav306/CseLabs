#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int data[MAX];
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

// Push an element onto the stack
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->data[++(s->top)] = value;
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;  // Return a sentinel value
    } else {
        return s->data[(s->top)--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);
    int length = strlen(expression);

    // Scan the expression from left to right
    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            // If the character is an operand, convert it to an integer and push onto the stack
            push(&stack, expression[i] - '0');  // '0' is subtracted to convert char to int
        } else {
            // If the character is an operator, pop two elements from the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            // Apply the operator
            int result;
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Unsupported operator encountered: %c\n", expression[i]);
                    exit(EXIT_FAILURE);
            }

            // Push the result back onto the stack
            push(&stack, result);
        }
    }

    // The final result will be on top of the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
