#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* top = NULL;  // Global top pointer for the stack

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Push function (uses global top)
void push(int data) {
    Node* newNode = createNode(data);
    newNode->link = top;  // Link the new node to the previous top
    top = newNode;        // Update top to the new node
}

// Pop function (uses global top)
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("Popped: %d\n", top->data);
    top = top->link;  // Update top to the next node
    free(temp);
}

// Display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();  // 30 -> 20 -> 10 -> NULL

    pop();  // Popped: 30
    display();  // 20 -> 10 -> NULL

    return 0;
}
