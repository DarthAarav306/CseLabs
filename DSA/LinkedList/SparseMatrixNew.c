#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value, row, column;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value, int row, int column) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->column = column;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int value, int row, int column) {
    Node* newNode = createNode(value, row, column);
    if (!*head) {
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

Node* sparseMatrix(int rows, int cols, int matrix[rows][cols]) {
    Node* sparseMatrixHead = NULL;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertAtEnd(&sparseMatrixHead, matrix[i][j], i, j);
            }
        }
    }
    return sparseMatrixHead;
}

void display(Node* head) {
    if (!head) {
        printf("The matrix is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Sparse Matrix Representation (Value, Row, Column):\n");
    while (temp != NULL) {
        printf("Value: %d, Row: %d, Column: %d\n", temp->value, temp->row, temp->column);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Declare the variable-length array
    int matrix[rows][cols];

    // Input matrix values
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    Node* sparseHead = sparseMatrix(rows, cols, matrix);
    display(sparseHead);

    return 0;
}
