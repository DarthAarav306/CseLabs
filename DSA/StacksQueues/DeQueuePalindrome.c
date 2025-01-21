#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    char deque[MAX];
    int front;
    int rear;
} Deque;

// Initialize the deque
void initialize(Deque* dq) {
    dq->front = 0;  // Front is always empty
    dq->rear = 0;
}

// Check if the deque is empty
int isEmpty(Deque* dq) {
    return dq->front == dq->rear;
}

// Check if the deque is full (empty-slot method)
int isFull(Deque* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

// Insert an element at the rear
void insertRear(Deque* dq, char value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
    } else {
        dq->rear = (dq->rear + 1) % MAX;  // Move rear first to ensure front remains empty
        dq->deque[dq->rear] = value;      // Now insert the value at the new rear position
    }
}

// Delete an element from the front
char deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    } else {
        dq->front = (dq->front + 1) % MAX;  // Move front first
        return dq->deque[dq->front];  // Then access the element
    }
}

// Delete an element from the rear
char deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    } else {
        char ele = dq->deque[dq->rear];
        dq->rear = (dq->rear - 1 + MAX) % MAX;  // Move rear back first
        return ele;  // Return the rear element
    }
}

// Function to check if a string is a palindrome using deque (with empty front)
int isPalindrome(char* str) {
    Deque dq;
    initialize(&dq);

    // Insert all characters of the string into the deque
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {  // Only consider alphabetic characters
            insertRear(&dq, tolower(str[i]));  // Convert to lowercase and insert
        }
    }

    // Check if the string is a palindrome
    while ((dq.rear - dq.front + MAX) % MAX > 1) {  // Keep comparing until 1 or 0 element is left
        if (deleteFront(&dq) != deleteRear(&dq)) {
            return 0;  // Not a palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);  // Use scanf to take string input without spaces

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
