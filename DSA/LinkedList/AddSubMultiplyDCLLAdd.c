#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, expo;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to create a new node
Node *createNode(int coeff, int expo) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Insert node at the end
void insertAtEnd(Node *header, int coeff, int expo) {
    Node *newNode = createNode(coeff, expo);
    if (header->next == header) {
        header->next = newNode;
        newNode->prev = header;
        header->prev = newNode;
        newNode->next = header;
        return;
    }
    Node *temp = header->prev; // More efficient to access last node directly
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = header;
    header->prev = newNode;
}

void insertInOrder(Node *poly, int coeff, int expo) {
    Node *newNode = createNode(coeff, expo);
    if (poly->next == poly) {
        insertAtEnd(poly, coeff, expo);
        return;
    }
    Node *temp = poly->next;

    // Separate while and if conditions
    while (temp != poly) {
        if (expo > temp->expo) {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return;
        }
        temp = temp->next;
    }

    if (temp == poly) {
        newNode->next = poly;
        newNode->prev = poly->prev;
        poly->prev->next = newNode;
        poly->prev = newNode;
    }
}
// Add or subtract two polynomials
Node *addSub(Node *poly1, Node *poly2, int sub) {
    Node *p1 = poly1->next;
    Node *p2 = poly2->next;
    Node *result = createNode(0, 0); // Dummy header

    while (p1 != poly1 && p2 != poly2) {
        int coeff, expo;
        if (p1->expo > p2->expo) {
            coeff = p1->coeff;
            expo = p1->expo;
            p1 = p1->next;
        } else if (p1->expo < p2->expo) {
            coeff = sub ? -p2->coeff : p2->coeff;
            expo = p2->expo;
            p2 = p2->next;
        } else {
            coeff = sub ? p1->coeff - p2->coeff : p1->coeff + p2->coeff;
            expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (coeff != 0) insertAtEnd(result, coeff, expo);
    }
    while (p1 != poly1) {
        insertAtEnd(result, p1->coeff, p1->expo);
        p1 = p1->next;
    }
    while (p2 != poly2) {
        insertAtEnd(result, sub ? -p2->coeff : p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

// Multiply two polynomials
Node *multiply(Node *poly1, Node *poly2) {
    Node *result = createNode(0, 0); // Dummy header
    Node *p1 = poly1->next;

    while (p1 != poly1) {
        Node *p2 = poly2->next;
        while (p2 != poly2) {
            int coeff = p1->coeff * p2->coeff;
            int expo = p1->expo + p2->expo;
            insertInOrder(result, coeff, expo);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    // Combine terms with the same exponent
    Node *r = result->next;
    while (r != result && r->next != result) {
        if (r->expo == r->next->expo) {
            r->coeff += r->next->coeff;
            Node *deleted = r->next;
            r->next = deleted->next;
            deleted->next->prev = r;
            free(deleted);
        } else {
            r = r->next;
        }
    }
    return result;
}

// Display polynomial
void display(Node *poly) {
    if (poly->next == poly) {
        printf("Polynomial is empty.\n");
        return;
    }
    Node *temp = poly->next;
    while (temp != poly) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != poly) {
            printf(temp->next->coeff >= 0 ? " + " : " ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node *poly1 = createNode(0, 0); // Header for poly1
    Node *poly2 = createNode(0, 0); // Header for poly2

    int n1, n2;
    printf("Enter number of terms for poly1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int coeff, expo;
        printf("Enter coeff and expo for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insertAtEnd(poly1, coeff, expo);
    }

    printf("Enter number of terms for poly2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int coeff, expo;
        printf("Enter coeff and expo for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insertAtEnd(poly2, coeff, expo);
    }

    printf("\nPoly1: ");
    display(poly1);
    printf("Poly2: ");
    display(poly2);

    printf("\nSum: ");
    Node *sum = addSub(poly1, poly2, 0);
    display(sum);

    printf("Difference: ");
    Node *diff = addSub(poly1, poly2, 1);
    display(diff);

    printf("Product: ");
    Node *prod = multiply(poly1, poly2);
    display(prod);

    return 0;
}
