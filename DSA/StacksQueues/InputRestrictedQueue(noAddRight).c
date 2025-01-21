#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int deque[MAX];
    int front;
    int rear;
} Deque;

// Initialize the deque
void initialize(Deque* dq) {
    dq->front = 0;  // Front is always empty
    dq->rear = 0;
}

// Check if the deque is empty
int isEmpty(Deque* dq) {
    return dq->front == dq->rear;
}

// Check if the deque is full (empty-slot method)
int isFull(Deque* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

// Insert an element at the front (input restricted, so no add at rear)
void insertFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;  // Move front back first to ensure rear remains available
        dq->deque[dq->front] = value;             // Insert the value at the new front position
        printf("Inserted %d at the front\n", value);
    }
}

// Delete an element from the front
int deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    } else {
        int value = dq->deque[dq->front];
        dq->front = (dq->front + 1) % MAX;  // Move front ahead
        printf("Removed %d from the front\n", value);
        return value;
    }
}

// Delete an element from the rear
int deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    } else {
        int value = dq->deque[dq->rear];
        dq->rear = (dq->rear - 1 + MAX) % MAX;  // Move rear back
        printf("Removed %d from the rear\n", value);
        return value;
    }
}

// Display the deque elements
void displayDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque elements: ");
        int i = dq->front;
        while (i != dq->rear) {
            printf("%d ", dq->deque[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", dq->deque[dq->rear]);
    }
}

int main() {
    Deque dq;
    initialize(&dq);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display Deque\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;

            case 2:
                deleteFront(&dq);
                break;

            case 3:
                deleteRear(&dq);
                break;

            case 4:
                displayDeque(&dq);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
