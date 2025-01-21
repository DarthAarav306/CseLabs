#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty(int* p) {
    return top == -1;
}

// Function to check if the stack is full
int isFull(int* p) {
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int* p, int ele) {
    if (isFull(p)) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = ele;
        printf("%d Pushed\n", ele);
    }
}

// Function to pop an element from the stack
int pop(int* p) {
    if (isEmpty(p)) {
        printf("Underflow\n");
        return -1;  // Return -1 in case of underflow
    } else {
        int ele = stack[top];
        top--;
        printf("%d Popped\n", ele);
        return ele;
    }
}

// Function to display the stack elements
void display(int* p) {
    if (isEmpty(p)) {
        printf("Empty stack\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int decnum;
    int* p = stack;  // Pointer to the stack array

    printf("Enter decimal number: \n");
    scanf("%d", &decnum);  // Pass the address of decnum

    // Convert decimal to binary using the stack
    while (decnum != 0) {
        push(p, decnum % 2);
        decnum = decnum / 2;
    }

    // Display the binary number by popping the stack
    printf("Binary number is: ");
    while (!isEmpty(p)) {
        printf("%d", pop(p));
    }
    printf("\n");

    return 0;
}
