#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the queue

// Define the structure of the Queue
typedef struct {
    int calls[MAX]; // Array to store call IDs or customer IDs
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Add a call to the queue (enqueue)
void enqueue(Queue* q, int callID) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more calls.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if the queue was empty
    }

    q->rear++;
    q->calls[q->rear] = callID;
    printf("Call %d added to the queue.\n", callID);
}

// Remove a call from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No calls to handle.\n");
        return -1;
    }

    int callID = q->calls[q->front];
    if (q->front == q->rear) {
        // If this was the last element, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    printf("Call %d handled and removed from the queue.\n", callID);
    return callID;
}

// Display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No calls to display.\n");
        return;
    }

    printf("Calls in the queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->calls[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    int choice, callID;

    printf("Customer Care Call Management System\n");
    while (1) {
        printf("\n1. Add Call (Enqueue)\n2. Handle Call (Dequeue)\n3. Display Calls\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Call ID: ");
                scanf("%d", &callID);
                enqueue(&q, callID);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
