#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for queue nodes
struct Node {
    char passenger[50];  // Passenger name
    struct Node* next;
};

// Structure for queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->passenger, name);
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a passenger
void enqueue(struct Queue* q, char* name) {
    struct Node* temp = createNode(name);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a passenger
char* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct Node* temp = q->front;
    char* name = (char*)malloc(50 * sizeof(char));
    strcpy(name, temp->passenger);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return name;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to process passengers alternately from two queues
void processPassengers(struct Queue* q1, struct Queue* q2) {
    while (!isEmpty(q1) || !isEmpty(q2)) {
        if (!isEmpty(q1)) {
            printf("Processing from Queue 1: %s\n", dequeue(q1));
        }
        if (!isEmpty(q2)) {
            printf("Processing from Queue 2: %s\n", dequeue(q2));
        }
    }
}

int main() {
    struct Queue* queue1 = createQueue();
    struct Queue* queue2 = createQueue();

    int n;
    printf("Enter the number of passengers: ");
    scanf("%d", &n);

    char name[50];
    // Enqueue passengers alternately in both queues
    for (int i = 0; i < n; i++) {
        printf("Enter name of passenger %d: ", i + 1);
        scanf("%s", name);
        if (i % 2 == 0) {
            enqueue(queue1, name);
        } else {
            enqueue(queue2, name);
        }
    }

    // Process passengers from both queues alternately
    processPassengers(queue1, queue2);

    return 0;
}
