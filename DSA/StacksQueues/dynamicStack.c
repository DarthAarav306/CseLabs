#include <stdio.h>
#include <stdlib.h>

// Typedef for Stack Structure
typedef struct {
    int top;
    int capacity;
    int* arr;
} Stack;

// Function to initialize the stack dynamically
void initializeStack(Stack* stack) {
    stack->capacity = 1; // Initial capacity
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int)); // Allocate memory dynamically
}

// Function to double the stack size when full
// Function to double the stack size when full, without using realloc
void doubleStackCapacity(Stack* stack) {
    int newCapacity = stack->capacity * 2;

    // Allocate new memory with double capacity
    int* newArr = (int*)malloc(newCapacity * sizeof(int));
    
    // Copy elements from old array to the new array
    for (int i = 0; i <= stack->top; i++) {
        newArr[i] = stack->arr[i];
    }

    // Free the old array
    free(stack->arr);

    // Assign the new array to the stack
    stack->arr = newArr;
    stack->capacity = newCapacity;
}
void doubleStackCapacity(Stack* stack) {
    stack->capacity *= 2;
    stack->arr = (int*)realloc(stack->arr, stack->capacity * sizeof(int)); // Reallocate memory with double capacity
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        doubleStackCapacity(stack); // Increase capacity if the stack is full
    }
    stack->arr[++(stack->top)] = value;
    printf("%d pushed onto stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

// Function to display the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to display all elements of the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function to test dynamic stack operations with user input
int main() {
    Stack stack;
    initializeStack(&stack);

    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                free(stack.arr); // Free dynamically allocated memory
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
