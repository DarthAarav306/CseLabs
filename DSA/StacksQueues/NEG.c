#include <stdio.h>
#define MAX 100

// Define the Stack structure
typedef struct {
    int stack[MAX];
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
void push(Stack* p, int ele) {
    if (isFull(p)) {
        printf("Overflow!\n");
    } else {
        p->stack[++(p->top)] = ele; // Increment top and then push the element
    }
}

// Function to pop an element from the stack
int pop(Stack* p) {
    if (isEmpty(p)) {
        printf("Underflow!\n");
        return -1;  // Return -1 in case of underflow
    } else {
        return p->stack[(p->top)--];  // Pop the element and then decrement top
    }
}

// Function to display the stack elements
void display(Stack* s) {
    printf("Displaying:- \n");
    if (isEmpty(s)) {
        printf("Empty stack\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->stack[i]);
        }
    }
}

int main() {
    Stack stack1;
    Stack stack2;
    stack1.top = -1;
    stack2.top = -1;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Pushing into stack 1
    for (int i = 0; i < n; i++) {
        push(&stack1, arr[i]);
    }

    // Pushing NGEs into stack 2
    for (int i = 0; i <= stack1.top; i++) {
        int found = 0;
        for (int j = i + 1; j <= stack1.top; j++) {
            if (arr[j] > arr[i]) {
                push(&stack2, arr[j]);
                found = 1;
                break;
            }
        }
        if (!found) {
            push(&stack2, -1);
        }
    }

    // Displaying the results
    printf("Element---NGE\n");
    for (int i = 0; i <= stack1.top; i++) {
        printf("%d --> %d\n", stack1.stack[i], stack2.stack[i]);
    }

    return 0;
}
