#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an I/O request
typedef struct IORequest {
    int requestID;
    char operation[50]; // I/O operation description
} IORequest;

// Node structure for the queue
typedef struct Node {
    IORequest data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an I/O request
void enqueue(Queue* q, int requestID, const char* operation) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.requestID = requestID;
    strcpy(newNode->data.operation, operation);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("I/O Request ID %d added to the queue.\n", requestID);
}

// Dequeue and process an I/O request
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("No I/O requests to process.\n");
        return;
    }

    Node* temp = q->front;
    printf("Processing I/O Request ID %d: %s\n", temp->data.requestID, temp->data.operation);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

// Display all pending I/O requests
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("No pending I/O requests.\n");
        return;
    }

    Node* temp = q->front;
    printf("Pending I/O Requests:\n");
    while (temp != NULL) {
        printf("Request ID: %d | Operation: %s\n", temp->data.requestID, temp->data.operation);
        temp = temp->next;
    }
}

int main() {
    Queue ioQueue;
    initQueue(&ioQueue);

    int choice;
    int requestID = 1; // Unique ID for each I/O request
    char operation[50];

    do {
        printf("\nI/O Operation Management System\n");
        printf("1. Add I/O Request\n");
        printf("2. Process I/O Request\n");
        printf("3. Display Pending I/O Requests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter I/O Operation Description: ");
                scanf(" %[^\n]", operation);
                enqueue(&ioQueue, requestID++, operation);
                break;
            case 2:
                dequeue(&ioQueue);
                break;
            case 3:
                displayQueue(&ioQueue);
                break;
            case 4:
                printf("Exiting I/O Operation Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
