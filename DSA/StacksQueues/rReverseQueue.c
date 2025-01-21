#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Enqueue an element into the queue
void enqueue(Queue* q, int x) {
    if (q->rear == MAX) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear++] = x;
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front++];
}

// Recursive function to reverse the queue
void reverseQueue(Queue* q) {
    if (isEmpty(q)) {
        return;  // Base case: If the queue is empty, stop recursion
    }
   
    int data = dequeue(q);  // Dequeue the front element
    reverseQueue(q);        // Recursively reverse the remaining queue
    enqueue(q, data);       // Enqueue the dequeued element at the rear
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    int n, value;

    // Ask the user for the number of elements to enqueue
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    // Enqueue the elements based on user input
    printf("Enter %d elements to enqueue:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Original Queue: \n");
    displayQueue(&q);

    // Reverse the queue
    reverseQueue(&q);

    printf("Reversed Queue: \n");
    displayQueue(&q);

    return 0;
}
