#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Global variables
char stack[MAX];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(char ele) {
    if (isFull()) {
        printf("Stack is full.\n");
    } else {
        top++;
        stack[top] = ele;
        printf("Element %c pushed in stack\n", ele);
    }
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return '\0';  // Return null character if the stack is empty
    } else {
        char ele = stack[top];
        top--;
        return ele;
    }
}

// Function to display the stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%c\n", stack[i]);
        }
    }
}

int main() {
    char str[80];
    char reversedStr[80];
    int i = 0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    // Push all characters of the string onto the stack
    while (str[i] != '\0' && str[i] != '\n') {  // '\0' is the string terminator, and '\n' handles new line
        push(str[i]);
        i++;
    }

    // Pop all characters from the stack to reverse the string
    i = 0;
    while (!isEmpty()) {
        reversedStr[i++] = pop();
    }
    reversedStr[i] = '\0';  // Add null terminator to the end of the reversed string

    printf("Reversed string: %s\n", reversedStr);

    return 0;
}
