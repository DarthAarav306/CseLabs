#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, expo;
    struct Node* next;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->expo = expo;
    newNode->coeff = coeff;
    newNode->next = newNode;
    return newNode;
}

void insertAtEnd(Node* header, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (header->next == header) {  // List is empty
        header->next = newNode;
        newNode->next = header;
        return;
    }
    Node* temp = header->next;
    while (temp->next != header) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = header;
}

void insertInOrder(Node* header, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (header->next == header) {
        header->next = newNode;
        newNode->next = header;
        return;
    }
    Node* temp = header->next;
    Node* prev = header;
    while (temp != header) {
        if (expo > temp->expo) {
            prev->next = newNode;
            newNode->next = temp;
            return;
        }
        if (temp->next == header) {
            temp->next = newNode;
            newNode->next = header;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

Node* multiply(Node* polyheader1, Node* polyheader2) {
    Node* p1 = polyheader1->next;
    Node* result = createNode(0, 0);  // Header for result list
    while (p1 != polyheader1) {
        Node* p2 = polyheader2->next;
        while (p2 != polyheader2) {
            int coeff = p1->coeff * p2->coeff;
            int expo = p1->expo + p2->expo;
            insertInOrder(result, coeff, expo);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    
    // Combine terms with the same exponent
    Node* r = result->next;
    while (r != result && r->next != result) {
        if (r->expo == r->next->expo) {
            r->coeff += r->next->coeff;
            Node* deleted = r->next;
            r->next = r->next->next;
            free(deleted);  // Corrected the memory free
        } else {
            r = r->next;
        }
    }
    return result;
}

void displayPoly(Node* header) {
    Node* p = header->next;
    while (p != header) {
        printf("%dx^%d", p->coeff, p->expo);
        p = p->next;
        if (p != header) printf(" + ");
    }
    printf("\n");
}

int main() {
    Node* poly1 = createNode(0, 0);  // Header node for poly1
    Node* poly2 = createNode(0, 0);  // Header node for poly2

    // Example polynomials: 3x^3 + 2x^1 + 1
    insertAtEnd(poly1, 3, 3);
    insertAtEnd(poly1, 2, 1);
    insertAtEnd(poly1, 1, 0);

    // Example polynomials: 4x^2 + 1
    insertAtEnd(poly2, 4, 2);
    insertAtEnd(poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    Node* result = multiply(poly1, poly2);
    printf("Result of multiplication: ");
    displayPoly(result);

    return 0;
}
