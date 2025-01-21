#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

// Structure to represent a vehicle
typedef struct {
    int priority;
    char type[20];
} Vehicle;

Vehicle trafficQueue[MAX_SIZE];
int front = -1, rear = -1;  // Front and rear are -1 initially (queue is empty)

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to insert a vehicle into the queue
void insertVehicle(int priority, const char* type) {
    if (isFull()) {
        printf("Traffic queue is full! Cannot insert more vehicles.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;  // Initialize front on first insert
    }

    rear++;  // Move rear forward
    trafficQueue[rear].priority = priority;
    strcpy(trafficQueue[rear].type, type);

    printf("Vehicle of type %s with priority %d added to the queue.\n", type, priority);
}

// Function to move out the vehicle with the highest priority
void clearTraffic() {
    if (isEmpty()) {
        printf("No vehicles in the traffic queue.\n");
        return;
    }

    // Find the vehicle with the highest priority
    int maxPriorityIndex = front;
    for (int i = front + 1; i <= rear; i++) {
        if (trafficQueue[i].priority > trafficQueue[maxPriorityIndex].priority) {
            maxPriorityIndex = i;
        }
    }

    // Output the vehicle that is moving out
    printf("Vehicle of type %s with priority %d is moving out.\n", trafficQueue[maxPriorityIndex].type, trafficQueue[maxPriorityIndex].priority);

    // Shift all vehicles after the vehicle moved out
    for (int i = maxPriorityIndex; i < rear; i++) {
        trafficQueue[i] = trafficQueue[i + 1];
    }

    rear--;  // Adjust rear

    if (front > rear) {
        front = rear = -1;  // Queue becomes empty
    }
}

// Function to display the vehicles in the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Traffic queue is empty!\n");
        return;
    }

    printf("\nCurrent traffic queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("Vehicle type: %s, Priority: %d\n", trafficQueue[i].type, trafficQueue[i].priority);
    }
}

int main() {
    int choice, priority;
    char vehicleType[20];

    do {
        printf("\nMenu:\n");
        printf("1. Insert a vehicle into the queue\n");
        printf("2. Clear traffic (move out the highest priority vehicle)\n");
        printf("3. Display the traffic queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the vehicle type (Emergency, Fire, School, President, Others): ");
                scanf("%s", vehicleType);
                printf("Enter the vehicle priority: ");
                scanf("%d", &priority);
                insertVehicle(priority, vehicleType);
                break;

            case 2:
                clearTraffic();
                break;

            case 3:
                displayQueue();
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
