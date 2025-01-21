#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 20
#define MAX_STACKS 4

int memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS + 1];  // One extra for final boundary

void initializeStacks(int n) {
    // Set up boundaries and tops for each stack
    top[0] = boundary[0] = -1;
    for (int i = 1; i < n; i++) {
        top[i] = boundary[i] = (MEMORY_SIZE / n) * i - 1;
    }
    boundary[n] = MEMORY_SIZE - 1;
}

void push(int stack_no, int item, int n) {
    if (top[stack_no] == boundary[stack_no + 1]) {
        printf("Stack %d Overflow\n", stack_no + 1);
    } else {
        memory[++top[stack_no]] = item;
        printf("Pushed %d into Stack %d\n", item, stack_no + 1);
    }
}

int pop(int stack_no) {
    if (top[stack_no] == boundary[stack_no]) {
        printf("Stack %d Underflow\n", stack_no + 1);
        return -1;  // Indicating an underflow
    } else {
        int item = memory[top[stack_no]--];
        printf("Popped %d from Stack %d\n", item, stack_no + 1);
        return item;
    }
}

void displayStack(int stack_no) {
    if (top[stack_no] == boundary[stack_no]) {
        printf("Stack %d is Empty\n", stack_no + 1);
    } else {
        printf("Stack %d elements: ", stack_no + 1);
        for (int i = boundary[stack_no] + 1; i <= top[stack_no]; i++) {
            printf("%d ", memory[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of stacks (maximum %d): ", MAX_STACKS);
    scanf("%d", &n);
    if (n > MAX_STACKS) {
        printf("Cannot have more than %d stacks.\n", MAX_STACKS);
        return 1;
    }

    initializeStacks(n);

    int choice, stack_no, item;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n2. Pop\n3. Display a Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1-%d): ", n);
                scanf("%d", &stack_no);
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(stack_no - 1, item, n);
                break;
            case 2:
                printf("Enter stack number (1-%d): ", n);
                scanf("%d", &stack_no);
                pop(stack_no - 1);
                break;
            case 3:
                printf("Enter stack number (1-%d): ", n);
                scanf("%d", &stack_no);
                displayStack(stack_no - 1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
