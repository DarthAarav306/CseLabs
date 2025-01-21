#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int height;
    struct Node* link;
} Node;

Node* createNode(int height) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->height = height;
    newNode->link = NULL;
    return newNode;
}

void insertAtEnd(Node** start, int height) {
    Node* newNode = createNode(height);
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

Node* merge(Node* classA, Node* classB) {
    Node* mergedList = NULL;
    
    // While both lists have elements
    while (classA != NULL && classB != NULL) {
        if (classA->height <= classB->height) {
            insertAtEnd(&mergedList, classA->height);
            classA = classA->link;
        } else {
            insertAtEnd(&mergedList, classB->height);
            classB = classB->link;
        }
    }

    // If classA still has elements
    while (classA != NULL) {
        insertAtEnd(&mergedList, classA->height);
        classA = classA->link;
    }

    // If classB still has elements
    while (classB != NULL) {
        insertAtEnd(&mergedList, classB->height);
        classB = classB->link;
    }

    return mergedList;
}

void display(Node* start) {
    if (start == NULL) {
        printf("Empty list.\n");
    } else {
        Node* temp = start;
        while (temp != NULL) {
            printf("%d ", temp->height);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    Node* classA = NULL;
    Node* classB = NULL;
    Node* mergedList = NULL;

    int N1, N2;
    
    printf("Enter number of students in Class A: ");
    scanf("%d", &N1);
    printf("Enter heights of students of Class A: ");
    for (int i = 0; i < N1; i++) {
        int height;
        scanf("%d", &height);
        insertAtEnd(&classA, height);
    }

    printf("Enter number of students in Class B: ");
    scanf("%d", &N2);
    printf("Enter heights of students of Class B: ");
    for (int i = 0; i < N2; i++) {
        int height;
        scanf("%d", &height);
        insertAtEnd(&classB, height);
    }

    printf("\nClass A line: ");
    display(classA);

    printf("Class B line: ");
    display(classB);

    mergedList = merge(classA, classB);


    printf("Merged line: ");
    display(mergedList);

    return 0;
}
