#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to calculate the length of the linked list
int length(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to rotate the linked list clockwise by k positions
Node* rightRotate(Node* head, int k) {
    if (k == 0 || head == NULL) 
        return head;

    int len = length(head);

    // If k is greater than the length of the list, take k % len
    k = k % len;

    if (k == 0)
        return head;

    // Convert right rotation into left rotation
    k = len - k;

    // Make the linked list circular
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    // Traverse to the kth node
    Node* curr = head;
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }

    // Update the new head and break the loop
    head = curr->next;
    curr->next = NULL;

    return head;
}

// Function to rotate the linked list anticlockwise by k positions
Node* leftRotate(Node* head, int k) {
    if (k == 0 || head == NULL)
        return head;

    int len = length(head);

    // If k is greater than the length of the list, take k % len
    k = k % len;

    if (k == 0)
        return head;

    // Make the linked list circular
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    // Traverse to the kth node
    Node* curr = head;
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }

    // Update the new head and break the loop
    head = curr->next;
    curr->next = NULL;

    return head;
}

int main() {
    Node* head = NULL;
    int n, k, choice;

    // Input number of elements and the elements in the linked list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Original Linked List: ");
    displayList(head);

    // Input number of positions to rotate
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Ask the user whether they want clockwise or anticlockwise rotation
    printf("Enter your choice: 1 for Clockwise, 2 for Anticlockwise: ");
    scanf("%d", &choice);

    if (choice == 1) {
        head = rightRotate(head, k);
        printf("Linked List after Clockwise Rotation: ");
        displayList(head);
    } else if (choice == 2) {
        head = leftRotate(head, k);
        printf("Linked List after Anticlockwise Rotation: ");
        displayList(head);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
