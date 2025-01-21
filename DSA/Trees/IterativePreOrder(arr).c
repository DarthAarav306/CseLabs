#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum stack size

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure of the stack
typedef struct {
    Node* array[MAX];
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

// Push a node onto the stack
void push(Stack* s, Node* node) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->array[++(s->top)] = node;
}

// Pop a node from the stack
Node* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->array[(s->top)--];
}

// Peek at the top node of the stack
Node* peek(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
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

// Iterative preorder traversal using a single stack
void iterativePreorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Stack s;
    initStack(&s);

    // Start with the root node
    push(&s, root);

    printf("Preorder Traversal: ");
    while (!isEmpty(&s)) {
        Node* node = pop(&s);  // Pop the top node
        printf("%d ", node->data);  // Visit the node (Root)

        // Push right and left children onto the stack
        // Push the right child first so that the left child is processed next
        if (node->rchild != NULL) {
            push(&s, node->rchild);
        }
        if (node->lchild != NULL) {
            push(&s, node->lchild);
        }
    }
    printf("\n");
}

// Main function to create a sample tree and perform preorder traversal
int main() {
    // Constructing a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);

    iterativePreorderTraversal(root);  // Perform preorder traversal

    return 0;
}
