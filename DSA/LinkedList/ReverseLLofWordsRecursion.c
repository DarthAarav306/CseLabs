#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the singly linked list
typedef struct Node {
    char word[100];  // Assuming words are up to 100 characters long
    struct Node* next;
} Node;

// Function to create a new node with a word
Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);  // Copy the word to the node
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
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
    }
}

// Recursive function to reverse the linked list
Node* reverseList(Node* head) {
    // Base case: if head is NULL or there's only one node, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    Node* rest = reverseList(head->next);

    // After reversing the rest, make the next node point to the current node
    head->next->next = head;

    // Make the current node point to NULL (end of the reversed list)
    head->next = NULL;

    // Return the new head of the reversed list
    return rest;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    int n;
    char word[100];

    // Input the number of words
    printf("Enter the number of words: ");
    scanf("%d", &n);

    // Input each word and insert into the list
    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insertAtEnd(&head, word);
    }

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the reversed list
    printf("Reversed List: ");
    displayList(head);

    return 0;
}
