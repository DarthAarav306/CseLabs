#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 20
#define MAX_QUEUES 4

int memory[MEMORY_SIZE];
int front[MAX_QUEUES], rear[MAX_QUEUES];  // Front and rear for each queue
int boundary[MAX_QUEUES + 1];  // One extra boundary to handle memory limits
int segmentSize;  // Size of each segment for individual queues

// Initialize queues
void initializeQueues(int n) {
    segmentSize = MEMORY_SIZE / n;  // Split the memory evenly across queues
    for (int i = 0; i < n; i++) {
        front[i] = rear[i] = boundary[i] = segmentSize * i;
    }
    boundary[n] = MEMORY_SIZE;  // Set the final boundary
}

// Check if a queue is full (empty slot method)
int isQueueFull(int q_no) {
    return (rear[q_no] + 1) % segmentSize + boundary[q_no] == front[q_no];
}

// Check if a queue is empty
int isQueueEmpty(int q_no) {
    return front[q_no] == rear[q_no];
}

// Enqueue an element into the queue (empty slot method)
void enqueue(int q_no, int item, int n) {
    if (isQueueFull(q_no)) {
        printf("Queue %d is full!\n", q_no + 1);
    } else {
        rear[q_no] = (rear[q_no] + 1) % segmentSize + boundary[q_no];  // Move rear first
        memory[rear[q_no]] = item;  // Then insert the item at the new rear
        printf("Inserted %d into Queue %d\n", item, q_no + 1);
    }
}

// Dequeue an element from the queue (empty slot method)
void dequeue(int q_no) {
    if (isQueueEmpty(q_no)) {
        printf("Queue %d is empty!\n", q_no + 1);
    } else {
        front[q_no] = (front[q_no] + 1) % segmentSize + boundary[q_no];  // Move front first
        int item = memory[front[q_no]];  // Then get the item from the new front position
        printf("Removed %d from Queue %d\n", item, q_no + 1);
    }
}

// Display a queue
void displayQueue(int q_no) {
    if (isQueueEmpty(q_no)) {
        printf("Queue %d is empty!\n", q_no + 1);
    } else {
        printf("Queue %d elements: ", q_no + 1);
        int i = (front[q_no] + 1) % segmentSize + boundary[q_no];  // Start from the first element
        while (i != rear[q_no]) {
            printf("%d ", memory[i]);
            i = (i + 1) % segmentSize + boundary[q_no];  // Move circularly
        }
        printf("%d\n", memory[rear[q_no]]);  // Print the last element
    }
}

int main() {
    int n;
    printf("Enter the number of queues (maximum %d): ", MAX_QUEUES);
    scanf("%d", &n);
    if (n > MAX_QUEUES) {
        printf("Cannot have more than %d queues.\n", MAX_QUEUES);
        return 1;
    }

    initializeQueues(n);

    int choice, q_no, item;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display a Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (1-%d): ", n);
                scanf("%d", &q_no);
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(q_no - 1, item, n);
                break;
            case 2:
                printf("Enter queue number (1-%d): ", n);
                scanf("%d", &q_no);
                dequeue(q_no - 1);
                break;
            case 3:
                printf("Enter queue number (1-%d): ", n);
                scanf("%d", &q_no);
                displayQueue(q_no - 1);
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
