#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

void insertAtBottom(Stack* s, int value) {
    if (isEmpty(s)) {
        push(s, value);
    } else {
        int temp = pop(s);
        insertAtBottom(s, value);
        push(s, temp);
    }
}

void rev(Stack* s) {
    if (isEmpty(s)) {
        return;
    }
    int temp = pop(s);
    rev(s);  // Recursively reverse the rest of the stack
    insertAtBottom(s, temp);  // Insert the popped element at the bottom
}

}

int main() {
    Stack s;
    initialize(&s);

    int n, value;
    printf("Enter the number of elements you want to push onto the stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    printf("Original Stack:\n");
    display(&s);

    reverseStack(&s);

    printf("Reversed Stack:\n");
    display(&s);

    return 0;
}
