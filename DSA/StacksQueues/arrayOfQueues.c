#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 20
#define MAX_QUEUES 4

int memory[MEMORY_SIZE];
int front[MAX_QUEUES];
int rear[MAX_QUEUES];
int boundary[MAX_QUEUES + 1];  // One extra for final boundary

// Initialize the queues
void initializeQueues(int n) {
    // Set up boundaries, fronts, and rears for each queue
    boundary[0] = -1;  // Boundary for the first queue
    for (int i = 0; i < n; i++) {
        front[i] = rear[i] = boundary[i];  // Initialize both to boundary
        boundary[i + 1] = (MEMORY_SIZE / n) * (i + 1) - 1;  // Next boundary
    }
    boundary[n] = MEMORY_SIZE - 1;  // Set the last boundary
}

// Enqueue operation
void enqueue(int queue_no, int item, int n) {
    // Check for overflow
    if (rear[queue_no] == boundary[queue_no + 1]) {
        printf("Queue %d Overflow\n", queue_no + 1);
        return;
    }

    // First enqueue operation (queue is initially empty)
    if (rear[queue_no] == boundary[queue_no]) {
        front[queue_no] = rear[queue_no] = boundary[queue_no] + 1;  // Initialize front and rear
    } else {
        rear[queue_no]++;
    }
    memory[rear[queue_no]] = item;

    printf("Enqueued %d into Queue %d\n", item, queue_no + 1);
}

// Dequeue operation
int dequeue(int queue_no) {
    // Check for underflow
    if (front[queue_no] == boundary[queue_no]) {
        printf("Queue %d Underflow\n", queue_no + 1);
        return -1;  // Indicating an underflow
    }

    // Retrieve the front item and increment front
    int item = memory[front[queue_no]];

    if (front[queue_no] == rear[queue_no]) {
        // Reset to empty state
        front[queue_no] = rear[queue_no] = boundary[queue_no];
    } else {
        front[queue_no]++;
    }

    printf("Dequeued %d from Queue %d\n", item, queue_no + 1);
    return item;
}

// Display a queue
void displayQueue(int queue_no) {
    if (front[queue_no] == boundary[queue_no]) {
        printf("Queue %d is Empty\n", queue_no + 1)
