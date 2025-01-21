#include <stdio.h>
#define MAX 5

// Define the Queue structure with array, front, and rear
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Function to enqueue an element
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        int i, j;
        // Find the correct position for the new element
        for (i = q->front; (i != q->rear + 1) % MAX; i = (i + 1) % MAX) {
            if (q->arr[i] > item) {
                break;
            }
        }
        // Shift elements to the right to make space
        for (j = q->rear; j != (i - 1 + MAX) % MAX; j = (j - 1 + MAX) % MAX) {
            q->arr[(j + 1) % MAX] = q->arr[j];
        /*for (j = (rear + 1) % MAX; j != index; j = (j - 1 + MAX) % MAX) {
         arr[j] = arr[(j - 1 + MAX) % MAX];
}
*/
        }
        // Insert the new item
        q->arr[i] = item;
        q->rear = (q->rear + 1) % MAX;
        printf("%d enqueued\n", item);
    }
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i != q->rear; i = (i + 1) % MAX) {
            printf("%d ", q->arr[i]);
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, item;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Display Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                display(&q);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
