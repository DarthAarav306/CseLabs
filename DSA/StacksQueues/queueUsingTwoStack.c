#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int data[100];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    stack->data[++(stack->top)] = value;
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; 
    }
    return stack->data[(stack->top)--];
}
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1; 
    }
    return stack->data[stack->top];
}
typedef struct Queue {
    Stack stack1;  
    Stack stack2;  
} Queue;

int isQueueEmpty(Queue* q) {
    return isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2);
}

// Check if the queue is full (both stacks full)
int isQueueFull(Queue* q) {
    return isStackFull(&q->stack1) && isStackFull(&q->stack2);
}
void initQueue(Queue* q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(Queue* q, int value) {
    push(&q->stack1, value);
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    
    // Now pop from stack2
    return pop(&q->stack2);
}

// Peek the front element of the queue
int peekQueue(Queue* q) {
    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    
    // Now peek from stack2
    return peek(&q->stack2);
}

// Display the queue elements
void display(Queue* q) {
    if (isEmpty(&q->stack1) && isEmpty(&q->stack2)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    
    // First, display elements from stack2 from top to bottom
    if (!isEmpty(&q->stack2)) {
        for (int i = q->stack2.top; i >= 0; i--) {
            printf("%d ", q->stack2.data[i]);
        }
    }

    // Then, display elements from stack1 from bottom to top
    if (!isEmpty(&q->stack1)) {
        for (int i = 0; i <= q->stack1.top; i++) {
            printf("%d ", q->stack1.data[i]);
        }
    }

    printf("\n");
}


int main() {
    Queue q;
    initQueue(&q);

    int choice, value;
    
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value == -1) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                value = peekQueue(&q);
                if (value == -1) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Front of the queue: %d\n", value);
                }
                break;

            case 4:
                display(&q);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
