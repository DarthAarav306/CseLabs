#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a polynomial term
typedef struct Node {
    int coeff;
    int expo;
    struct Node* link;
} Node;

// Function to create a new node
Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->link = NULL;
    return newNode;
}

// Function to insert node at the end of the polynomial
void insertAtEnd(Node** start, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    Node* temp = *start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Function to add two polynomials
Node* addTwoPolys(Node* start1, Node* start2) {
    Node* p = start1;
    Node* q = start2;
    Node* result = NULL;

    while (p != NULL && q != NULL) {
        int coeff, expo;
        if (p->expo == q->expo) {
            expo = p->expo;
            coeff = p->coeff + q->coeff;
            p = p->link;
            q = q->link;
        } else if (p->expo > q->expo) {
            expo = p->expo;
            coeff = p->coeff;
            p = p->link;
        } else {
            expo = q->expo;
            coeff = q->coeff;
            q = q->link;
        }
        if (coeff != 0) {
            insertAtEnd(&result, coeff, expo);
        }
    }
    while (p != NULL) {
        insertAtEnd(&result, p->coeff, p->expo);
        p = p->link;
    }
    while (q != NULL) {
        insertAtEnd(&result, q->coeff, q->expo);
        q = q->link;
    }
    return result;
}

// Function to display a polynomial
void display(Node* start) {
    if (start == NULL) {
        printf("Empty polynomial.\n");
        return;
    }
    Node* temp = start;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

// Function to erase a polynomial
void erase(Node** start) {
    Node* temp = *start;
    while (temp != NULL) {
        Node* next = temp->link;
        free(temp);
        temp = next;
    }
    *start = NULL;
}

int main() {
    int coeff, expo;
    printf("Enter number of polynomials: ");
    int n;
    scanf("%d", &n);

    Node** polynomials = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        polynomials[i] = NULL;
        printf("\nEnter number of terms for polynomial %d: ", (i + 1));
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            printf("Enter coefficient and exponent: ");
            scanf("%d %d", &coeff, &expo);
            insertAtEnd(&polynomials[i], coeff, expo);
        }
    }

    printf("\nPolynomials are:\n");
    for (int i = 0; i < n; i++) {
        printf("Polynomial %d: ", i + 1);
        display(polynomials[i]);
    }

    // Sum of polynomials
    Node* sum = polynomials[0];
    for (int i = 1; i < n; i++) {
        sum = addTwoPolys(sum, polynomials[i]);
    }

    printf("\nSum of all polynomials is: ");
    display(sum);

    // Free memory
    for (int i = 0; i < n; i++) {
        erase(&polynomials[i]);
    }
    free(polynomials);
    erase(&sum);

    return 0;
}
