#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5  // Max planes waiting for landing or takeoff
#define SIMULATION_TIME 20 // Total time units for simulation

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Initialize a queue (front is always empty)
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Check if the queue is full (empty-slot method)
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// Enqueue a plane into the queue
void enqueue(Queue* q, int planeID) {
    if (isFull(q)) {
        printf("Queue is full! Plane %d refused.\n", planeID);
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // Move rear first (to ensure front remains empty)
        q->queue[q->rear] = planeID;  // Insert the plane
    }
}

// Dequeue a plane from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;  // Queue is empty
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // Move front to the next position
        return q->queue[q->front];  // Return the dequeued plane
    }
}

// Runway Simulation
void simulateAirportTraffic(int simulationTime) {
    Queue landingQueue, takeoffQueue;
    initializeQueue(&landingQueue);
    initializeQueue(&takeoffQueue);

    int planeID = 0, currentTime = 0;
    int planesLanded = 0, planesTakenOff = 0, planesRefused = 0;
    int totalLandingWait = 0, totalTakeoffWait = 0, runwayIdleTime = 0;

    srand(time(0)); // Seed for random plane arrivals

    for (currentTime = 1; currentTime <= simulationTime; currentTime++) {
        // Randomly generate planes for landing and takeoff
        int landingPlaneArrives = rand() % 2; // 0 or 1
        int takeoffPlaneArrives = rand() % 2; // 0 or 1

        if (landingPlaneArrives) {
            planeID++;
            if (isFull(&landingQueue)) {
                planesRefused++;
                printf("Plane %d refused landing.\n", planeID);
            } else {
                enqueue(&landingQueue, planeID);
                printf("Plane %d added to landing queue.\n", planeID);
            }
        }

        if (takeoffPlaneArrives) {
            planeID++;
            if (isFull(&takeoffQueue)) {
                planesRefused++;
                printf("Plane %d refused takeoff.\n", planeID);
            } else {
                enqueue(&takeoffQueue, planeID);
                printf("Plane %d added to takeoff queue.\n", planeID);
            }
        }

        // If the runway is idle, decide if landing or takeoff happens
        if (!isEmpty(&landingQueue)) {
            int landingPlane = dequeue(&landingQueue);
            planesLanded++;
            totalLandingWait += (currentTime - landingPlane);  // Assume plane ID is also its arrival time
            printf("Plane %d landed at time %d.\n", landingPlane, currentTime);
        } else if (!isEmpty(&takeoffQueue)) {
            int takeoffPlane = dequeue(&takeoffQueue);
            planesTakenOff++;
            totalTakeoffWait += (currentTime - takeoffPlane);
            printf("Plane %d took off at time %d.\n", takeoffPlane, currentTime);
        } else {
            // Runway is idle
            runwayIdleTime++;
            printf("Runway idle at time %d.\n", currentTime);
        }
    }

    // Print statistics after simulation
    printf("\n--- Simulation Summary ---\n");
    printf("Planes landed: %d\n", planesLanded);
    printf("Planes taken off: %d\n", planesTakenOff);
    printf("Planes refused: %d\n", planesRefused);
    printf("Runway idle time: %d units\n", runwayIdleTime);
    printf("Average landing wait time: %.2f units\n", planesLanded ? (float)totalLandingWait / planesLanded : 0);
    printf("Average takeoff wait time: %.2f units\n", planesTakenOff ? (float)totalTakeoffWait / planesTakenOff : 0);
}

int main() {
    simulateAirportTraffic(SIMULATION_TIME);
    return 0;
}
