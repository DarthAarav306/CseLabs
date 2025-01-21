#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

// Initialize the queue
void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->link = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", value);
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->link;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Display the queue
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    Queue queue1, queue2;
    initQueue(&queue1);
    initQueue(&queue2);
    int choice, queueNo, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Select queue (1 or 2): ");
        scanf("%d", &queueNo);
        Queue* queue = (queueNo == 1) ? &queue1 : &queue2;

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
