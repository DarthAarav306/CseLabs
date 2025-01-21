#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    char data[100];  // String data
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(Node** head, char* str) {
    Node* newNode = createNode(str);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    printf("List: ");
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        printf("%s -> ", temp->data);
    }
    printf("NULL\n");
}

// Function to sort the linked list using Selection Sort
void selectionSort(Node* head) {
    if (head == NULL) return;

    for (Node* i = head; i != NULL; i = i->next) {
        Node* min = i;

        // Find the minimum element in the unsorted part
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->data, min->data) < 0) {
                min = j;
            }
        }

        // Swap the data of the current node and the min node
        if (min != i) {
            char temp[100];
            strcpy(temp, i->data);
            strcpy(i->data, min->data);
            strcpy(min->data, temp);
        }
    }
}

// Main function to drive the program
int main() {
    Node* head = NULL;
    int choice;
    char str[100];

    do {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Sort\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to be inserted to the node: ");
                scanf("%s", str);
                insertAtFront(&head, str);  // Insert at the front of the list
                break;

            case 2:
                selectionSort(head);  // Sort the list using Selection Sort
                printf("List sorted.\n");
                break;

            case 3:
                displayList(head);  // Display the linked list
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
