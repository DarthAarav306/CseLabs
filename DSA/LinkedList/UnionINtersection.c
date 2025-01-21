#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* link;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertAtEnd(Node** start, int data) {
    Node* newNode = createNode(data);
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

// Function to check if an element exists in a list
int exists(Node* start, int data) {
    Node* temp = start;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}

// Function to perform union of two sets without a header node
Node* unionWithoutHeader(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    // Add all elements of list1 to the result
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    // Add elements of list2 that are not already in result
    temp = list2;
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

// Function to perform intersection of two sets without a header node
Node* intersectionWithoutHeader(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    // Add elements common to both lists to the result
    while (temp != NULL) {
        if (exists(list2, temp->data) && !exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

// Function to perform union of two sets with a header node
Node* unionWithHeader(Node* list1, Node* list2) {
    Node* result = createNode(0);  // Create header node
    Node* temp = list1;

    // Add all elements of list1 to the result
    while (temp != NULL) {
        if (!exists(result->link, temp->data)) {  // Skip header node
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    // Add elements of list2 that are not already in result
    temp = list2;
    while (temp != NULL) {
        if (!exists(result->link, temp->data)) {  // Skip header node
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

// Function to perform intersection of two sets with a header node
Node* intersectionWithHeader(Node* list1, Node* list2) {
    Node* result = createNode(0);  // Create header node
    Node* temp = list1;

    // Add elements common to both lists to the result
    while (temp != NULL) {
        if (exists(list2, temp->data) && !exists(result->link, temp->data)) {  // Skip header node
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

// Function to display a linked list (skips the header node if present)
void displayList(Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (start->data == 0 && start->link != NULL) {
        start = start->link;  // Skip header node
    }

    Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node *list1 = NULL, *list2 = NULL;
    int n1, n2, data;

    // Input first list
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        insertAtEnd(&list1, data);
    }

    // Input second list
    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        insertAtEnd(&list2, data);
    }

    // Perform union and intersection without header node
    Node* unionNoHeader = unionWithoutHeader(list1, list2);
    Node* intersectionNoHeader = intersectionWithoutHeader(list1, list2);

    printf("Union (without header node): ");
    displayList(unionNoHeader);

    printf("Intersection (without header node): ");
    displayList(intersectionNoHeader);

    // Perform union and intersection with header node
    Node* unionHeader = unionWithHeader(list1, list2);
    Node* intersectionHeader = intersectionWithHeader(list1, list2);

    printf("Union (with header node): ");
    displayList(unionHeader);

    printf("Intersection (with header node): ");
    displayList(intersectionHeader);

    return 0;
}
