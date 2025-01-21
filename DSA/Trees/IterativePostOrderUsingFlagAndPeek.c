#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum stack size

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure of the stack element (node with a visited flag)
typedef struct {
    Node* node;
    int visited;  // 0 = first visit, 1 = ready to visit in postorder
} StackElement;

// Define the structure of the stack
typedef struct {
    StackElement array[MAX];
    int top;
} Stack;

// Stack initialization
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push a node with a visited flag onto the stack
void push(Stack* s, Node* node, int visited) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->array[++(s->top)].node = node;
    s->array[s->top].visited = visited;
}

// Pop a node with a visited flag from the stack
StackElement pop(Stack* s) {
    if (isEmpty(s)) {
        StackElement empty = {NULL, -1};
        return empty;
    }
    return s->array[(s->top)--];
}

// Peek at the top element of the stack without popping
StackElement peek(Stack* s) {
    if (isEmpty(s)) {
        StackElement empty = {NULL, -1};
        return empty;
    }
    return s->array[s->top];
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

// Iterative postorder traversal using one stack and a visited flag
void iterativePostorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Stack s;
    initStack(&s);

    push(&s, root, 0);  // Start with the root node and visited = 0

    printf("Postorder Traversal: ");
    while (!isEmpty(&s)) {
        StackElement topElement = peek(&s);  // Look at the top without popping
        Node* node = topElement.node;
        int visited = topElement.visited;

        if (visited == 1) {
            // If visited is 1, we are visiting this node in postorder
            printf("%d ", node->data);
            pop(&s);  // Now we actually pop the node from the stack
        } else {
            // First visit: update the flag and push right and left children
            s.array[s.top].visited = 1;  // Update the flag directly in the stack

            if (node->rchild != NULL) {
                push(&s, node->rchild, 0);  // Push the right child with visited = 0
            }
            if (node->lchild != NULL) {
                push(&s, node->lchild, 0);  // Push the left child with visited = 0
            }
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
