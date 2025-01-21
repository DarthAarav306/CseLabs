#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for DLL
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a character at the end of the DLL
void insertEnd(Node** head, char data) {
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
    newNode->prev = temp;
}

// Reverse the linked list into a new list
Node* reverseList(Node* head) {
    Node* reverseHead = NULL;
    Node* temp = head;

    while (temp != NULL) {
        Node* newNode = createNode(temp->data);
        newNode->next = reverseHead;
        if (reverseHead != NULL) {
            reverseHead->prev = newNode;
        }
        reverseHead = newNode;
        temp = temp->next;
    }

    return reverseHead;
}

// Compare two linked lists for equality
int areListsEqual(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0; // Lists are not equal
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Both lists should end at the same time
    return (head1 == NULL && head2 == NULL);
}

// Check if a linked list is a palindrome
int isPalindrome(Node* head) {
    Node* reversed = reverseList(head);
    return areListsEqual(head, reversed);
}

int main() {
    Node* head = NULL;
    char str[100];

    printf("Enter a word: ");
    scanf("%s", str);

    // Insert all characters into the DLL
    for (int i = 0; str[i] != '\0'; i++) {
        insertEnd(&head, str[i]);
    }

    // Check if the word is a palindrome
    if (isPalindrome(head)) {
        printf("The word is a palindrome.\n");
    } else {
        printf("The word is not a palindrome.\n");
    }

    return 0;
}
