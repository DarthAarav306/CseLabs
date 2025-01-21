#include <stdio.h>
#include <stdlib.h>

// Structure for the node of the doubly linked list
typedef struct Node {
    int row, col, value;  // Store the row index, column index, and value of the matrix element
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
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

// Function to display the sparse matrix represented by the doubly linked list
void displaySparseMatrix(Node* head) {
    if (head == NULL) {
        printf("The matrix is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Row  Col  Value\n");
    while (temp != NULL) {
        printf("%d    %d    %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

// Main function
int main() {
    int matrix[8][8] = {
        {0, 3, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0, 7},
        {0, 0, 5, 0, 0, 0, 8, 0},
        {2, 0, 0, 0, 0, 6, 0, 0},
        {0, 1, 0, 9, 0, 0, 0, 4},
        {0, 1, 7, 0, 0, 0, 0, 0}
    };

    Node* sparseMatrix = NULL;  // Head of the doubly linked list

    // Traverse the matrix and add non-zero elements to the doubly linked list
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matrix[i][j] != 0) {
                insertEnd(&sparseMatrix, i, j, matrix[i][j]);
            }
        }
    }

    // Display the sparse matrix using the doubly linked list
    displaySparseMatrix(sparseMatrix);

    return 0;
}
