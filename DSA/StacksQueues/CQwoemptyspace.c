#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % MAX);  // Full if rear is just ahead of front
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;  // First insertion sets front and rear to 0
        } else {
            rear = (rear + 1) % MAX;  // Increment rear circularly
        }
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Removed %d\n", queue[front]);
        if (front == rear) {
            // Queue becomes empty after this dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Increment front circularly
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;  // Move circularly
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Will fill the queue (no empty slot left)
    display();
    dequeue();
    enqueue(60);  // Will wrap around the array and insert at front
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
