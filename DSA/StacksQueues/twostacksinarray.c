#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int data[MAX_SIZE];
int top1;  // Top for Stack 1
int top2;  // Top for Stack 2

// Initialize the two stacks
void initialize() {
    top1 = -1;
    top2 = MAX_SIZE;
}

// Push operation for the first stack
void push1(int value) {
    if (top1 < top2 - 1) {
        data[++top1] = value;
        printf("Pushed %d into Stack 1\n", value);
    } else {
        printf("Stack 1 Overflow\n");
    }
}

// Push operation for the second stack
void push2(int value) {
    if (top1 < top2 - 1) {
        data[--top2] = value;
        printf("Pushed %d into Stack 2\n", value);
    } else {
        printf("Stack 2 Overflow\n");
    }
}

// Pop operation for the first stack
int pop1() {
    if (top1 >= 0) {
        int value = data[top1--];
        printf("Popped %d from Stack 1\n", value);
        return value;
    } else {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

// Pop operation for the second stack
int pop2() {
    if (top2 < MAX_SIZE) {
        int value = data[top2++];
        printf("Popped %d from Stack 2\n", value);
        return value;
    } else {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}

// Display the elements in Stack 1
void displayStack1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

// Display the elements in Stack 2
void displayStack2() {
    if (top2 == MAX_SIZE) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements: ");
        for (int i = MAX_SIZE - 1; i >= top2; i--) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

// Main function to test the implementation
int main() {
    initialize();
    int choice, value;

    do {
        printf("\n1. Push to Stack 1");
        printf("\n2. Push to Stack 2");
        printf("\n3. Pop from Stack 1");
        printf("\n4. Pop from Stack 2");
        printf("\n5. Display Stack 1");
        printf("\n6. Display Stack 2");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                displayStack1();
                break;
            case 6:
                displayStack2();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 7);

    return 0;
}
