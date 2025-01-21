#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
int precedence(char token) {
    switch (token) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3; // Higher precedence for exponentiation
        default: return 0;
    }
}

int is_right_associative(char token) {
    // Only exponentiation is right associative
    return token == '^';
}

void infix_to_postfix(char* expr) {
    Stack s;
    s.top = -1;
    char symbol;

    for (int i = 0; expr[i] != '\0'; i++) {
        symbol = expr[i];
        if (isdigit(symbol) || isalpha(symbol)) {
            printf("%c", symbol);  // Directly print operands
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while (s.stack[s.top] != '(') {
                printf("%c", pop(&s));
            }
            pop(&s); // Discard left parenthesis
        } else {
            // Corrected condition to handle associativity properly
            while (s.top != -1 &&
                   (precedence(s.stack[s.top]) > precedence(symbol) || 
                   (precedence(s.stack[s.top]) == precedence(symbol) && !is_right_associative(symbol)))) {
                printf("%c", pop(&s));
            }
            push(&s, symbol);
        }
    }

    while (s.top != -1) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expr);

    printf("Postfix expression: ");
    infix_to_postfix(expr);

    return 0;
}
