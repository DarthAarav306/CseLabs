#include <stdio.h>
#include <stdlib.h>
#define MAX 100  // Define the maximum size of the stack

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure of the stack
typedef struct {
    Node* array[MAX];  // Array to hold the nodes
    int top;           // Index of the top element
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* s, Node* node) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->array[++s->top] = node;
}

// Pop an element from the stack
Node* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->array[s->top--];
}

// Function to create a new binary tree node
Node* createNewNode(int data) {
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
    
    Node* newNode = createNewNode(data);
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

// Function to perform iterative inorder traversal using array-based stack
void iterativeInorderTraversal(Node* root) {
    Stack s;
    initStack(&s);
    Node* current = root;

    printf("Inorder Traversal: ");
    while (current != NULL || !isEmpty(&s)) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(&s, current);
            current = current->lchild;
        }

        // Current must be NULL at this point, pop the top item from the stack
        current = pop(&s);
        printf("%d ", current->data);  // Visit the node

        // Move to the right subtree
        current = current->rchild;
    }
    printf("\n");
}

int main() {
    Node* root;
    int data;

    // Create the binary tree by taking root data from the user
    printf("Enter data for root (-1 for no root): ");
    scanf("%d", &data);

    root = createBinaryTree(data);  // Initialize root with the tree created

    // Perform iterative inorder traversal
    iterativeInorderTraversal(root);

    return 0;
}
