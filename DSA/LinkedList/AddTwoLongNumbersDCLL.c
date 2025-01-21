#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digit;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = newNode;  // Circular nature
    newNode->prev = newNode;
    return newNode;
}

// Function to insert a node at the beginning of the doubly circular linked list
void insertBeginning(Node* header, int digit) {
    Node* newNode = createNode(digit);

    // Edge case: Check if the list is empty (i.e., only the header exists)
    if (header->next == header) {
        // List is empty, this is the first node
        header->next = newNode;
        header->prev = newNode;
        newNode->next = header;
        newNode->prev = header;
        return;
    }

    // Normal insertion at the beginning
    Node* first = header->next;
    newNode->next = first;
    newNode->prev = header;
    header->next = newNode;
    first->prev = newNode;
}

// Function to display the number from most significant to least significant
void displayNumber(Node* header) {
    Node* temp = header->next;

    if (temp == header) {
        printf("0\n");
        return;
    }

    while (temp != header) {
        printf("%d", temp->digit);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two large numbers represented as circular doubly linked lists
Node* addLargeNumbers(Node* num1, Node* num2) {
    Node* result = createNode(0);  // Header node for the result list
    Node *p = num1->prev, *q = num2->prev;  // Start from the last (least significant) digits
    int carry = 0;

    // Traverse both lists and add corresponding digits
    while (p != num1 || q != num2 || carry != 0) {
        int sum = carry;

        if (p != num1) {
            sum += p->digit;
            p = p->prev;  // Move backward to the previous node
        }

        if (q != num2) {
            sum += q->digit;
            q = q->prev;  // Move backward to the previous node
        }

        insertBeginning(result, sum % 10);  // Insert the result digit at the beginning
        carry = sum / 10;  // Carry for the next digit
    }

    return result;
}

// Function to extract digits of a number and insert into the list
void extractDigits(long long num, Node* header) {
    if (num == 0) {
        insertBeginning(header, 0);  // If the number is 0
        return;
    }

    while (num > 0) {
        int digit = num % 10;
        insertBeginning(header, digit);  // Insert least significant digit first
        num /= 10;
    }
}

int main() {
    Node* num1 = createNode(0);  // Header node for first large number
    Node* num2 = createNode(0);  // Header node for second large number

    long long input1, input2;

    // Input for the first large number
    printf("Enter the first large number: ");
    scanf("%lld", &input1);

    // Input for the second large number
    printf("Enter the second large number: ");
    scanf("%lld", &input2);

    // Extract digits and insert into the list
    extractDigits(input1, num1);
    extractDigits(input2, num2);

    printf("First Large Number: ");
    displayNumber(num1);

    printf("Second Large Number: ");
    displayNumber(num2);

    // Add the two large numbers
    Node* result = addLargeNumbers(num1, num2);

    printf("Sum of the two large numbers: ");
    displayNumber(result);

    return 0;
}
