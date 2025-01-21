#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* link;  // Pointer to the next node
} Node;

// Function to create the header node
Node* createHeader() {
    Node* header = (Node*)malloc(sizeof(Node));
    header->coeff = -1;  // Header node doesn't represent an actual term
    header->exp = -1;    // Set the header metadata
    header->link = header;  // Points to itself, forming the circular nature
    return header;
}

// Function to create a new term node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a term at the end (before the header node)
void insertTerm(Node* header, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    Node* temp = header;
    
    // Traverse until the last node (which points to header)
    while (temp->link != header) {
        temp = temp->link;
    }
    
    // Insert new term node at the end, before the header
    temp->link = newNode;
    newNode->link = header;  // Maintain circular link to header
}

// Function to display the polynomial
void displayPolynomial(Node* header) {
    if (header->link == header) {  // No terms, only the header
        printf("Zero polynomial.\n");
        return;
    }
    
    Node* temp = header->link;  // Start from the first term node
    while (temp != header) {  // Traverse until you reach the header again
        printf("%d*x^%d", temp->coeff, temp->exp);
        if (temp->link != header) {
            printf(" + ");
        }
        temp = temp->link;
    }
    printf("\n");
}

// Function to add two polynomials (with header nodes)
Node* addPolynomials(Node* pHeader, Node* qHeader) {
    Node* resultHeader = createHeader();  // Header for the result polynomial
    Node* p = pHeader->link;
    Node* q = qHeader->link;

    while (p != pHeader && q != qHeader) {
        if (p->exp == q->exp) {
            int sumCoeff = p->coeff + q->coeff;
            if (sumCoeff != 0) {
                insertTerm(resultHeader, sumCoeff, p->exp);
            }
            p = p->link;
            q = q->link;
        } else if (p->exp > q->exp) {
            insertTerm(resultHeader, p->coeff, p->exp);
            p = p->link;
        } else {
            insertTerm(resultHeader, q->coeff, q->exp);
            q = q->link;
        }
    }

    // Insert remaining terms from either polynomial
    while (p != pHeader) {
        insertTerm(resultHeader, p->coeff, p->exp);
        p = p->link;
    }

    while (q != qHeader) {
        insertTerm(resultHeader, q->coeff, q->exp);
        q = q->link;
    }

    return resultHeader;
}

// Function to free the memory for a polynomial
void erasePolynomial(Node* header) {
    Node* temp = header->link;
    while (temp != header) {
        Node* toDelete = temp;
        temp = temp->link;
        free(toDelete);
    }
    free(header);
}

int main() {
    // Create two polynomials with header nodes
    Node* poly1 = createHeader();
    Node* poly2 = createHeader();

    // Input terms for first polynomial
    printf("Enter terms for the first polynomial (coeff exp) (-1 to stop):\n");
    int coeff, exp;
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1) break;  // Stop input
        insertTerm(poly1, coeff, exp);
    }

    // Input terms for second polynomial
    printf("Enter terms for the second polynomial (coeff exp) (-1 to stop):\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1) break;  // Stop input
        insertTerm(poly2, coeff, exp);
    }

    // Display both polynomials
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial after addition: ");
    displayPolynomial(result);

    // Free the memory for all polynomials
    erasePolynomial(poly1);
    erasePolynomial(poly2);
    erasePolynomial(result);

    return 0;
}
