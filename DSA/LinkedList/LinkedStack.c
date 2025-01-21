#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int data;
    struct Node* link;  // Replaced 'next' with 'link'
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->link = *top;  // Link the new node to the previous top
    *top = newNode;        // Update the top to the new node
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* temp = *top;       // Temporary node to hold the top element
    *top = (*top)->link;     // Move top to the next element
    int poppedValue = temp->data;
    free(temp);              // Free the old top
    return poppedValue;
}

// Function to display the stack
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;  // Traverse using 'link'
    }
    printf("NULL\n");
}

int main() {
    Node* top = NULL;  // Stack is empty initially
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
