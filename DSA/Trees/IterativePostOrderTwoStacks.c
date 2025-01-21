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

// Iterative postorder traversal using two stacks
void iterativePostorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    // Push the root onto s1
    push(&s1, root);

    // Process all nodes in s1
    while (!isEmpty(&s1)) {
        Node* node = pop(&s1);
        push(&s2, node);  // Push current node to s2

        // Push left and right children of the node to s1
        if (node->lchild != NULL) {
            push(&s1, node->lchild);
        }
        if (node->rchild != NULL) {
            push(&s1, node->rchild);
        }
    }

    // s2 now contains nodes in postorder (Left, Right, Root) sequence
    printf("Postorder Traversal: ");
    while (!isEmpty(&s2)) {
        Node* node = pop(&s2);
        printf("%d ", node->data);
    }
    printf("\n");
}

// Main function to test the traversal
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

    iterativePostorderTraversal(root);  // Perform postorder traversal

    return 0;
}
