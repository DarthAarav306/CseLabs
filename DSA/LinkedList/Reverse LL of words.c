#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[100];
    struct Node* link;
} Node;

// Function to create a new node
Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** start, char* word) {
    Node* newNode = createNode(word);
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

// Function to reverse the linked list (using iterative logic)
void reverse(Node** start) {
    Node* curr = *start;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    *start = prev;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Node* start = NULL;
    int n;
    char word[100];

    // Input number of nodes and their words
    printf("Enter the number of words: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insertAtEnd(&start, word);
    }

    printf("Original List: ");
    displayList(start);

    // Reverse the linked list
    reverse(&start);

    printf("Reversed List: ");
    displayList(start);

    return 0;
}
