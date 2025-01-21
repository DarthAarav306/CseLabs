#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char word[100];  
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word); 
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void insertAtEnd(Node** head, char* word) {
    Node* newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void reverseDLL(Node** head) {
    Node* temp = NULL;
    Node* current = *head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node, which is the previous node now
    }

    // Update the head to point to the new first node (previously the last node)
    if (temp != NULL) {
        *head = temp->prev;
    }
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;
    int n;
    char word[100];

    printf("Enter the number of words: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);  
        insertAtEnd(&head, word);
    }

    printf("Original List: ");
    displayList(head);


    reverseDLL(&head);

    printf("Reversed List: ");
    displayList(head);

    return 0;
}
