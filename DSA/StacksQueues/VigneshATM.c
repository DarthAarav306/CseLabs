#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure to represent people in the line
typedef struct {
    int people[MAX];  // Stores the positions of people in the queue
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;  // Both start at the same point in an empty queue
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;  // Empty if both front and rear point to the same slot
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;  // Full when rear catches up to front
}

// Enqueue a person into the queue (empty slot method)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;  // Move rear first to ensure front remains empty
    q->people[q->rear] = value;     // Insert the value at the new rear position
}

// Dequeue a person from the queue (empty slot method)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Return -1 if queue is empty
    }
    q->front = (q->front + 1) % MAX;  // Move front to the element being dequeued
    return q->people[q->front];       // Return the dequeued element
}

// Function to check if Vignesh and Lata can enter together
void canEnterTogether(Queue* q, int K) {
    int group[3];  // To hold 3 people at a time
    int index = 0; // Track how many are in the group

    while (!isEmpty(q)) {
        group[index++] = dequeue(q);  // Add people to the group

        // If the group is full (3 people), check if Vignesh and Lata are together
        if (index == 3) {
            if ((group[0] == K && group[1] == K + 1) || 
                (group[1] == K && group[2] == K + 1) || 
                (group[0] == K && group[2] == K + 1)) {
                printf("Yes\n");
                return;
            }
            index = 0;  // Reset the group
        }
    }
    // If we go through all the groups and don't find Vignesh and Lata together
    printf("No\n");
}

//Is the function below also valid?
int canEnter(int n,int k)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initializeQueue(q);
    for(int i=1;i<=n;i++)
    {
        enqueue(q,i);
    }
    int group[3];
    int j=0;
    while(!isEmpty(q))
    {
        group[j++]=dequeue(q);
        if(j==3)
        {
            if(group[0]==k && group[1]==k+1 || group[1]==k && group[2]==k+1)
            {
                return 1;
            }
            j=0;
        }
    }
    return 0;
}

int main() {
    int T;  // Number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, K;
        printf("Enter N (number of people) and K (Vignesh's position): ");
        scanf("%d %d", &N, &K);

        Queue q;
        initializeQueue(&q);

        // Enqueue all people into the queue
        for (int i = 1; i <= N; i++) {
            enqueue(&q, i);
        }

        // Check if Vignesh and Lata can enter together
        canEnterTogether(&q, K);
    }

    return 0;
}
