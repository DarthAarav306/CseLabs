#include <stdio.h>
#include <stdlib.h>

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

// Function to create a circular linked list of size n
Node* createCircularList(int n) {
    Node* head = createNode(1);
    Node* temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = createNode(i);
        temp = temp->next;
    }
    temp->next = head; // Make it circular
    return head;
}

// Function to solve Josephus problem using linked list
int josephusUsingLinkedList(int n, int m) {
    Node* head = createCircularList(n);
    Node* prev = NULL;
    Node* temp = head;

    // Loop until only one node is left
    while (temp->next != temp) {
        // Traverse to the m-th node
        for (int i = 1; i < m; i++) {
            prev = temp;
            temp = temp->next;
        }
        // Remove the m-th node
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
    
    int survivor = temp->data;
    free(temp); // Free the last node
    return survivor;
}

int main() {
    int n, m;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the step count (m): ");
    scanf("%d", &m);

    int safePosition = josephusUsingLinkedList(n, m);
    printf("The safe position is: %d\n", safePosition);

    return 0;
}
