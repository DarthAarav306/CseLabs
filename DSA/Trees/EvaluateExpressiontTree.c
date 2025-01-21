#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the structure of a node in the expression tree
typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Function to create a new node in the expression tree
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

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
            operatorNode->rchild = pop(&s);
            operatorNode->lchild = pop(&s);
            push(&s, operatorNode);
        }
    }
    return pop(&s);  // The remaining node in the stack is the root of the expression tree
}

// Function to evaluate the expression tree
int evaluateExpressionTree(Node* root) {
    // If the node is a leaf (operand), convert it to an integer and return it
    if (root->lchild == NULL && root->rchild == NULL) {
        return root->data - '0';  // Convert char to int (assumes single-digit operands)
    }

    // Recursively evaluate the left and right subtrees
    int leftValue = evaluateExpressionTree(root->lchild);
    int rightValue = evaluateExpressionTree(root->rchild);

    // Apply the operator at the current node
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;  // Assumes no division by zero in input
    }
    return 0;
}

// Main function to build and evaluate the expression tree
int main() {
    char postfix[100];
    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    // Build the expression tree from postfix expression
    Node* root = buildExpressionTree(postfix);

    // Evaluate and print the result
    int result = evaluateExpressionTree(root);
    printf("The result of the expression is: %d\n", result);

    return 0;
}
