#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node *next, *prev;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtEnd(Node* header, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (header->next == header) {
        header->next = newNode;
        newNode->next = header;
        newNode->prev = header;
        header->prev = newNode;
        return;
    }
    Node* temp = header->prev;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = header;
    header->prev = newNode;
}

void display(Node* header) {
    if (header->next == header) {
        printf("0\n");
        return;
    }
    Node* temp = header->next;
    while (temp != header) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != header) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node* addition(Node* header1, Node* header2) {
    Node* p = header1->next;
    Node* q = header2->next;
    Node* result = createNode(0, 0);  // Create header for result list

    while (p != header1 && q != header2) {
        int coeff, expo;
        if (p->expo > q->expo) {  // Higher exponent goes in result
            coeff = p->coeff;
            expo = p->expo;
            p = p->next;
        } else if (p->expo < q->expo) {  // Lower exponent goes in result
            coeff = q->coeff;
            expo = q->expo;
            q = q->next;
        } else {  // Equal exponents, add coefficients
            coeff = p->coeff + q->coeff;
            expo = p->expo;
            p = p->next;
            q = q->next;
        }
        if (coeff != 0) {  // Only add terms with non-zero coefficients
            insertAtEnd(result, coeff, expo);
        }
    }

    // Add remaining terms from header1 if any
    while (p != header1) {
        insertAtEnd(result, p->coeff, p->expo);
        p = p->next;
    }

    // Add remaining terms from header2 if any
    while (q != header2) {
        insertAtEnd(result, q->coeff, q->expo);
        q = q->next;
    }

    return result;
}

int main() {
    Node* poly1 = createNode(0, 0);  // Header node for the first polynomial
    Node* poly2 = createNode(0, 0);  // Header node for the second polynomial

    // Sample insertion of terms into poly1 and poly2 for testing
    insertAtEnd(poly1, 5, 3);
    insertAtEnd(poly1, 4, 1);
    insertAtEnd(poly1, 2, 0);

    insertAtEnd(poly2, 3, 3);
    insertAtEnd(poly2, 2, 2);
    insertAtEnd(poly2, 4, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    Node* result = addition(poly1, poly2);
    printf("Sum: ");
    display(result);

    return 0;
}
