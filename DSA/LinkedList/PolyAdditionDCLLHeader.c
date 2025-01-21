#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the doubly circular linked list
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the doubly circular linked list
void insertEnd(Node* header, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    Node* last = header->prev;

    // Update links to insert the node at the end
    newNode->next = header;
    newNode->prev = last;
    last->next = newNode;
    header->prev = newNode;
}

// Function to display a polynomial
void displayPolynomial(Node* header) {
    Node* temp = header->next;

    if (temp == header) {
        printf("0\n");
        return;
    }

    while (temp != header) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;

        if (temp != header)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = createNode(0, 0);  // Create header for the result polynomial
    Node *p = poly1->next, *q = poly2->next;

    while (p != poly1 && q != poly2) {
        if (p->exp == q->exp) {
            int sumCoeff = p->coeff + q->coeff;
            if (sumCoeff != 0)  // Only insert non-zero coefficients
                insertEnd(result, sumCoeff, p->exp);
            p = p->next;
            q = q->next;
        } else if (p->exp > q->exp) {
            insertEnd(result, p->coeff, p->exp);
            p = p->next;
        } else {
            insertEnd(result, q->coeff, q->exp);
            q = q->next;
        }
    }

    // Add the remaining terms of poly1
    while (p != poly1) {
        insertEnd(result, p->coeff, p->exp);
        p = p->next;
    }

    // Add the remaining terms of poly2
    while (q != poly2) {
        insertEnd(result, q->coeff, q->exp);
        q = q->next;
    }

    return result;
}

int main() {
    Node* poly1 = createNode(0, 0);  // Header node for polynomial 1
    Node* poly2 = createNode(0, 0);  // Header node for polynomial 2

    int n1, n2, coeff, exp;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertEnd(poly1, coeff, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertEnd(poly2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    Node* result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    displayPolynomial(result);

    return 0;
}
