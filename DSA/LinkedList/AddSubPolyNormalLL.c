#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
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

// Function to insert node at the end of the list
void insertAtEnd(Node** start, int coeff, int exp) {
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

// Function to display a single polynomial
void displayPoly(Node* start) {
    if (start == NULL) {
        printf("No terms in polynomial.\n");
        return;
    }
    
    Node* temp = start;
    while (temp != NULL) {
        printf("%d*x^%d", temp->coeff, temp->exp);
        if (temp->link != NULL) printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

// Function to add/subtract two polynomials
Node* combinePolynomials(Node* p, Node* q, int subtract) {
    Node* result = NULL;  // Result polynomial
    
    // Traverse both polynomials
    while (p != NULL && q != NULL) {
        int coeff, exp;
        
        if (p->exp == q->exp) {
            // Combine coefficients based on operation (addition or subtraction)
            if (subtract) {
                coeff = p->coeff - q->coeff;  // Subtract coefficients
            } else {
                coeff = p->coeff + q->coeff;  // Add coefficients
            }
            exp = p->exp;
            p = p->link;
            q = q->link;
        } else if (p->exp > q->exp) {
            // Take term from polynomial p
            coeff = p->coeff;
            exp = p->exp;
            p = p->link;
        } else {
            // Take term from polynomial q
            if (subtract) {
                coeff = -q->coeff;  // Negate q's coefficient for subtraction
            } else {
                coeff = q->coeff;
            }
            exp = q->exp;
            q = q->link;
        }
        
        if (coeff != 0) {
            insertAtEnd(&result, coeff, exp);
        }
    }

    // If there are remaining terms in p, insert them
    while (p != NULL) {
        insertAtEnd(&result, p->coeff, p->exp);
        p = p->link;
    }

    // If there are remaining terms in q, insert them
    while (q != NULL) {
        int coeff = subtract ? -q->coeff : q->coeff;
        insertAtEnd(&result, coeff, q->exp);
        q = q->link;
    }

    return result;
}

// Function to erase a polynomial (free memory)
void erasePolynomial(Node** start) {
    Node* temp = *start;
    Node* next;
    
    while (temp != NULL) {
        next = temp->link;
        free(temp);
        temp = next;
    }
    
    *start = NULL;
}

// Main function to take input and test polynomial operations
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
