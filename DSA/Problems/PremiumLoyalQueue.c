#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node {
    char type; // 'P' for premium, 'L' for loyal
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the queue
void insertAtFront(Node** front, Node** rear, char type) {
    Node* newNode = createNode(type);
    if (*front == NULL) {
        *front = *rear = newNode;
    } else {
        newNode->next = *front;
        *front = newNode;
    }
}

// Function to insert a node at the end of the queue
void insertAtEnd(Node** front, Node** rear, char type) {
    Node* newNode = createNode(type);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to delete from the front of the queue
char deleteFromFront(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return '\0';
    }
    Node* temp = *front;
    char type = temp->type;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return type;
}

// Function to display the queue
void displayQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = front;
        while (temp != NULL) {
            printf("%c -> ", temp->type);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node *originalFront = NULL, *originalRear = NULL;
    Node *premiumFront = NULL, *premiumRear = NULL;
    int K = 3;  // Threshold for transferring premium customers
    int premiumCount = 0;

    int choice;
    char customerType;

    while (1) {
        printf("\n1. Add customer (P for Premium, L for Loyal)\n");
        printf("2. Process (Delete from front)\n");
        printf("3. Display queues\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer type (P/L): ");
                scanf(" %c", &customerType);

                if (customerType == 'P') {
                    insertAtFront(&originalFront, &originalRear, customerType);
                    premiumCount++;
                    if (premiumCount == K) {
                        // Transfer premium customers to the premium queue
                        while (premiumCount > 0) {
                            char type = deleteFromFront(&originalFront, &originalRear);
                            insertAtEnd(&premiumFront, &premiumRear, type);
                            premiumCount--;
                        }
                    }
                } else if (customerType == 'L') {
                    insertAtEnd(&originalFront, &originalRear, customerType);
                } else {
                    printf("Invalid customer type!\n");
                }
                break;

            case 2:
                if (premiumFront != NULL) {
                    printf("Processing Premium: %c\n", deleteFromFront(&premiumFront, &premiumRear));
                } else if (originalFront != NULL) {
                    printf("Processing Original: %c\n", deleteFromFront(&originalFront, &originalRear));
                } else {
                    printf("Both queues are empty!\n");
                }
                break;

            case 3:
                printf("Original Queue: ");
                displayQueue(originalFront);
                printf("Premium Queue: ");
                displayQueue(premiumFront);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
