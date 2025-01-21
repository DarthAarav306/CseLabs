#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the stack
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Define the structure for the stack
typedef struct Stack {
    Node* top;
} Stack;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->link = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->link;
    free(temp);
    return poppedValue;
}

// Display the stack
void displayStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);
    int choice, stackNo, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Select stack (1 or 2): ");
        scanf("%d", &stackNo);
        Stack* stack = (stackNo == 1) ? &stack1 : &stack2;

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                displayStack(stack);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
