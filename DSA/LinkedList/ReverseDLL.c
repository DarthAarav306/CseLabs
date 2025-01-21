#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to reverse the doubly linked list
void reverseDLL(Node** head) {
    Node* temp = NULL;
    Node* current = *head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node, which is the previous node now
    }

    // Update the head to point to the new first node (previously the last node)
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Insert elements into the doubly linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Original List: ");
    displayList(head);

    // Reverse the doubly linked list
    reverseDLL(&head);

    printf("Reversed List: ");
    displayList(head);

    return 0;
}
