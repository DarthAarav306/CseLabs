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
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        // Ensure stack is not empty before accessing stack[top]
        while (!isEmpty(stack) && arr[i] > stack[top] && k > 0) {
            pop(stack);
            k--;
        }
        push(stack, arr[i]);
    }

    // Remove extra elements if k is still greater than 0
    while (k > 0 && !isEmpty(stack)) {
        pop(stack);
        k--;
    }

    printf("New Array is:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
