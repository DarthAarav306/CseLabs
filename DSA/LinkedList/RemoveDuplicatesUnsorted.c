#include<stdio.h>
#include<stdlib.h>

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

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!(*head)) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete duplicates from a singly linked list
void deleteDuplicates(Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp && temp->next) {
        Node* prev = temp;
        Node* i = temp->next;
        while (i) {
            if (temp->data == i->data) {
                prev->next = i->next;
                free(i);  // Free the duplicate node
                i = prev->next;  // Move to the next node after deletion
            } else {
                prev = i;
                i = i->next;
            }
        }
        temp = temp->next;
    }
}

// Function to display the linked list
void displayList(Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list = NULL;

    // Inserting elements, including duplicates
    insertAtEnd(&list, 1);
    insertAtEnd(&list, 2);
    insertAtEnd(&list, 3);
    insertAtEnd(&list, 2);  // Duplicate
    insertAtEnd(&list, 4);
    insertAtEnd(&list, 1);  // Duplicate

    printf("List before deleting duplicates: ");
    displayList(list);

    deleteDuplicates(list);

    printf("List after deleting duplicates: ");
    displayList(list);

    return 0;
}
