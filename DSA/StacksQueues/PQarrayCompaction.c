#include <stdio.h>
#define MAX 3
typedef struct {
    int arr[MAX];
    int rear;
    int front;
} PQ;
void ADDQ(PQ *q, int item) {
    if (q->rear + 1 == MAX) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear++;
        q->arr[q->rear] = item;
        printf("Added %d to queue\n", item);
    }
}
void compactQueue(PQ *q) {
    int i, j = 0;
    for (i = 0; i <= q->rear; i++) {
        if (q->arr[i] != -1) {
            q->arr[j++] = q->arr[i]; // Shift the non-`-1` elements to the front
        }
    }
    q->rear = j - 1; // Update the rear pointer
}
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



void DELQ(PQ *q) {
    int min, i;
    int index = -1;

    if (q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Find the minimum element in the queue
    min = q->arr[0];
    for (i = 1; i <= q->rear; i++) {
        if (q->arr[i] != -1 && q->arr[i] < min) {
            min = q->arr[i];
            index = i;
        }
    }

    // Delete the minimum element by setting its position to -1
    if (index != -1) {
        q->arr[index] = -1;
        printf("Deleted element: %d\n", min);
    } else {
        printf("No element found to delete.\n");
    }

    // Compact the queue after deletion
    compactQueue(q);
}

void display(PQ *q) {
    printf("Queue elements: ");
    if (q->rear == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = 0; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    PQ q;
    q.rear = -1;
    q.front = -1;
    int ch, item;

    do {
        printf("Press 1. ADDQ   2. DELETE Q    3. DISPLAY Q\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be added to the Q\n");
                scanf("%d", &item);
                ADDQ(&q, item);
                break;
            case 2:
                DELQ(&q);
                break;
            case 3:
                display(&q);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
