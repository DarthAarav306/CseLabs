#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a vehicle
typedef struct Vehicle {
    char type[20];  // Vehicle type (Emergency, Fire, School, etc.)
    int priority;   // Priority of the vehicle (10 for Emergency, etc.)
    int arrivalTime; // The order in which the vehicle arrived
    struct Vehicle* next;  // Pointer to the next vehicle in the list
} Vehicle;

// Function to create a new vehicle node
Vehicle* createVehicle(char* type, int priority, int arrivalTime) {
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    strcpy(newVehicle->type, type);
    newVehicle->priority = priority;
    newVehicle->arrivalTime = arrivalTime;
    newVehicle->next = NULL;
    return newVehicle;
}

// Function to insert a vehicle into the priority queue
void enqueue(Vehicle** front, char* type, int priority, int arrivalTime) {
    Vehicle* newVehicle = createVehicle(type, priority, arrivalTime);
    if (*front == NULL || (*front)->priority < priority) {
        // If the queue is empty or the new vehicle has the highest priority
        newVehicle->next = *front;
        *front = newVehicle;
    } else {
        // Find the correct position to insert the new vehicle
        Vehicle* temp = *front;
        while (temp->next != NULL && (temp->next->priority > priority ||
               (temp->next->priority == priority && temp->next->arrivalTime < arrivalTime))) {
            temp = temp->next;
        }
        newVehicle->next = temp->next;
        temp->next = newVehicle;
    }
    printf("Added %s vehicle with priority %d.\n", type, priority);
}

// Function to dequeue the highest priority vehicle
void dequeue(Vehicle** front) {
    if (*front == NULL) {
        printf("Queue is empty! No vehicles to remove.\n");
        return;
    }
    Vehicle* temp = *front;
    printf("Vehicle %s is allowed to move.\n", temp->type);
    *front = (*front)->next;
    free(temp);
}

// Function to display the vehicles in the queue
void displayQueue(Vehicle* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Vehicles in the queue:\n");
    while (front != NULL) {
        printf("%s (Priority: %d)\n", front->type, front->priority);
        front = front->next;
    }
}

int main() {
    Vehicle* trafficQueue = NULL;  // Front of the priority queue
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
                displayQueue(trafficQueue);
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
