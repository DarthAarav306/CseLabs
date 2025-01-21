#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* link;  // Points to the next node in the list
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to enqueue (add) an element to the queue
void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);

    if (*rear == NULL) { // If queue is empty
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->link = newNode; // Link the new node to the last node
        *rear = newNode;         // Update the rear pointer to the new node
    }
    printf("%d enqueued.\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(Node** front, Node** rear) {
    if (*front == NULL) { // If the queue is empty
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node* temp = *front;        // Temp pointer to hold the front node
    int data = temp->data;      // Retrieve the data from the front node
    *front = (*front)->link;    // Move front to the next node

    if (*front == NULL) {       // If the queue is now empty, rear should also be NULL
        *rear = NULL;
    }

    free(temp);  // Free the dequeued node
    return data;
}

// Function to display the queue
void display(Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Node* front1 = NULL;  // First queue
    Node* rear1 = NULL;   // First queue

    Node* front2 = NULL;  // Second queue
    Node* rear2 = NULL;   // Second queue

    int choice, value, queueNumber;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Choose Queue (1 or 2): ");
            scanf("%d", &queueNumber);
        }

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                if (queueNumber == 1) {
                    enqueue(&front1, &rear1, value);
                } else if (queueNumber == 2) {
                    enqueue(&front2, &rear2, value);
                }
                break;
            case 2:
                if (queueNumber == 1) {
                    value = dequeue(&front1, &rear1);
                } else if (queueNumber == 2) {
                    value = dequeue(&front2, &rear2);
                }
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                if (queueNumber == 1) {
                    display(front1);
                } else if (queueNumber == 2) {
                    display(front2);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
