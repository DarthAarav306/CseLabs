#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent the Circular Queue
typedef struct {
    char** queue; // Dynamic array to hold strings
    int front;
    int rear;
    int max; // Maximum capacity of the queue
} CircularQueue;

// Function to initialize the circular queue
void initializeCQ(CircularQueue* cq, int size) {
    cq->max = size; // Set the maximum size based on user input
    cq->queue = (char**)malloc(cq->max * sizeof(char*)); // Allocate memory for the queue
    cq->front = -1;
    cq->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue* cq) {
    return ((cq->rear + 1) % cq->max == cq->front);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* cq) {
    return (cq->front == -1);
}

// Function to insert a string into the circular queue
void insertcq(CircularQueue* cq, char* str) {
    if (isFull(cq)) {
        printf("Queue is full! Cannot insert '%s'\n", str);
    } else {
        if (isEmpty(cq)) {
            cq->front = 0; // Set front to 0 if the queue is initially empty
        }

        // Move rear to the next position circularly
        cq->rear = (cq->rear + 1) % cq->max;
        cq->queue[cq->rear] = (char*)malloc(100 * sizeof(char)); // Allocate space for the string
        strcpy(cq->queue[cq->rear], str); // Copy the string into the queue
        printf("Inserted '%s' into the queue\n", str);
    }
}

// Function to delete a string from the circular queue
void deletecq(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty! Cannot delete\n");
    } else {
        printf("Deleted '%s' from the queue\n", cq->queue[cq->front]);

        // If there's only one element, reset both front and rear to -1
        if (cq->front == cq->rear) {
            cq->front = -1;
            cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % cq->max; // Move front to the next position circularly
        }
    }
}

// Function to display the contents of the circular queue
void displaycq(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents:\n");
    int i = cq->front;
    while (i != cq->rear) {
        printf("%s ", cq->queue[i]);
        i = (i + 1) % cq->max; // Move circularly
    }
    printf("%s\n", cq->queue[cq->rear]); // Print the last element
}

int main() {
    CircularQueue cq;
    int size;

    // Input the size of the queue
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &size);

    initializeCQ(&cq, size);

    int choice;
    char str[100];

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input string to insert into the queue
                printf("Enter the string to insert: ");
                scanf("%s", str); // Input the string (without spaces)
                insertcq(&cq, str);
                break;
            case 2:
                deletecq(&cq);
                break;
            case 3:
                displaycq(&cq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(cq.queue[i]); // Free each allocated string
    }
    free(cq.queue); // Free the queue array

    return 0;
}
