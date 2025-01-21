#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Stack structure to store tree nodes
typedef struct Stack {
    TreeNode* data;
    struct Stack* next;
} Stack;

// Create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a tree node onto the stack
void push(Stack** top, TreeNode* node) {
    Stack* newStackNode = (Stack*)malloc(sizeof(Stack));
    newStackNode->data = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

// Function to pop a tree node from the stack
TreeNode* pop(Stack** top) {
    if (*top == NULL) {
        return NULL;
    }
    Stack* temp = *top;
    TreeNode* node = temp->data;
    *top = (*top)->next;
    free(temp);
    return node;
}

// Function to check if the stack is empty
int isEmpty(Stack* top) {
    return top == NULL;
}

// Iterative preorder traversal function
void iterativePreorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Initialize stack
    Stack* stack = NULL;

    // Push the root node to start the traversal
    push(&stack, root);

    // Loop until the stack is empty
    while (!isEmpty(stack)) {
        // Pop the top node and print it (visiting the node)
        TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        // Push the right child first, so the left child gets processed first
        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

int main() {
    // Creating a simple binary tree:
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    iterativePreorderTraversal(root);
    printf("\n");

    return 0;
}
