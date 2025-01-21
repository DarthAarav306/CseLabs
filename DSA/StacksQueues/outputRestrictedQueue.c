#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char queue[MAX][100];  // Store strings in the queue
    int front;
    int rear;
} Queue;

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Insert at the front of the queue
void insertFront(Queue* q, char* ele) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    // If queue is initially empty
    if (isEmpty(q)) {
        q->rear = (q->rear + 1) % MAX;
        strcpy(q->queue[q->rear], ele);
    } else {
        strcpy(q->queue[q->front], ele);  // Insert element at front position
        q->front = (q->front - 1 + MAX) % MAX;
    }
    printf("Inserted '%s' at the front\n", ele);
}

// Insert at the rear of the queue
void insertRear(Queue* q, char* ele) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;  // Increment rear
    strcpy(q->queue[q->rear], ele);  // Insert element at rear position
    printf("Inserted '%s' at the rear\n", ele);
}

// Delete from the front of the queue
void deleteFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    q->front = (q->front + 1) % MAX;  // Increment front
    printf("Deleted element from the front\n");
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = (q->front + 1) % MAX;
    while (i != (q->rear + 1) % MAX) {
        printf("%s ", q->queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Delete from the rear of the queue (Commented out, since it’s an output-restricted dequeue)
/*
void deleteRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Deleted '%s' from the rear\n", q->queue[q->rear]);
    q->rear = (q->rear - 1 + MAX) % MAX;  // Decrement rear
}
*/

int main() {
    Queue q;
    q.front = 0;
    q.rear = 0;

    int choice;
    char str[100];

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to insert at the front: ");
                scanf("%s", str);
                insertFront(&q, str);
                break;
            case 2:
                printf("Enter the string to insert at the rear: ");
                scanf("%s", str);
                insertRear(&q, str);
                break;
            case 3:
                deleteFront(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
