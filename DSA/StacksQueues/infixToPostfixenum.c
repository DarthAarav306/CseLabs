#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 0}; // In-stack precedence
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0}; // Incoming precedence

typedef struct {
    precedence stack[MAX];
    int top;
} Stack;

void push(Stack* s, precedence token) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->stack[++(s->top)] = token;
}

precedence pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return eos;
    }
    return s->stack[(s->top)--];
}

precedence get_token(char* symbol, int* n, char* expr) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void print_token(precedence token) {
    switch (token) {
        case plus: printf("+"); break;
        case minus: printf("-"); break;
        case times: printf("*"); break;
        case divide: printf("/"); break;
        case mod: printf("%%"); break;
        default: break;
    }
}

void infix_to_postfix(char* expr) {
    Stack s;
    s.top = -1;
    int n = 0;
    char symbol;
    precedence token = get_token(&symbol, &n, expr);

    push(&s, eos);  // Initialize stack with eos

    while (token != eos) {
        if (token == operand) {
            printf("%c", symbol);  // Directly print operands
        } else if (token == rparen) {
            while (s.stack[s.top] != lparen) {
                print_token(pop(&s));
            }
            pop(&s); // Discard left parenthesis
        } else {
            while (isp[s.stack[s.top]] >= icp[token]) {
                print_token(pop(&s));
            }
            push(&s, token);
        }
        token = get_token(&symbol, &n, expr);
    }

    while (s.top != -1 && s.stack[s.top] != eos) {
        print_token(pop(&s));
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
