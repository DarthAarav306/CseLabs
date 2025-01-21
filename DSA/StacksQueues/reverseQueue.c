#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct {
    int *arr;
    int front;
    int rear;
    int maxSize;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = 0;  // Front is always empty
    q->rear = 0;
    q->maxSize = size;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % q->maxSize == q->front;
}

// Enqueue an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        q->rear = (q->rear + 1) % q->maxSize;  // Move rear first
        q->arr[q->rear] = value;               // Now insert the value at the new rear position
    }
}

// Dequeue an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        q->front = (q->front + 1) % q->maxSize;  // Move front first
        return q->arr[q->front];                 // Return the front element
    }
}

// Display the queue elements
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = (q->front + 1) % q->maxSize;
    while (i != (q->rear + 1) % q->maxSize) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->maxSize;
    }
    printf("\n");
}

// Reverse the queue using a stack
void reverseQueue(Queue *q) {
    int stack[q->maxSize];
    int top = -1;

    // Dequeue all elements and push onto the stack
    while (!isEmpty(q)) {
        stack[++top] = dequeue(q);
    }

    // Pop from stack and enqueue back to the queue
    while (top != -1) {
        enqueue(q, stack[top--]);
    }
}

int main() {
    int n, element;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    Queue q;
    initializeQueue(&q, n + 1);  // +1 to account for the empty slot in circular queue

    // Take user input to fill the queue
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        enqueue(&q, element);
    }

    printf("Original Queue:\n");
    displayQueue(&q);

    // Reverse the queue
    reverseQueue(&q);

    printf("Reversed Queue:\n");
    displayQueue(&q);

    // Free dynamically allocated memory
    free(q.arr);

    return 0;
}
