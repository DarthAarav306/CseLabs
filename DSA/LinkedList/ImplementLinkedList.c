#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of the list
void insertAtEnd(Node** start, int data) {
    Node* newNode = createNode(data);
    if (*start == NULL) {  // If the list is empty, make the new node the start
        *start = newNode;
    } else {
        Node* temp = *start;
        while (temp->next != NULL) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Add the new node at the end
    }
}

// Insert at the beginning of the list
void insertAtBeginning(Node** start, int data) {
    Node* newNode = createNode(data);
    newNode->next = *start;  // Link the new node to the first node
    *start = newNode;        // Make the new node the start
}

// Insert at a specific position
void insertAtPosition(Node** start, int data, int pos) {
    Node* newNode = createNode(data);

    // If inserting at the beginning
    if (pos == 1) {
        newNode->next = *start;
        *start = newNode;
        return;
    }

    Node* temp = *start;
    // Traverse to the node just before the desired position
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is beyond the length of the list
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = temp->next;  // Link the new node to the next node
    temp->next = newNode;        // Link the previous node to the new node
}


// Delete from the beginning
void deleteFromBeginning(Node** start) {
    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *start;
    *start = (*start)->next;  // Move the start pointer to the next node
    free(temp);               // Free the old start node
}

// Delete from the end of the list
void deleteFromEnd(Node** start) {
    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*start)->next == NULL) {  // If there's only one node
        free(*start);
        *start = NULL;
        return;
    }

    Node* temp = *start;
    while (temp->next->next != NULL) {  // Traverse to the second last node
        temp = temp->next;
    }
    free(temp->next);  // Free the last node
    temp->next = NULL; // Set the second last node as the last node
}

// Delete from a specific position
void deleteAtPosition(Node** start, int pos) {
    if (*start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {  // If deleting the first node
        Node* temp = *start;
        *start = (*start)->next;  // Move the start pointer to the next node
        free(temp);
        return;
    }

    Node* temp = *start;
    // Traverse to the node just before the one to be deleted
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // If position is beyond the length of the list
    if (temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    Node* toDelete = temp->next;  // Node to be deleted
    temp->next = temp->next->next;  // Unlink the node
    free(toDelete);  // Free the deleted node
}

// Display the list
void display(Node* start) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int getSize(Node* start) {
    int count = 0;
    Node* temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    Node* head = NULL;  // Initialize the head of the list to NULL
    int choice, data, pos;

    do {
        printf("\n1. Insert at end\n2. Insert at beginning\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter the value and position to insert: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}
