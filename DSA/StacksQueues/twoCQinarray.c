#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Size of the array, N

int queue[MAX];  // Shared array for both queues
int front1, rear1;  // Front and rear for the first queue
int front2, rear2;  // Front and rear for the second queue

// Initialize the queues
void initializeQueues() {
    front1 = rear1 = 0;  // Front and rear for queue 1 (0 to N/2 - 1)
    front2 = rear2 = MAX / 2;  // Front and rear for queue 2 (N/2 to N-1)
}

// Check if queue 1 is empty
int isEmptyQueue1() {
    return front1 == rear1;
}

// Check if queue 2 is empty
int isEmptyQueue2() {
    return front2 == rear2;
}

// Check if queue 1 is full (empty slot way)
int isFullQueue1() {
    return (rear1 + 1) % (MAX / 2) == front1;
}

// Check if queue 2 is full (empty slot way)
int isFullQueue2() {
    return ((rear2 + 1 - MAX / 2) % (MAX / 2)) + (MAX / 2) == front2;
}

// Enqueue into queue 1
void enqueue1(int value) {
    if (isFullQueue1()) {
        printf("Queue 1 is full!\n");
    } else {
        rear1 = (rear1 + 1) % (MAX / 2);  // Move rear first to ensure front remains empty
        queue[rear1] = value;             // Now insert the value at the new rear position
        printf("Inserted %d into Queue 1\n", value);
    }
}

// Enqueue into queue 2
void enqueue2(int value) {
    if (isFullQueue2()) {
        printf("Queue 2 is full!\n");
    } else {
        rear2 = (rear2 + 1 - MAX / 2) % (MAX / 2) + MAX / 2;  // Move rear first
        queue[rear2] = value;                         // Now insert the value at the new rear position
        printf("Inserted %d into Queue 2\n", value);
    }
}

// Dequeue from queue 1
void dequeue1() {
    if (isEmptyQueue1()) {
        printf("Queue 1 is empty!\n");
    } else {
        front1 = (front1 + 1) % (MAX / 2);  // Move front and remove the element
        printf("Removed %d from Queue 1\n", queue[front1]);
    }
}

// Dequeue from queue 2
void dequeue2() {
    if (isEmptyQueue2()) {
        printf("Queue 2 is empty!\n");
    } else {
        front2 = (front2 + 1) % (MAX / 2) + (MAX / 2); // Move front and remove the element
        printf("Removed %d from Queue 2\n", queue[front2]);
    }
}

// Display queue 1
void displayQueue1() {
    if (isEmptyQueue1()) {
        printf("Queue 1 is empty!\n");
    } else {
        printf("Queue 1: ");
        int i = (front1 + 1) % (MAX / 2);
        while (i != (rear1 + 1) % (MAX / 2)) {
            printf("%d ", queue[i]);
            i = (i + 1) % (MAX / 2);
        }
        printf("\n");
    }
}

// Display queue 2
void displayQueue2() {
    if (isEmptyQueue2()) {
        printf("Queue 2 is empty!\n");
    } else {
        printf("Queue 2: ");
        int i = (front2 + 1 - MAX / 2) % (MAX / 2) + MAX / 2;
        while (i != (rear2 + 1 - MAX / 2) % (MAX / 2) + MAX / 2) {
            printf("%d ", queue[i]);
            i = (i + 1 - MAX / 2) % (MAX / 2) + MAX / 2;
        }
        printf("\n");
    }
}

int main() {
    initializeQueues();

    int choice, value;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue into Queue 1\n");
        printf("2. Dequeue from Queue 1\n");
        printf("3. Display Queue 1\n");
        printf("4. Enqueue into Queue 2\n");
        printf("5. Dequeue from Queue 2\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue into Queue 1: ");
                scanf("%d", &value);
                enqueue1(value);
                break;
            case 2:
                dequeue1();
                break;
            case 3:
                displayQueue1();
                break;
            case 4:
                printf("Enter a value to enqueue into Queue 2: ");
                scanf("%d", &value);
                enqueue2(value);
                break;
            case 5:
                dequeue2();
                break;
            case 6:
                displayQueue2();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
