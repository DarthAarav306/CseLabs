#include <stdio.h>
#define MAX 5  // You can increase the MAX size for a larger queue

typedef struct {
    int arr[MAX];
    int rear;
    int front;
} PQ;

// Function to add an element to the priority queue
void ADDQ(PQ *q, int item) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = item;
        printf("Added %d to queue\n", item);
    }
}

// Function to compact the queue after deletion
void compactQueue(PQ *q) {
    int j = (q->front + 1) % MAX;  // Start from the first element after the empty front slot

    for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->arr[i] != -1) {  // Check for valid (non-deleted) element
            q->arr[j] = q->arr[i];  // Move element to the correct position
            j = (j + 1) % MAX;  // Move j to the next position in the circular queue
        }
    }

    q->rear = (j - 1 + MAX) % MAX;  // Update the rear pointer
}

// Function to delete the minimum element from the queue
void DELQ(PQ *q) {
    if (q->rear == q->front) {
        printf("Queue is empty\n");
        return;
    }

    int min = q->arr[(q->front + 1) % MAX];  // Start with the first valid element
    int index = (q->front + 1) % MAX;

    // Find the minimum element and its index
    for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->arr[i] < min && q->arr[i] != -1) {
            min = q->arr[i];
            index = i;
        }
    }

    printf("Deleted element: %d\n", min);
    q->arr[index] = -1;  // Mark the deleted element as -1

    // Compact the queue after deletion
    compactQueue(q);
}

// Function to display the queue elements
void display(PQ *q) {
    if (q->rear == q->front) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = (q->front + 1) % MAX; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    PQ q;
    q.rear = 0;
    q.front = 0;

    int ch, item;

    do {
        printf("\n1. ADDQ\n2. DELETE Q (Minimum Element)\n3. DISPLAY Q\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be added to the queue: ");
                scanf("%d", &item);
                ADDQ(&q, item);
                break;
            case 2:
                DELQ(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
