#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure of a stack for nodes
typedef struct {
    Node* array[100];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push a node onto the stack
void push(Stack* s, Node* node) {
    s->array[++(s->top)] = node;
}

// Pop a node from the stack
Node* pop(Stack* s) {
    return s->array[(s->top)--];
}

// Function to create a new node in the binary tree
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Function to build an expression tree from a postfix expression
Node* buildExpressionTree(char* postfix) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // If the symbol is an operand, create a node and push it onto the stack
        if (isalnum(symbol)) {
            Node* operandNode = createNode(symbol);
            push(&s, operandNode);
        }
        // If the symbol is an operator, pop two nodes, make them children, and push the new tree node
        else {
            Node* operatorNode = createNode(symbol);
            
            // Pop the right and left operands
            operatorNode->rchild = pop(&s);
            operatorNode->lchild = pop(&s);
            
            // Push the new subtree back onto the stack
            push(&s, operatorNode);
        }
    }
    
    // The remaining node in the stack is the root of the expression tree
    return pop(&s);
}

// Function to print the expression tree in inorder (to verify structure)
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    
    // Print left child, node, then right child
    if (!isalnum(root->data)) printf("(");  // Print opening parenthesis for operators
    
    inorderTraversal(root->lchild);
    printf("%c", root->data);
    inorderTraversal(root->rchild);
    
    if (!isalnum(root->data)) printf(")");  // Print closing parenthesis for operators
}

// Main function to build and display the expression tree
int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    // Build the expression tree from postfix expression
    Node* root = buildExpressionTree(postfix);
    
    // Display the tree in inorder (which will resemble the infix expression)
    printf("Inorder (infix) representation of the expression: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}
