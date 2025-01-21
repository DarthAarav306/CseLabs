#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int queue[MAX];
    int front;
    int rear;
} Queue;

int isEmpty(Queue* q) {
    return (q->front == q->rear);
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

void pqinsert(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    // Insert new element at rear
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = x;
    printf("Inserted %d into the priority queue\n", x);
}

int pqmindelete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue empty\n");
        return -1; // Return -1 to signify the queue is empty
    }

    // Find the smallest element in the queue
    int smallindex = (q->front + 1) % MAX;  // Start from the first element in queue
    for (int i = (q->front + 2) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->queue[i] < q->queue[smallindex]) {
            smallindex = i;
        }
    }

    int smallest = q->queue[smallindex];  // Smallest element to return

    // Shift elements after the smallest to maintain the queue
    for (int j = smallindex; j != q->rear; j = (j + 1) % MAX) {
        q->queue[j] = q->queue[(j + 1) % MAX];  // Circular shift
    }
    q->rear = (q->rear - 1 + MAX) % MAX;  // Update rear

    return smallest;  // Return the smallest element
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
            printf("%d ", q->queue[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    q.front = 0;  // Front always points to the empty slot
    q.rear = 0;

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert into Priority Queue\n");
        printf("2. Delete Minimum Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                pqinsert(&q, value);
                break;
            case 2:
                value = pqmindelete(&q);
                if (value != -1) {
                    printf("Deleted minimum element: %d\n", value);
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
