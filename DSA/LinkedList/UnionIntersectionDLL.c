#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the end of the doubly linked list
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
        newNode->prev = temp;
    }
}

// Display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Check if the element exists in the list
int exists(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1; // Element exists
        }
        temp = temp->next;
    }
    return 0; // Element does not exist
}

// Union of two doubly linked lists
Node* unionOfLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    // Add all elements of list1 to the result
    while (temp != NULL) {
        insertAtEnd(&result, temp->data);
        temp = temp->next;
    }

    // Add elements of list2 to the result that are not already in it
    temp = list2;
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Intersection of two doubly linked lists
Node* intersectionOfLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    // Add elements to result if they exist in both lists
    while (temp != NULL) {
        if (exists(list2, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* unionList = NULL;
    Node* intersectionList = NULL;
    int n1, n2, data;

    // Input elements for list1
    printf("Enter the number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements of List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertAtEnd(&list1, data);
    }

    // Input elements for list2
    printf("Enter the number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements of List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertAtEnd(&list2, data);
    }

    // Perform union
    unionList = unionOfLists(list1, list2);
    printf("Union of List 1 and List 2:\n");
    displayList(unionList);

    // Perform intersection
    intersectionList = intersectionOfLists(list1, list2);
    printf("Intersection of List 1 and List 2:\n");
    displayList(intersectionList);

    return 0;
}
