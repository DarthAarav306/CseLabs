#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the new node becomes the head
    } else {
        Node* temp = *head;
        while (temp->link != NULL) {  // Traverse to the last node
            temp = temp->link;
        }
        temp->link = newNode;  // Attach the new node to the end of the list
    }
}

// Function to concatenate two linked lists
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;  // If the first list is empty, return the second list
    }
    
    Node* temp = head1;
    
    // Traverse to the last node of the first list
    while (temp->link != NULL) {
        temp = temp->link;
    }
    
    // Link the last node of the first list to the head of the second list
    temp->link = head2;
    
    return head1;  // Return the concatenated list's head
}

// Function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2, data;
    
    // Input for the first list
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n1);
    
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }
    
    // Input for the second list
    printf("\nEnter the number of elements for the second list: ");
    scanf("%d", &n2);
    
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }
    
    // Display both lists before concatenation
    printf("\nFirst List: ");
    display(head1);
    
    printf("Second List: ");
    display(head2);
    
    // Concatenate the lists
    head1 = concatenate(head1, head2);
    
    // Display the concatenated list
    printf("\nConcatenated List: ");
    display(head1);
    
    return 0;
}
