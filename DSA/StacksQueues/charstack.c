#include <stdio.h>
#define MAX 100

// Define the Stack structure
typedef struct {
    char stack[MAX];
    int top;
} Stack;

// Function to check if the stack is empty
int isEmpty(Stack* p) {
   return p->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* p) {
    return p->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* p, char ele) {
    if (isFull(p)) {
        printf("Overflow!\n");
    } else {
        p->stack[++(p->top)] = ele; // Increment top and then push the element
        printf("Pushed '%c'\n", ele);
    }
}

// Function to pop an element from the stack
char pop(Stack* p) {
    if (isEmpty(p)) {
        printf("Underflow!\n");
        return '\0';  // Return null character instead of NULL
    } else {
        char ele = p->stack[(p->top)--];  // Pop the element and then decrement top
        printf("'%c' popped\n", ele);
        return ele;
    }
}

// Function to display the stack elements
void display(Stack* s) {
    printf("Displaying:- \n");
    if (isEmpty(s)) {
        printf("Empty stack\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%c\n", s->stack[i]);
        }
    }
}

// Main function
int main() {
    int ch;
    char ele;
    Stack stack;
    stack.top = -1;  // Initialize the top of the stack

    while (1) {
        printf("Enter choice:-\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &ch);  // Use &ch instead of &choice

        switch (ch) {
            case 1:
                printf("Enter element you want to push: ");
                scanf(" %c", &ele);  // Use " %c" to properly read the character input
                push(&stack, ele);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter valid choice\n");
        }
    }

    return 0;
}
