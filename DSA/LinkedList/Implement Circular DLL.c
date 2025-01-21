#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;  // Circular nature
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the front of the circular DLL
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the node points to itself
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;  // The new node becomes the new head
    }
}

// Function to insert a node at the end of the circular DLL
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the node points to itself
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPos(Node** head, int data, int pos) {
    if (pos == 1) {
        insertAtFront(head, data);
        return;
    }

    Node* temp = *head;
    Node* newNode = createNode(data);
    int i = 1;
    while (i < pos - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }
    if (temp->next == *head && i < pos - 1) {
        printf("Position out of bounds.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete the node at the front of the circular DLL
void deleteAtFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* last = (*head)->prev;
    if (*head == (*head)->next) {
        *head = NULL;  // If there's only one node, make the list empty
        free(temp);
        return;
    }

    *head = (*head)->next;
    (*head)->prev = last;
    last->next = *head;
    free(temp);
}

// Function to delete the node at the end of the circular DLL
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* last = (*head)->prev;
    if (*head == last) {
        *head = NULL;  // If there's only one node
        free(last);
        return;
    }

    Node* secondLast = last->prev;
    secondLast->next = *head;
    (*head)->prev = secondLast;
    free(last);
}

// Function to delete a node at a specific position
void deleteAtPos(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtFront(head);
        return;
    }

    Node* temp = *head;
    int i = 1;
    while (i < pos && temp->next != *head) {
        temp = temp->next;
        i++;
    }
    if (temp->next == *head && i < pos) {
        printf("Position out of bounds.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Function to display the circular doubly linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Function to reverse the circular doubly linked list
void reverseList(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = *head;
    Node* temp = NULL;
    Node* last = (*head)->prev;

    // Traverse through the list and swap next and prev for each node
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != *head);

    *head = last;  // Update the head to point to the last node, which is the new head
}

// Function to search for an element in the list
int searchElement(Node* head, int data) {
    if (head == NULL) {
        return 0;  // List is empty
    }

    Node* temp = head;
    do {
        if (temp->data == data) {
            return 1;  // Element found
        }
        temp = temp->next;
    } while (temp != head);
    
    return 0;  // Element not found
}

// Function to count the total number of nodes in the list
int countNodes(Node* head) {
    if (head == NULL) {
        return 0;  // List is empty
    }

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    
    return count;
}

// Function to sort the list in ascending order (bubble sort)
void sortList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp;
    Node* current;
    int swapped;

    do {
        swapped = 0;
        current = head;
        while (current->next != head) {
            if (current->data > current->next->data) {
                // Swap data
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Main function to drive the program
int main() {
    Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Reverse List\n");
        printf("9. Search for Element\n");
        printf("10. Count Nodes\n");
        printf("11. Sort the List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;

            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPos(&head, data, pos);
                break;

            case 4:
                deleteAtFront(&head);
                break;

            case 5:
                deleteAtEnd(&head);
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                reverseList(&head);
                break;

            case 9:
                printf("Enter the value to search for: ");
                scanf("%d", &data);
                if (searchElement(head, data)) {
                    printf("Element found!\n");
                } else {
                    printf("Element not found!\n");
                }
                break;

            case 10:
                printf("Total nodes: %d\n", countNodes(head));
                break;

            case 11:
                sortList(head);
                printf("List sorted.\n");
                break;

            case 12:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
