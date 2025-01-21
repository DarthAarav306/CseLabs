#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself to create circular structure
    return newNode;
}

// Insert at the end of the circular list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
}

// Create a circular list with `n` nodes
Node* createCircle(int n) {
    Node* circle = NULL;
    for (int i = 1; i <= n; i++) {
        insertAtEnd(&circle, i);
    }
    return circle;
}

// Delete the node at the `k`th position starting from `start`
Node* deletePos(Node** start, int k) {
    if (!*start) return NULL;

    Node* temp = *start;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }

    Node* deleted = temp->next;
    temp->next = deleted->next;

    if (deleted == *start) { // If deleting the head, update the head
        *start = deleted->next;
    }

    free(deleted);
    return temp->next; // Return the next position in the circle
}

// Josephus problem using circular list
int josephusPosition(int n, int m) {
    Node* circle = createCircle(n);
    Node* temp = circle;

    while (temp->next != temp) { // Loop until one node remains
        temp = deletePos(&temp, m); // Delete every m-th node
    }
    int result = temp->data;
    free(temp); // Free the last remaining node
    return result;
}

int main() {
    int n, m;
    printf("Enter the number of people in the circle (n): ");
    scanf("%d", &n);
    printf("Enter the step count (m): ");
    scanf("%d", &m);

    int safePosition = josephusPosition(n, m);
    printf("The safe position is: %d\n", safePosition);

    return 0;
}
