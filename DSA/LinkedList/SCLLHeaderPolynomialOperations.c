#include <stdio.h>
#include <stdlib.h>

// Node structure for representing a term in a polynomial
typedef struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* next;  // Pointer to the next node
} Node;

// Function to create a new node for the polynomial
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(Node* header, int coeff, int exp) {
    // If header is NULL, there's no point inserting (defensive programming)
    if (header == NULL) { 
        printf("Error: Header node is null.\n");
        return;
    }

    // Create a new node for the polynomial term
    Node* newNode = createNode(coeff, exp);

    // If it's the first node, make it point to header itself
    if (header->next == header) {           //is this necessary??
        header->next = newNode;
        newNode->next = header;
        return;
    }

    // Otherwise, traverse to the last node in the list
    Node* temp = header;
    while (temp->next != header) {
        temp = temp->next;
    }

    // Insert the new node at the end and link it back to the header
    temp->next = newNode;
    newNode->next = header;
}


// Function to display the polynomial
void displayPolynomial(Node* header) {
    if (header->next == header) {     
        printf("0\n");  // Empty polynomial
        return;
    }

    Node* temp = header->next;
    while (temp != header) {
        printf("%d x^%d ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != header) {
            printf("+ ");
        }
    }
    printf("\n");
}

Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = createNode(0, 0);  // Header node for the result
    result->next = result;
    Node* p1 = poly1->next;
    Node* p2 = poly2->next;
    
    // While both p1 and p2 haven't reached their respective header nodes
    while (p1 != poly1 && p2 != poly2) {
        int coeff = 0, exp = 0;

        if (p1->exp > p2->exp) {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            coeff = -p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
        } else {
            coeff = p1->coeff - p2->coeff;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (coeff != 0) {
            insertEnd(result, coeff, exp);
        }
    }

    // Add remaining terms from p1
    while (p1 != poly1) {
        insertEnd(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Subtract remaining terms from p2
    while (p2 != poly2) {
        insertEnd(result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}


// Function to insert a term in descending order of exponents
void insertInOrder(Node* header, int coeff, int exp) {
    if (header == NULL) return;

    Node* newNode = createNode(coeff, exp);
    Node* temp = header->next;
    Node* prev = header;

    while (temp != header) {
        if (temp->exp < exp) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    newNode->next = temp;
    prev->next = newNode;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = createNode(0, 0);  // Header node for the result
    result->next = result;

    if (poly1->next == poly1 || poly2->next == poly2) {
        printf("One or both of the polynomials are empty.\n");
        return result;
    }

    Node* p1 = poly1->next;

    while (p1 != poly1) {
        Node* p2 = poly2->next;
        while (p2 != poly2) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;

            insertInOrder(result, coeff, exp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    // Combine terms with the same exponent
    Node* ptr3 = result->next;
    Node* temp = NULL;

    while (ptr3->next != result) {
        if (ptr3->exp == ptr3->next->exp) {
            ptr3->coeff += ptr3->next->coeff;
            temp = ptr3->next;
            ptr3->next = ptr3->next->next;
            free(temp);
        } else {
            ptr3 = ptr3->next;
        }
    }

    return result;
}

// Function to input a polynomial from the user
Node* inputPolynomial() {
    Node* header = createNode(0, 0);  // Header node
    header->next = header;
    int n, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertEnd(header, coeff, exp);
    }

    return header;
}

// Main function with menu-driven approach
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice;

    while (1) {
        printf("\nPolynomial Operations Menu\n");
        printf("1. Input Polynomial 1\n");
        printf("2. Input Polynomial 2\n");
        printf("3. Subtract Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Display Polynomial 1\n");
        printf("6. Display Polynomial 2\n");
        printf("7. Display Result\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                poly1 = inputPolynomial();
                break;
            case 2:
                poly2 = inputPolynomial();
                break;
            case 3:
                result = subtractPolynomials(poly1, poly2);
                printf("Result of subtraction: ");
                displayPolynomial(result);
                break;
            case 4:
                result = multiplyPolynomials(poly1, poly2);
                printf("Result of multiplication: ");
                displayPolynomial(result);
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
            case 6:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case 7:
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
