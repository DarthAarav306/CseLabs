#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
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

// Enqueue an element
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }

    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // Reset the queue when it becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 40);
    display(&q);

    return 0;
}
