#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtBeginning(Node* header, int data) {
    Node* newNode = createNode(data);
    if (header->next == header) {  // List is empty
        header->next = newNode;
        newNode->prev = header;
        newNode->next = header;
        header->prev = newNode;
    } else {  // Insert at beginning
        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
    }
}

Node* createLongNumber(long num) {
    Node* longNum = createNode(0);  // Create header node
    while (num != 0) {
        int rd = num % 10;
        insertAtBeginning(longNum, rd);
        num /= 10;
    }
    return longNum;
}

Node* add(Node* num1, Node* num2) {
    Node* sumList = createNode(0);  // Header node for sum list
    Node* n1 = num1->prev;
    Node* n2 = num2->prev;
    int sum = 0, carry = 0;

    while (n1 != num1 || n2 != num2 || carry) {
        sum = carry;
        if (n1 != num1) {
            sum += n1->data;
            n1 = n1->prev;
        }
        if (n2 != num2) {
            sum += n2->data;
            n2 = n2->prev;
        }
        carry = sum / 10;
        sum = sum % 10;
        insertAtBeginning(sumList, sum);
    }
    return sumList;
}

void display(Node* header) {
    if (header->next == header) {  // Empty list
        return;
    }
    Node* temp = header->next;
    while (temp != header) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    long num1, num2;
    printf("Enter first long num: ");
    scanf("%ld", &num1);
    printf("Enter second long num: ");
    scanf("%ld", &num2);

    Node* num1list = createLongNumber(num1);
    Node* num2list = createLongNumber(num2);
    Node* sumList = add(num1list, num2list);

    printf("Sum is: ");
    display(sumList);

    return 0;
}
