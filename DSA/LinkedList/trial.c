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

Node* unionWithoutHeader(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    temp = list2;
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

Node* intersectionWithoutHeader(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = list1;

    while (temp != NULL) {
        if (exists(list2, temp->data) && !exists(result, temp->data)) {
            insertAtEnd(&result, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

Node* unionWithHeader(Node* list1, Node* list2) {
    Node* result = createNode(0);
    Node* temp = list1;

    while (temp != NULL) {
        if (!exists(result->link, temp->data)) {
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    temp = list2;
    while (temp != NULL) {
        if (!exists(result->link, temp->data)) {
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

Node* intersectionWithHeader(Node* list1, Node* list2) {
    Node* result = createNode(0);
    Node* temp = list1;

    while (temp != NULL) {
        if (exists(list2, temp->data) && !exists(result->link, temp->data)) {
            insertAtEnd(&result->link, temp->data);
        }
        temp = temp->link;
    }

    return result;
}

void displayList(Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (start->data == 0 && start->link != NULL) {
        start = start->link;
    }

    Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    int n1, n2, data;

    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        insertAtEnd(&list1, data);
    }

    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        insertAtEnd(&list2, data);
    }

    Node* unionNoHeader = unionWithoutHeader(list1, list2);
    Node* intersectionNoHeader = intersectionWithoutHeader(list1, list2);

    printf("Union (without header node): ");
    displayList(unionNoHeader);

    printf("Intersection (without header node): ");
    displayList(intersectionNoHeader);

    Node* unionHeader = unionWithHeader(list1, list2);
    Node* intersectionHeader = intersectionWithHeader(list1, list2);

    printf("Union (with header node): ");
    displayList(unionHeader);

    printf("Intersection (with header node): ");
    displayList(intersectionHeader);

    return 0;
}
