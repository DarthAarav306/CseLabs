#include <stdio.h>
#include <stdlib.h>

// Define Node using typedef
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the front of the doubly linked list
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert at the rear of the doubly linked list
void insertRear(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert at a specific position based on your logic
void insertAtPosition(Node** head, int data, int pos) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If inserting at position 1, call insertFront function
    if (pos == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Traverse to the (pos - 1)th node
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    // If temp == NULL, position is out of bounds
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    // If temp->next == NULL, we are inserting at the end
    if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    // Otherwise, insert between temp and temp->next
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete a node from the front
void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the rear
void deleteRear(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node at a specific position
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        deleteFront(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}
void insertAfterElement(Node** head, int data, int element) {
    Node* temp = *head;
    
    // Traverse the list to find the node containing 'element'
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }

    // If the element is not found in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", element);
        return;
    }

    // Create the new node to insert
    Node* newNode = createNode(data);

    // Insert the new node after the found node
    newNode->next = temp->next;  // New node points to temp's next node
    newNode->prev = temp;        // New node's prev points to temp

    // If temp is not the last node, update the next node's prev pointer
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    // Link temp's next pointer to the new node
    temp->next = newNode;

    printf("Inserted %d after %d.\n", data, element);
}


// Function to display the doubly linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the doubly linked list in reverse
void displayReverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Doubly Linked List in Reverse: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function to test all operations
int main() {
    Node* head = NULL;
    int choice, data, position;
    int element;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Display List in Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;

            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &data);
                insertRear(&head, data);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteFront(&head);
                break;

            case 5:
                deleteRear(&head);
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                displayReverse(head);
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);
            case 10:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                insertAfterElement(&head, data, element);
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
