#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to represent a vehicle
typedef struct {
    char type[20];  // Vehicle type (Emergency, Fire, etc.)
    int priority;   // Priority of the vehicle (10 for Emergency, 9 for Fire, etc.)
} Vehicle;

// Priority Queue structure using a circular queue
typedef struct {
    Vehicle queue[MAX];
    int rear;
    int front;
} PriorityQueue;

void initializeQueue(PriorityQueue* pq) {
    pq->front = pq->rear = 0;  // Set front and rear both to 0
}

// Check if the queue is full (using modulo logic)
int isFull(PriorityQueue* pq) {
    return (pq->rear + 1) % MAX == pq->front;
}

// Check if the queue is empty (front == rear)
int isEmpty(PriorityQueue* pq) {
    return pq->front == pq->rear;
}

// Enqueue an element into the queue
void enqueue(PriorityQueue* pq, char* type, int priority) {
    if (isFull(pq)) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(pq->queue[pq->rear].type, type);  // Insert vehicle type
    pq->queue[pq->rear].priority = priority; // Insert priority
    pq->rear = (pq->rear + 1) % MAX;         // Circular increment of rear

    printf("Inserted vehicle %s with priority %d\n", type, priority);
}

// Dequeue an element from the queue (find and remove highest priority)
Vehicle dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        Vehicle empty = {"None", -1};
        return empty;
    }

    // Find the vehicle with the highest priority
    int highestPriorityIndex = pq->front;
    for (int i = pq->front; i != pq->rear; i = (i + 1) % MAX) {
        if (pq->queue[i].priority > pq->queue[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    Vehicle highestPriorityVehicle = pq->queue[highestPriorityIndex];

    // Shift elements after removing the highest priority vehicle
    for (int i = highestPriorityIndex; i != pq->rear; i = (i + 1) % MAX) {
        pq->queue[i] = pq->queue[(i + 1) % MAX];
    }

    pq->rear = (pq->rear - 1 + MAX) % MAX;  // Adjust rear circularly

    printf("Removed vehicle %s with priority %d\n", highestPriorityVehicle.type, highestPriorityVehicle.priority);

    return highestPriorityVehicle;
}

void displayQueue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents:\n");
    for (int i = pq->front; i != pq->rear; i = (i + 1) % MAX) {
        printf("%s (Priority: %d)\n", pq->queue[i].type, pq->queue[i].priority);
    }
}

int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    enqueue(&pq, "Emergency", 10);
    enqueue(&pq, "Fire", 9);
    enqueue(&pq, "School", 8);
    enqueue(&pq, "Others", 6);
    enqueue(&pq, "President", 7);

    displayQueue(&pq);

    dequeue(&pq);  // Remove the vehicle with the highest priority

    displayQueue(&pq);

    return 0;
}
