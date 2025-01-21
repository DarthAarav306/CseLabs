#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;  
int rear = 0;

int isEmpty() {
    return front == rear;
}

int isFull() {
    return (rear + 1) % MAX == front;  
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        rear = (rear + 1) % MAX;  
        queue[rear] = value;      
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        front = (front + 1) % MAX;  
        printf("Removed %d\n", queue[front]);  
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = (front + 1) % MAX;  
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  
        }
        printf("%d\n", queue[rear]);  
    }
}

int main() {
    enqueue(10);  // Inserted into index 1
    enqueue(20);  // Inserted into index 2
    enqueue(30);  // Inserted into index 3
    enqueue(40);  // Inserted into index 4
    display();
    
    dequeue();    // Removes 10, front moves to index 1
    enqueue(50);  // Inserted into index 0 (wrapped around)
    display();
    
    dequeue();    // Removes 20
    dequeue();    // Removes 30
    display();
    
    return 0;
}
