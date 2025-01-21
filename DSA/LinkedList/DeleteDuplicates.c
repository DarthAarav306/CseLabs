#include <stdio.h>
#include <stdlib.h>

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

// Function to insert at the end of the list
void insertAtEnd(Node** start, int data) {
    Node* newNode = createNode(data);
    if (*start == NULL) {
        *start = newNode;
    } else {
        Node* temp = *start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Function to delete duplicates
void deleteDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL && current->link != NULL) {
        Node* temp = current;
        while (temp->link != NULL) {
            if (current->data == temp->link->data) {
                Node* duplicate = temp->link;
                temp->link = temp->link->link;
                free(duplicate);
            } else {
                temp = temp->link;
            }
        }
        current = current->link;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Node* start = NULL;
    int n, value;

    // Input the number of nodes and their values
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&start, value);
    }

    printf("Original List: ");
    displayList(start);

    deleteDuplicates(start);

    printf("List after removing duplicates: ");
    displayList(start);

    return 0;
}
