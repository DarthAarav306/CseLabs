#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Node structure for the expression tree
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Stack to hold tree nodes while constructing the tree
typedef struct {
    Node* array[MAX_SIZE];
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
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->array[++(s->top)] = node;
}

// Pop a node from the stack
Node* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->array[(s->top)--];
}

// Function to create a new tree node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create an expression tree from prefix expression
Node* createExpressionTree(char* prefix) {
    Stack s;
    initStack(&s);

    // Traverse the prefix expression from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {  // If operand, create a node and push it onto the stack
            push(&s, createNode(prefix[i]));
        } else {  // If operator, create a node, pop two nodes, and attach them as children
            Node* operatorNode = createNode(prefix[i]);
            operatorNode->left = pop(&s);
            operatorNode->right = pop(&s);
            push(&s, operatorNode);
        }
    }

    // The final node on the stack is the root of the expression tree
    return pop(&s);
}

// Recursive function to evaluate the expression tree
int evaluateExpressionTree(Node* root) {
    if (root == NULL) return 0;

    // If it's a leaf node (operand), convert it to integer and return
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';  // Convert char to int
    }

    // Evaluate the left and right subtrees
    int leftEval = evaluateExpressionTree(root->left);
    int rightEval = evaluateExpressionTree(root->right);

    // Perform the operation based on the operator in the root node
    switch (root->data) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0;
}

// Function to print the tree in inorder for verification
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int main() {
    char prefix[MAX_SIZE];
    
    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    // Create the expression tree from the given prefix expression
    Node* root = createExpressionTree(prefix);

    printf("Inorder traversal of the expression tree: ");
    inorderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
