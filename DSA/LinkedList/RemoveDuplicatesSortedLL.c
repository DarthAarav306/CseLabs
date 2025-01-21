#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

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

void removeDuplicates(Node* head) {
    Node* current = head;
    
    while (current != NULL && current->link != NULL) {
        if (current->data == current->link->data) {
            Node* temp = current->link;
            current->link = current->link->link;
            free(temp); 
        } else {
            current = current->link; 
        }
    }
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Original List: ");
    displayList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    displayList(head);

    return 0;
}
