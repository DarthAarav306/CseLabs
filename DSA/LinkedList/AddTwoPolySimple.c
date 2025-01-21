#include<stdio.h>
#include<stdlib.h>

// Define the Node structure for a polynomial term
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
    newNode->link = NULL;
    return newNode;
}

// Function to insert node at the end of the polynomial
void insertAtEnd(Node** start, int coeff, int exp) {
    if (coeff == 0) return;  // Skip if the coefficient is zero

    Node* newNode = createNode(coeff, exp);
    if (*start == NULL) {
        *start = newNode;
    } else {
        Node* temp = *start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Function to add two polynomials
Node* AddTwoPolynomials(Node* start1, Node* start2) {
    Node* p = start1;
    Node* q = start2;
    Node* result = NULL;  // Result polynomial

    // Traverse both lists and add corresponding terms
    while (p != NULL && q != NULL) {
        int coeff, exp;
        if (p->exp == q->exp) {  // Same exponent
            coeff = p->coeff + q->coeff;
            exp = p->exp;
            p = p->link;
            q = q->link;
        } else if (p->exp > q->exp) {  // p has a higher exponent
            coeff = p->coeff;
            exp = p->exp;
            p = p->link;
        } else {  // q has a higher exponent
            coeff = q->coeff;
            exp = q->exp;
            q = q->link;
        }

        if (coeff != 0) {  // Only insert non-zero terms
            insertAtEnd(&result, coeff, exp);
        }
    }

    // Add remaining terms from p
    while (p != NULL) {
        if (p->coeff != 0) {  // Skip zero terms
            insertAtEnd(&result, p->coeff, p->exp);
        }
        p = p->link;
    }

    // Add remaining terms from q
    while (q != NULL) {
        if (q->coeff != 0) {  // Skip zero terms
            insertAtEnd(&result, q->coeff, q->exp);
        }
        q = q->link;
    }

    return result;
}

// Function to display a polynomial
void displayPoly(Node* start) {
    if (start == NULL) {
        printf("Empty polynomial.\n");
        return;
    }

    Node* temp = start;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

// Function to erase a polynomial
void erasePolynomial(Node** start) {
    Node* temp = *start;
    while (temp != NULL) {
        Node* next = temp->link;
        free(temp);
        temp = next;
    }
    *start = NULL;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    int n1, n2, coeff, exp;

    // Input first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly1, coeff, exp);
    }

    // Input second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly2, coeff, exp);
    }

    // Display the polynomials
    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    // Add the two polynomials
    result = AddTwoPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    displayPoly(result);

    // Erase the polynomials to free memory
    erasePolynomial(&poly1);
    erasePolynomial(&poly2);
    erasePolynomial(&result);

    return 0;
}
