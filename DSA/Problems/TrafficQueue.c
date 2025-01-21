#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

// Structure to represent a vehicle
typedef struct {
    char type[20];  // Vehicle type (Emergency, Fire, School, etc.)
    int priority;   // Priority of the vehicle (10 for Emergency, etc.)
    int arrivalTime; // The order in which the vehicle arrived
} Vehicle;

// Queue structure for storing vehicles
typedef struct {
    Vehicle vehicles[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
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
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue a vehicle into the priority queue
void enqueue(Queue* q, char* type, int priority, int arrivalTime) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more vehicles.\n");
        return;
    }
    
    Vehicle newVehicle;
    strcpy(newVehicle.type, type);
    newVehicle.priority = priority;
    newVehicle.arrivalTime = arrivalTime;

    // Insert in sorted order based on priority
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        q->vehicles[q->rear] = newVehicle;
    } else {
        int i = q->rear;
        // Move elements with lower priority or same priority but earlier arrival time one step back
        while (i >= q->front && (q->vehicles[i].priority < priority || 
            (q->vehicles[i].priority == priority && q->vehicles[i].arrivalTime < arrivalTime))) {
            q->vehicles[(i + 1) % MAX] = q->vehicles[i];
            i = (i - 1 + MAX) % MAX;
        }
        q->vehicles[(i + 1) % MAX] = newVehicle;
        q->rear = (q->rear + 1) % MAX;
    }
    printf("Added %s vehicle with priority %d.\n", type, priority);
}

// Dequeue the vehicle with the highest priority
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No vehicles to remove.\n");
        return;
    }

    printf("Vehicle %s is allowed to move.\n", q->vehicles[q->front].type);

    // If only one vehicle is in the queue, reset front and rear
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Vehicles in the queue:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("%s (Priority: %d)\n", q->vehicles[i].type, q->vehicles[i].priority);
        i = (i + 1) % MAX;
    }
    // Print the last vehicle
    printf("%s (Priority: %d)\n", q->vehicles[q->rear].type, q->vehicles[q->rear].priority);
}

int main() {
    Queue trafficQueue;
    initializeQueue(&trafficQueue);

    int choice;
    int arrivalTime = 0;  // Keep track of the order of arrival
    char vehicleType[20];
    int priority;

    do {
        printf("\nMenu:\n");
        printf("1. Add a vehicle\n");
        printf("2. Clear traffic\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle type (Emergency/Fire/School/President/Others): ");
                scanf("%s", vehicleType);

                if (strcmp(vehicleType, "Emergency") == 0) {
                    priority = 10;
                } else if (strcmp(vehicleType, "Fire") == 0) {
                    priority = 9;
                } else if (strcmp(vehicleType, "School") == 0) {
                    priority = 8;
                } else if (strcmp(vehicleType, "President") == 0) {
                    priority = 7;
                } else {
                    priority = 6;
                }

                enqueue(&trafficQueue, vehicleType, priority, arrivalTime++);
                break;

            case 2:
                dequeue(&trafficQueue);
                break;

            case 3:
                displayQueue(&trafficQueue);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
