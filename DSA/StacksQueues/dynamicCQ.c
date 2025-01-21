#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int front;
    int rear;
    int capacity;
} Queue;

int isFull(Queue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void resizeQueue(Queue *q) {
    int newCapacity = 2 * q->capacity;
    int *newQueue = (int *)malloc(newCapacity * sizeof(int));
    
    if (newQueue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i = (q->front + 1) % q->capacity;
    int j = 0;

    do {
        newQueue[j++] = q->queue[i];
        i = (i + 1) % q->capacity;
    } while (i != (q->rear + 1) % q->capacity);

    free(q->queue);
    q->queue = newQueue;
    q->front = newCapacity - 1; 
    q->rear = j - 1;            
    q->capacity = newCapacity;

    printf("Queue capacity doubled to %d\n", newCapacity);
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->queue[q->rear] = data;
    printf("Element %d inserted\n", data);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = q->queue[q->front];
    q->front = (q->front + 1) % q->capacity;
    return data;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = (q->front + 1) % q->capacity;
    while (i != (q->rear + 1) % q->capacity) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int initialCapacity;
    printf("Enter initial capacity of the queue: ");
    scanf("%d", &initialCapacity);

    Queue q;
    q.queue = (int *)malloc(initialCapacity * sizeof(int));
    if (q.queue == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    q.front = initialCapacity - 1;
    q.rear = initialCapacity - 1;
    q.capacity = initialCapacity;

    int choice, data;
    do {
        printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\n-1. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(&q);
                break;
            case -1:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != -1);

    free(q.queue);
    return 0;
}
