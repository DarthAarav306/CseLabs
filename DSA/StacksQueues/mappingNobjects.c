#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100  // Total memory size
#define MAX_OBJECTS 10    // Maximum number of data objects (stacks and queues)

int memory[MEMORY_SIZE];  // Shared array for both stacks and queues
int front[MAX_OBJECTS];    // Front pointer for queues
int rear[MAX_OBJECTS];     // Rear pointer for queues
int top[MAX_OBJECTS];      // Top pointer for stacks
int boundary[MAX_OBJECTS + 1];  // Array boundaries for stacks and queues
int is_stack[MAX_OBJECTS];  // 1 if the object is a stack, 0 if it's a queue

// Function to initialize the memory for stacks and queues
void initializeObjects(int n1, int n2) {
    int n = n1 + n2;  // Total number of objects

    // Set up boundaries, tops, and fronts/rears for each stack/queue
    boundary[0] = -1;
    for (int i = 0; i < n; i++) {
        boundary[i + 1] = (MEMORY_SIZE / n) * (i + 1) - 1;  // Segment size
        top[i] = front[i] = rear[i] = boundary[i];          // Initialize pointers
    }

    // Mark first n1 objects as stacks and the rest as queues
    for (int i = 0; i < n1; i++) {
        is_stack[i] = 1;  // These are stacks
    }
    for (int i = n1; i < n; i++) {
        is_stack[i] = 0;  // These are queues
    }
}

// Check if there is space for the object
int spaceFull(int obj_no) {
    int segment_size = boundary[obj_no + 1] - boundary[obj_no];
    if (is_stack[obj_no]) {
        // For stacks, check if top has reached the boundary
        return top[obj_no] + 1 == boundary[obj_no + 1];
    } else {
        // For queues (circular), check if front == rear + 1 (full)
        return (rear[obj_no] + 1) % segment_size + boundary[obj_no] == front[obj_no];
    }
}

// Check if the object is empty
int isEmpty(int obj_no) {
    if (is_stack[obj_no]) {
        return top[obj_no] == boundary[obj_no];  // Stack empty
    } else {
        return front[obj_no] == rear[obj_no];  // Queue empty
    }
}

// Push an element to the stack
void push(int stack_no, int value) {
    if (spaceFull(stack_no)) {
        printf("Stack %d is full\n", stack_no + 1);
    } else {
        memory[++top[stack_no]] = value;
        printf("Pushed %d into Stack %d\n", value, stack_no + 1);
    }
}

// Pop an element from the stack
int pop(int stack_no) {
    if (isEmpty(stack_no)) {
        printf("Stack %d is empty\n", stack_no + 1);
        return -1;
    } else {
        int item = memory[top[stack_no]--];
        printf("Popped %d from Stack %d\n", item, stack_no + 1);
        return item;
    }
}

// Enqueue an element to the queue
void enqueue(int queue_no, int value) {
    if (spaceFull(queue_no)) {
        printf("Queue %d is full\n", queue_no + 1);
    } else {
        rear[queue_no] = (rear[queue_no] + 1) % (boundary[queue_no + 1] - boundary[queue_no]) + boundary[queue_no];
        memory[rear[queue_no]] = value;
        printf("Enqueued %d into Queue %d\n", value, queue_no + 1);
    }
}

// Dequeue an element from the queue
int dequeue(int queue_no) {
    if (isEmpty(queue_no)) {
        printf("Queue %d is empty\n", queue_no + 1);
        return -1;
    } else {
        front[queue_no] = (front[queue_no] + 1) % (boundary[queue_no + 1] - boundary[queue_no]) + boundary[queue_no];
        int item = memory[front[queue_no]];
        printf("Dequeued %d from Queue %d\n", item, queue_no + 1);
        return item;
    }
}

// Display the elements of a stack or queue
void display(int obj_no) {
    if (isEmpty(obj_no)) {
        if (is_stack[obj_no]) {
            printf("Stack %d is empty\n", obj_no + 1);
        } else {
            printf("Queue %d is empty\n", obj_no + 1);
        }
    } else {
        printf("Elements of ");
        if (is_stack[obj_no]) {
            printf("Stack %d: ", obj_no + 1);
            for (int i = boundary[obj_no] + 1; i <= top[obj_no]; i++) {
                printf("%d ", memory[i]);
            }
        } else {
            printf("Queue %d: ", obj_no + 1);
            int i = front[obj_no];
            do {
                i = (i + 1) % (boundary[obj_no + 1] - boundary[obj_no]) + boundary[obj_no];
                printf("%d ", memory[i]);
            } while (i != rear[obj_no]);
        }
        printf("\n");
    }
}

int main() {
    int n1, n2;
    printf("Enter the number of stacks: ");
    scanf("%d", &n1);
    printf("Enter the number of queues: ");
    scanf("%d", &n2);

    int n = n1 + n2;
    if (n > MAX_OBJECTS) {
        printf("Cannot have more than %d data objects (stacks and queues).\n", MAX_OBJECTS);
        return 1;
    }

    initializeObjects(n1, n2);

    int choice, obj_no, value;
    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Display Stack/Queue\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1-%d): ", n1);
                scanf("%d", &obj_no);
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(obj_no - 1, value);
                break;
            case 2:
                printf("Enter stack number (1-%d): ", n1);
                scanf("%d", &obj_no);
                pop(obj_no - 1);
                break;
            case 3:
                printf("Enter queue number (1-%d): ", n2);
                scanf("%d", &obj_no);
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(n1 + obj_no - 1, value);
                break;
            case 4:
                printf("Enter queue number (1-%d): ", n2);
                scanf("%d", &obj_no);
                dequeue(n1 + obj_no - 1);
                break;
            case 5:
                printf("Enter data object number (1-%d for stacks, 1-%d for queues): ", n1, n2);
                scanf("%d", &obj_no);
                if (obj_no <= n1) {
                    display(obj_no - 1);
                } else {
                    display(n1 + obj_no - 1);
                }
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
