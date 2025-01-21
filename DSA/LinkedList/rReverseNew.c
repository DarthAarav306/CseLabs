#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNewNode(char word[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);  // Copy the word to the node's word field
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of the linked list
void insertAtEnd(Node** start, char word[]) {
    Node* newNode = createNewNode(word);
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    Node* temp = *start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(Node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = start;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Recursive function to reverse the linked list
void reverse(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    Node* rest = (*head)->next;
    
    reverse(&rest);  // Recursively reverse the rest of the list

    (*head)->next->next = *head;  // Set the next node's next pointer to current node
    (*head)->next = NULL;  // Make the current node the last node

    *head = rest;  // Update the head to point to the new head of the reversed list
}

int main() {
    Node* start = NULL;
    int n;
    char word[100];

    // Input number of words
    printf("Enter the number of words: ");
    scanf("%d", &n);

    // Input words and insert into the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insertAtEnd(&start, word);
    }

    // Display original list
    printf("Original List: \n");
    display(start);

    // Reverse the list
    reverse(&start);

    // Display reversed list
    printf("Reversed List: \n");
    display(start);

    return 0;
}
