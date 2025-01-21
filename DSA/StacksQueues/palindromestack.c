#include <stdio.h>
#include <string.h>
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
    }
}

// Function to pop an element from the stack
char pop(Stack* p) {
    if (isEmpty(p)) {
        printf("Underflow!\n");
        return '\0';  // Return null character instead of NULL
    } else {
        char ele = p->stack[(p->top)--];  // Pop the element and then decrement top
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

// Convert a character to lowercase
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int main() {
    Stack stack;
    Stack *s = &stack;
    s->top = -1;
    char string[100];
    printf("\nEnter a string: ");
    scanf("%s", string);
    int len = strlen(string);
    
    // Push all characters to stack in lowercase
    for (int i = 0; i < len; i++) {
        push(&stack, toLower(string[i]));
    }
    
    int isPalin = 1;
    
    // Compare string with popped characters
    for (int i = 0; i < len / 2; i++) {
        if (pop(&stack) != toLower(string[i])) {
            isPalin = 0;
            break;
        }
    }
    
    if (isPalin) {
        printf("String is Palindrome\n");
    } else {
        printf("String is not Palindrome\n");
    }

    return 0;
}

