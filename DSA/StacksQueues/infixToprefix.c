#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void push(Stack* s, char token) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->stack[++(s->top)] = token;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->stack[(s->top)--];
}

char peek(Stack* s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->stack[s->top];
}

int precedence(char token) {
    switch (token) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int is_right_associative(char token) {
    return token == '^';  // Only exponentiation is right-associative
}

// Function to reverse a string and swap '(' with ')' and vice versa
void reverse(char* expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }

    // Swap parentheses while reversing
    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            expr[i] = ')';
        } else if (expr[i] == ')') {
            expr[i] = '(';
        }
    }
}

// Single function to convert infix to prefix
void infix_to_prefix(char* expr, char* result) {
    Stack s;
    s.top = -1;
    char symbol;
    int k = 0;

    // Step 1: Reverse the input expression and swap brackets
    reverse(expr);

    // Step 2: Convert the reversed infix expression to postfix
    for (int i = 0; expr[i] != '\0'; i++) {
        symbol = expr[i];

        if (isalnum(symbol)) {
            result[k++] = symbol;  // Directly append operands
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while (peek(&s) != '(') {
                result[k++] = pop(&s);
            }
            pop(&s);  // Discard the left parenthesis
        } else {
            // Handle precedence and associativity
            while (s.top != -1 && (precedence(peek(&s)) > precedence(symbol) || 
                  (precedence(peek(&s)) == precedence(symbol) && is_right_associative(symbol)))) {
                result[k++] = pop(&s);
            }
            push(&s, symbol);
    result[k] = '\0';     }
    }

    // Pop remaining operators from the stack
    while (s.top != -1) {
        result[k++] = pop(&s);
    }
     // Null-terminate the result

    // Step 3: Reverse the result to get the prefix expression
    reverse(result);
}

int main() {
    char expr[MAX], result[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", expr);

    infix_to_prefix(expr, result);

    printf("Prefix expression: %s\n", result);

    return 0;
}
