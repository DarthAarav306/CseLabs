#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insert(Node** head, const char* word) {
    Node* newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node* head = NULL;
    int n;
    char word[50];

    // Taking input from the user
    printf("Enter number of words: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insert(&head, word);
    }

    // Print the linked list
    printList(head);

    // Free the linked list
    freeList(head);

    return 0;
}
