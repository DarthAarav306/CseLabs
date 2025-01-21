#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the structure of a node in the expression tree
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Stack structure to hold nodes during tree construction
typedef struct Stack {
    Node* array[100];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push node onto stack
void push(Stack* s, Node* node) {
    s->array[++(s->top)] = node;
}

// Pop node from stack
Node* pop(Stack* s) {
    return s->array[(s->top)--];
}

// Create a new tree node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Construct expression tree from postfix expression
Node* constructTree(char postfix[]) {
    Stack s;
    initStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            // Operand: Create node and push to stack
            Node* newNode = createNode(ch);
            push(&s, newNode);
        } else {
            // Operator: Pop two nodes, make them children of new node, and push
            Node* newNode = createNode(ch);
            newNode->right = pop(&s);
            newNode->left = pop(&s);
            push(&s, newNode);
        }
    }
    // The root of the expression tree
    return pop(&s);
}

// Evaluate the expression tree recursively
int evaluate(Node* root) {
    if (root == NULL) return 0;
    
    // If it's a leaf node, return its value (operand)
    if (root->left == NULL && root->right == NULL)
        return root->data - '0'; // Convert char to int
    
    // Evaluate left and right subtrees
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);
    
    // Apply operator on left and right values
    switch (root->data) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
    }
    return 0;
}

// In-order traversal (optional: to display the expression tree structure)
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Construct the expression tree
    Node* root = constructTree(postfix);

    // Display the tree in in-order (optional)
    printf("Inorder traversal of the expression tree: ");
    inorderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluate(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}
