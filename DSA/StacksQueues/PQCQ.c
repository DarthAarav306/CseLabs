#include <stdio.h>
#define MAX 5

typedef struct {
    int element;
} Queue;

Queue Q[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
        Q[rear].element = item;
    } else {
        int i, j;
        // Find the correct position for the new element
        for (i = front; (i != rear + 1) % MAX; i = (i + 1) % MAX) {
            if (Q[i].element > item) {
                break;
            }
        }
        // Shift elements to the right to make space
        for (j = rear; j != (i - 2 + MAX) % MAX; j = (j - 1 + MAX) % MAX) {
            Q[(j + 1) % MAX] = Q[j];
        }
        // Insert the new item
        Q[i].element = item;
        rear = (rear + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", Q[i].element);
    }
    printf("%d\n", Q[rear].element);
}

int main() {
    enqueue(17);
    enqueue(14);
    enqueue(16);
    display(); // Display the queue before inserting 15

    enqueue(15); // Insert 15
    display(); // Display the queue after inserting 15

    return 0;
}
