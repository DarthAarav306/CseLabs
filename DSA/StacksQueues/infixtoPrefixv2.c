#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
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

void push(Stack* s, char ele) {
    if (isFull(s)) {
        printf("\nStack is full");
    } else {
        s->stack[++(s->top)] = ele;
    }
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("\nStack is empty");
        return '\0';  // Return null character if stack is empty
    } else {
        return s->stack[(s->top)--];
    }
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';  // Return null character if stack is empty
    } else {
        return s->stack[s->top];
    }
}

void reverse(char* expr, int len) {
    // Reversing
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
    // Exchanging brackets
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') {
            expr[i] = ')';
        } else if (expr[i] == ')') {
            expr[i] = '(';
        }
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return (op == '^');
}

int main() {
    Stack stack;
    initialize(&stack);  // Initialize the stack before using it

    char expr[100];
    printf("\nEnter expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    reverse(expr, len);

    char postfix[MAX];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalnum(expr[i])) {
            postfix[j++] = expr[i];  // Add operand to the result
        }
        else if (expr[i] == ')') {
            push(&stack, expr[i]);
        }
        else if (expr[i] == '(') {
            while (peek(&stack) != ')' && !isEmpty(&stack)) {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop the closing parenthesis
        }
        else {
            // Operator case
            while (!isEmpty(&stack) && 
                   ((precedence(peek(&stack)) > precedence(expr[i])) || 
                   (precedence(peek(&stack)) == precedence(expr[i]) && isRightAssociative(peek(&stack))))) {
                postfix[j++] = pop(&stack);  
            }
            push(&stack, expr[i]);
        }
    }

    // Pop all remaining operators in the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    // Reverse the postfix expression to get the final prefix expression
    int newlen = strlen(postfix);
    reverse(postfix, newlen);

    printf("Prefix is: %s\n", postfix);

    return 0;
}
