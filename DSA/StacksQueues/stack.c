#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define Stack structure
typedef struct {
    int stack[MAX];  // Array to store stack elements (renamed to 'stack')
    int top;         // Tracks the top index of the stack
} Stack;

// Initialize stack
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
        s->stack[++(s->top)] = value;  // Increment top and then add element to 'stack'
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;  // Return a sentinel value for underflow
    } else {
        return s->stack[(s->top)--];  // Return the top element from 'stack' and decrement top
    }
}

// Peek the top element without popping it
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->stack[s->top];  // Return the top element from 'stack'
    }
}

// Display the elements of the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->stack[i]);  // Access elements from 'stack'
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initialize(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    display(&stack);
    
    printf("Popped: %d\n", pop(&stack));
    display(&stack);
    
    printf("Top element is: %d\n", peek(&stack));
    
    return 0;
}
