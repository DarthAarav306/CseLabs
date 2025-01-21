#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Queue structure to hold front and rear pointers
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Initialize the queue
void initializeQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {  // If the queue is empty
        q->front = q->rear = newNode;
    } else {
        q->rear->link = newNode;  // Add the new node at the end
        q->rear = newNode;        // Update the rear pointer
    }
}

// Dequeue operation
void dequeue(Queue* q) {
    if (q->front == NULL) {  // If the queue is empty
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Dequeued: %d\n", q->front->data);
    q->front = q->front->link;  // Move front to the next node

    if (q->front == NULL) {  // If the queue is now empty, reset rear
        q->rear = NULL;
    }
    free(temp);
}

// Display the queue elements
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Queue q1, q2;  // Two independent queues
    initializeQueue(&q1);
    initializeQueue(&q2);

    // Operations on Queue 1
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    display(&q1);  // Queue 1: 10 -> 20 -> 30 -> NULL

    // Operations on Queue 2
    enqueue(&q2, 100);
    enqueue(&q2, 200);
    display(&q2);  // Queue 2: 100 -> 200 -> NULL

    dequeue(&q1);
    display(&q1);  // Queue 1: 20 -> 30 -> NULL

    return 0;
}
