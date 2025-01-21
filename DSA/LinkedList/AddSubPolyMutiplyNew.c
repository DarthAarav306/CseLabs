#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int expo, coeff;
    struct Node *next, *prev;
} Node;

// Function to create a new node
Node* createNode(int expo, int coeff) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node* header, int coeff, int expo) {
    Node* newNode = createNode(expo, coeff);
    Node* temp = header->prev;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    header->prev = newNode;
}

// Function to insert a node in sorted order based on expo
void insertInOrder(Node* header, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    Node* temp = header->next;

    // If the list is empty
    if (header->next == header) {
        insertAtEnd(header, coeff, expo);
        return;
    }

    // Traverse the list and find the correct position
    while (temp != header) {
        if (expo > temp->expo) {  // Use your logic: stop when expo > temp->expo
            break;
        }
        temp = temp->next;
    }

    // Insert the node at the correct position
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Function to add or subtract two polynomials
Node* addSub(Node* poly1, Node* poly2, int sub) {
    Node* result = createNode(0, 0);  // Header node for the result
    Node* p1 = poly1->next;
    Node* p2 = poly2->next;

    while (p1 != poly1 && p2 != poly2) {
        int coeff, expo;
        if (p1->expo > p2->expo) {
            coeff = p1->coeff;
            expo = p1->expo;
            p1 = p1->next;
        } else if (p2->expo > p1->expo) {
            coeff = sub ? -p2->coeff : p2->coeff;
            expo = p2->expo;
            p2 = p2->next;
        } else {
            coeff = sub ? p1->coeff - p2->coeff : p1->coeff + p2->coeff;
            expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        }
        insertAtEnd(result, coeff, expo);
    }

    while (p1 != poly1) {
        insertAtEnd(result, p1->coeff, p1->expo);
        p1 = p1->next;
    }

    while (p2 != poly2) {
        int coeff = sub ? -p2->coeff : p2->coeff;
        insertAtEnd(result, coeff, p2->expo);
        p2 = p2->next;
    }

    return result;
}

// Function to multiply two polynomials
Node* multiply(Node* poly1, Node* poly2) {
    Node* result = createNode(0, 0);  // Header node for the result
    Node* p1 = poly1->next;

    while (p1 != poly1) {
        Node* p2 = poly2->next;
        while (p2 != poly2) {
            int expo = p1->expo + p2->expo;
            int coeff = p1->coeff * p2->coeff;
            insertInOrder(result, coeff, expo);  // Insert in sorted order
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    // Combine terms with the same exponent
    Node* temp = result->next;
    while (temp != result) {
        if (temp->next != result && temp->expo == temp->next->expo) {
            Node* deleted = temp->next;
            temp->coeff += deleted->coeff;
            temp->next = deleted->next;
            deleted->next->prev = temp;
            free(deleted);
        } else {
            temp = temp->next;
        }
    }

    return result;
}

// Function to display the polynomial
void display(Node* header) {
    if (header->next == header) {
        printf("0\n");
        return;
    }
    Node* temp = header->next;
    while (temp != header) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != header) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Main function to test the code
int main() {
    Node* poly1 = createNode(0, 0);
    Node* poly2 = createNode(0, 0);

    insertInOrder(poly1, 3, 2);
    insertInOrder(poly1, 5, 1);
    insertInOrder(poly1, 6, 0);

    insertInOrder(poly2, 4, 1);
    insertInOrder(poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    Node* sum = addSub(poly1, poly2, 0);
    printf("Sum: ");
    display(sum);

    Node* difference = addSub(poly1, poly2, 1);
    printf("Difference: ");
    display(difference);

    Node* product = multiply(poly1, poly2);
    printf("Product: ");
    display(product);

    return 0;
}
