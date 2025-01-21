#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum stack size

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the stack structure
typedef struct Stack {
    Node* arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push a node onto the stack
void push(Stack* s, Node* node) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = node;
}

// Function to pop a node from the stack
Node* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->arr[(s->top)--];
}

// Function to peek at the top node of the stack
Node* peek(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->arr[s->top];
}

// Function to create a new node in the binary tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Function to create the binary tree using user input
Node* createBinaryTree(int data) {
    if (data == -1) {
        return NULL;
    }
    
    Node* newNode = createNode(data);
    int ldata, rdata;

    // Input and create left child
    printf("Enter data for left child of %d (-1 to stop): ", data);
    scanf("%d", &ldata);
    newNode->lchild = createBinaryTree(ldata);

    // Input and create right child
    printf("Enter data for right child of %d (-1 to stop): ", data);
    scanf("%d", &rdata);
    newNode->rchild = createBinaryTree(rdata);

    return newNode;
}

// Iterative postorder traversal using one stack
void iterativePostorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Stack s;
    initStack(&s); // Initialize the stack
    Node* current = root;
    Node* lastVisited = NULL;

    printf("Postorder Traversal: ");
    while (current != NULL || !isEmpty(&s)) {
        // Reach the leftmost node of the current subtree
        while (current != NULL) {
            push(&s, current);
            current = current->lchild;
        }

        // Peek the node on top of the stack
        Node* topNode = peek(&s);

        // If the right child exists and hasn't been visited yet, go to the right child
        if (topNode->rchild != NULL && lastVisited != topNode->rchild) {
            current = topNode->rchild;
        } else {
            // Visit the node
            printf("%d ", topNode->data);
            lastVisited = pop(&s);  // Update last visited after popping
        }
    }
    printf("\n");
}

// Main function to take input and perform postorder traversal
int main() {
    Node* root;
    int data;

    // Take input to create the binary tree
    printf("Enter data for root (-1 for no root): ");
    scanf("%d", &data);

    root = createBinaryTree(data);  // Initialize root with the tree created

    // Perform iterative postorder traversal
    iterativePostorderTraversal(root);

    return 0;
}
