#include <stdio.h>
#include <stdlib.h>

// Define the structure for the singly linked list
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

// Function to insert at the end of the list
void insertAtEnd(Node** head, int data) {
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
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Bubble Sort for Linked List
void sortBubble(Node* head) {
    if (head == NULL || head->next == NULL) return;

    Node* current;
    Node* next;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Swap the data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Selection Sort for Linked List
void sortSelection(Node* head) {
    if (head == NULL || head->next == NULL) return;

    Node* current = head;

    while (current != NULL) {
        Node* smallest = current;
        Node* next = current->next;

        while (next != NULL) {
            if (next->data < smallest->data) {
                smallest = next;
            }
            next = next->next;
        }

        // Swap the data between current and smallest
        if (smallest != current) {
            int temp = current->data;
            current->data = smallest->data;
            smallest->data = temp;
        }

        current = current->next;
    }
}

// Create a new sorted list
Node* sortWithNewList(Node* head) {
    Node* newHead = NULL;

    while (head != NULL) {
        Node* current = head;
        head = head->next;  // Move to the next node
        Node* newNode = createNode(current->data);

        // Insert into the new list in sorted order
        if (newHead == NULL || newNode->data < newHead->data) {
            newNode->next = newHead;
            newHead = newNode;
        } else {
            Node* temp = newHead;
            while (temp->next != NULL && temp->next->data < newNode->data) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        free(current);  // Free the old node after insertion
    }

    return newHead;
}

// Main Function
int main() {
    Node* head = NULL;

    // Insert elements into the list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);

    printf("Original List: ");
    displayList(head);

    // Approach 1: Bubble Sort
    printf("\nSorting using Bubble Sort...\n");
    sortBubble(head);
    displayList(head);

    // Reset the list
    head = NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);

    // Approach 2: Create a New Sorted List
    printf("\nSorting by Creating a New Sorted List...\n");
    head = sortWithNewList(head);
    displayList(head);

    // Reset the list
    head = NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);

    // Approach 3: Selection Sort
    printf("\nSorting using Selection Sort...\n");
    sortSelection(head);
    displayList(head);

    return 0;
}
