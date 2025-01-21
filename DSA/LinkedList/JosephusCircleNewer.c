#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;  // Points to itself initially
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node at the `k`th position in the circular linked list
void delete(Node** head, int k) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;

    // If only one node is left in the list
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
        return;
    }

    // If deleting the head node
    if (k == 1) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Traverse to the (k-1)th node
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }

    // Delete the kth node
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Function to find the safe position in the Josephus problem
int safePosition(int n, int k) {
    Node* circle = NULL;

    // Create the circular linked list with `n` nodes
    for (int i = 1; i <= n; i++) {
        insertAtEnd(&circle, i);
    }

    // Eliminate nodes one by one until only one node is left
    while (circle->next != circle) {
        delete(&circle, k);
    }

    int safePos = circle->data;
    free(circle);  // Free the last remaining node
    return safePos;
}

// Main function
int main() {
    int n, k;

    printf("Enter the number of people in the circle (n): ");
    scanf("%d", &n);

    printf("Enter the step rate (k): ");
    scanf("%d", &k);

    int safePos = safePosition(n, k);
    printf("The safe position is: %d\n", safePos);

    return 0;
}
