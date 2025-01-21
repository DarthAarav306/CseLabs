#include<stdio.h>
#include<stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at a given position
void insertAtPos(Node** start, int pos, int data) {
    Node* newNode = createNode(data);
    
    // If inserting at the first position
    if (pos == 1) {
        newNode->link = *start;
        *start = newNode;
        return;
    }

    Node* temp = *start;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** start, int data) {
    Node* newNode = createNode(data);
    if (*start == NULL) {  // If the list is empty, make the new node the start
        *start = newNode;
    } else {
        Node* temp = *start;
        while (temp->link != NULL) {  // Traverse to the last node
            temp = temp->link;
        }
        temp->link = newNode;  // Add the new node at the end
    }
}

// Function to display the linked list
void displayLL(Node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseLL(Node** start) {
    Node* prev = NULL;
    Node* current = *start;
    Node* next = NULL;

    while (current != NULL) {
        next = current->link;  // Store the next node
        current->link = prev;  // Reverse the current node's link
        prev = current;        // Move prev and current one step forward
        current = next;
    }

    *start = prev;  // Update the start to point to the new first node
}

int main() {
    Node* head = NULL;  // Initialize the start of the list
    
    int choice, data, pos;

    do {
        printf("\n1. Insert at Position\n2. Insert at End\n3. Reverse Linked List\n4. Display List\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPos(&head, pos, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                reverseLL(&head);
                printf("List reversed.\n");
                break;
            case 4:
                displayLL(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
