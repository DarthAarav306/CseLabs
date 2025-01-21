#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int deque[MAX];
    int front;
    int rear;
} Deque;

// Function to initialize the deque
void initialize(Deque *d) {
    d->front = 0;
    d->rear = 0;
}

// Function to check if the deque is full
int isFull(Deque *d) {
    return (d->front == (d->rear + 1) % MAX);
}

// Function to check if the deque is empty
int isEmpty(Deque *d) {
    return (d->front == d->rear);
}

// Function to insert an element at the front end of the deque
void insertFront(Deque *d, int item) {
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    d->deque[d->front] = item;               
    d->front = (d->front - 1 + MAX) % MAX;  
    printf("%d inserted at front\n", item);
}

// Function to insert an element at the rear end of the deque
void insertRear(Deque *d, int item) {
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    d->rear = (d->rear + 1) % MAX;           
    d->deque[d->rear] = item;                
    printf("%d inserted at rear\n", item);
}

// Function to delete an element from the front end of the deque
int deleteFront(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int item = d->deque[d->front];
    d->front = (d->front + 1) % MAX;         // Increment front to remove the element
    printf("%d deleted from front\n", item);
    return item;
}

// Function to delete an element from the rear end of the deque
int deleteRear(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int item = d->deque[d->rear];            
    d->rear = (d->rear - 1 + MAX) % MAX;     
    printf("%d deleted from rear\n", item);
    return item;
}

// Function to display the elements in the deque
void display(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = d->front;
    while (i != d->rear) {
        printf("%d ", d->deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque d;
    initialize(&d);
    int choice, item;

    do {
        printf("\n1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertFront(&d, item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insertRear(&d, item);
                break;
            case 3:
                deleteFront(&d);
                break;
            case 4:
                deleteRear(&d);
                break;
            case 5:
                display(&d);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
