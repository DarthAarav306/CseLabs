#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int priority; // The priority of the job
} Item;

typedef struct {
    Item queue[MAX];
    int front; // Points to the empty slot
    int rear;  // Points to the last valid element
} Queue;

Item indicator = {-1}; // Global indicator to represent an empty slot

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0; // Front is always empty
    q->rear = 0;  // Rear starts at the same position as front
    for (int i = 0; i < MAX; i++) {
        q->queue[i] = indicator; // Mark all positions as empty
    }
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear; // Empty if front equals rear
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front; // Full if rear's next is front
}

// Insert an element into the queue
void enqueue(Queue* q, Item ele) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert job with priority %d\n", ele.priority);
        return;
    }

    // Move rear to the next empty slot and insert the new element
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = ele;
    printf("Enqueued job with priority %d\n", ele.priority);
}

// Delete and return the job with the highest priority
Item dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return indicator; // Return indicator for an empty queue
    }

    // Find the job with the highest priority
    int maxIndex = (q->front + 1) % MAX; // Start searching from the first valid position
    for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->queue[i].priority > q->queue[maxIndex].priority) {
            maxIndex = i;
        }
    }

    // Save the highest-priority job
    Item maxJob = q->queue[maxIndex];

    // Mark the position as empty (set it to the indicator)
    q->queue[maxIndex] = indicator;

    // If the queue becomes empty after this operation, reset front and rear
    if (q->front == q->rear) {
        q->front = q->rear = 0;
    }

    printf("Dequeued job with priority %d\n", maxJob.priority);
    return maxJob;
}

// Display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->queue[i].priority != indicator.priority) { // Skip empty slots
            printf("%d ", q->queue[i].priority);
        }
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    Queue q;
    initQueue(&q);

    int choice;
    Item ele;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue a job\n");
        printf("2. Dequeue the highest-priority job\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the priority of the job: ");
                scanf("%d", &ele.priority);
                enqueue(&q, ele);
                break;

            case 2:
                ele = dequeue(&q);
                if (ele.priority != -1) {
                    printf("Processed job with priority %d\n", ele.priority);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
