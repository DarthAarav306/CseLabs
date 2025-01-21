#include <stdio.h>
#include <stdlib.h>

int time_q = 5;  // Time quantum for the round-robin scheduling

typedef struct Node {
    int b_time;         // Burst time
    int rem_time;       // Remaining time
    struct Node* link;  // Pointer to the next node
} Node;

Node* start = NULL;
Node* rear = NULL;

// Function to create a new node for a process
Node* CreateNode(int b_time) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->b_time = b_time;
    temp->rem_time = b_time;  // Remaining time is initially equal to burst time
    temp->link = NULL;
    return temp;
}

// Insert a node at the end of the circular linked list (enqueue)
void InsertAtEnd(int b_time) {
    Node* newNode = CreateNode(b_time);

    if (start == NULL) {
        // First process in the queue
        start = rear = newNode;
        rear->link = start;  // Circular link to itself
    } else {
        rear->link = newNode;
        rear = newNode;
        rear->link = start;  // Maintain circular link
    }
}

// Delete a node from the front of the circular linked list (dequeue)
void deleteFromFront() {
    if (start == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = start;
    if (start == rear) {
        // If there's only one process
        start = rear = NULL;
    } else {
        start = start->link;  // Move start to the next node
        rear->link = start;   // Maintain circular nature
    }
    free(temp);  // Free the memory of the deleted node
}

// Function to simulate the round-robin scheduling
void RoundRobin() {
    if (start == NULL) {
        printf("No processes in the queue.\n");
        return;
    }

    Node* temp = start;

    while (1) {
        int allDone = 1;  // Flag to check if all processes are finished

        do {
            if (temp->rem_time > 0) {
                allDone = 0;  // There is still work to do

                // Process for time quantum or remaining time, whichever is smaller
                if (temp->rem_time > time_q) {
                    printf("Process with burst time %d executed for %d units.\n", temp->b_time, time_q);
                    temp->rem_time -= time_q;
                } else {
                    printf("Process with burst time %d completed execution (remaining time: %d units).\n", temp->b_time, temp->rem_time);
                    temp->rem_time = 0;  // Mark process as finished
                    deleteFromFront();   // Delete the process from the front
                }
            }

            // Move to the next process
            temp = temp->link;

        } while (temp != start);  // Continue until we have cycled through all processes

        if (allDone) {
            // If all processes are finished, exit the loop
            break;
        }
    }

    printf("All processes completed.\n");
}

// Function to display the processes in the queue
void DisplayProcesses() {
    if (start == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = start;

    printf("Processes in queue (Burst time, Remaining time):\n");
    do {
        printf("(%d, %d) ", temp->b_time, temp->rem_time);
        temp = temp->link;
    } while (temp != start);
    printf("\n");
}

int main() {
    int n, burst_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burst_time);
        InsertAtEnd(burst_time);  // Insert process into the queue
    }

    printf("Initial state of processes:\n");
    DisplayProcesses();

    printf("\nSimulating round-robin scheduling...\n");
    RoundRobin();  // Simulate round-robin scheduling

    return 0;
}
