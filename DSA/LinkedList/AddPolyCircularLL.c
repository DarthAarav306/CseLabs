#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term in a circular linked list
typedef struct Node {
    int coeff;
    int exp;
    struct Node* link;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = newNode;  // Circular nature
    return newNode;
}

// Function to insert node at the end of the circular list
void insertAtEnd(Node** start, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    
    if (*start == NULL) {
        *start = newNode;
    } else {
        Node* temp = *start;
        while (temp->link != *start) {  // Traverse until we reach the start again
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = *start;  // Make it circular
    }
}

// Function to display a circular polynomial list
void displayPoly(Node* start) {
    if (start == NULL) {
        printf("No terms in polynomial.\n");
        return;
    }

    Node* temp = start;
    do {
        printf("%d*x^%d", temp->coeff, temp->exp);
        temp = temp->link;
        if (temp != start) printf(" + ");
    } while (temp != start);
    printf("\n");
}

// Function to add/subtract two polynomials
Node* combinePolynomials(Node* p, Node* q, int subtract) {
    Node* result = NULL;  // Result polynomial

    // Traverse both circular polynomials
    Node *startP = p, *startQ = q;

    do {
        int coeff, exp;
        
        if (p->exp == q->exp) {
            coeff = subtract ? p->coeff - q->coeff : p->coeff + q->coeff;
            exp = p->exp;
            p = p->link;
            q = q->link;
        } else if (p->exp > q->exp) {
            coeff = p->coeff;
            exp = p->exp;
            p = p->link;
        } else {
            coeff = subtract ? -q->coeff : q->coeff;
            exp = q->exp;
            q = q->link;
        }

        if (coeff != 0) {
            insertAtEnd(&result, coeff, exp);
        }

    } while (p != startP || q != startQ);

    return result;
}

// Function to erase a circular polynomial list
void erasePolynomial(Node** start) {
    if (*start == NULL) return;

    Node *temp = *start, *next;
    do {
        next = temp->link;
        free(temp);
        temp = next;
    } while (temp != *start);

    *start = NULL;
}

// Main function to take input and test polynomial operations using circular linked list
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    int n1, n2, coeff, exp, choice;

    // Input for first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly1, coeff, exp);
    }

    // Input for second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly2, coeff, exp);
    }

    // Displaying polynomials
    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    // Choose addition or subtraction
    printf("Choose operation: 1 for Addition, 2 for Subtraction: ");
    scanf("%d", &choice);

    if (choice == 1) {
        result = combinePolynomials(poly1, poly2, 0);  // Addition
    } else if (choice == 2) {
        result = combinePolynomials(poly1, poly2, 1);  // Subtraction
    }

    // Displaying result
    printf("Result: ");
    displayPoly(result);

    // Erasing polynomials
    erasePolynomial(&poly1);
    erasePolynomial(&poly2);
    erasePolynomial(&result);

    return 0;
}
