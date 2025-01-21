#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void push(Stack* s, char c) {
    s->stack[++(s->top)] = c;
}

char pop(Stack* s) {
    return s->stack[(s->top)--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int main() {
    Stack stack;
    stack.top = -1;  // Initialize the top of the stack to -1
    char expr[MAX];
    
    printf("Enter expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    int pmatch = 1;  // Flag to check if parentheses match

    for (int i = 0; i < len; i++) {
        // Push only opening parentheses
        if (expr[i] == '(') {
            push(&stack, expr[i]);
        }
        // Check for closing parentheses and pop
        else if (expr[i] == ')') {
            if (isEmpty(&stack)) {  // If stack is empty, there's no matching '('
                pmatch = 0;  // No match
                break;
            } else {
                pop(&stack);  // Pop the matching '('
            }
        }
        // Ignore all other characters (like letters and operators)
    }

    // After iterating, check if stack is empty, otherwise unmatched '(' remains
    if (!isEmpty(&stack)) {
        pmatch = 0;  // If stack is not empty, parentheses don't match
    }

    if (pmatch) {
        printf("Parentheses match\n");
    } else {
        printf("Parentheses don't match\n");
    }

    return 0;
}
