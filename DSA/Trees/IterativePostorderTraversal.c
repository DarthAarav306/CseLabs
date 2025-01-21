#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define the structure for a stack node
typedef struct Stack {
    TreeNode* treeNode;  // Holds a tree node
    struct Stack* next;  // Points to the next stack node (next element in the stack)
} Stack;

// Function to create a new tree node
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
    newStackNode->treeNode = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

// Function to pop a tree node from the stack
TreeNode* pop(Stack** top) {
    if (*top == NULL) {
        return NULL;
    }
    Stack* temp = *top;
    TreeNode* node = temp->treeNode;
    *top = (*top)->next;
    free(temp);
    return node;
}

// Function to check if the stack is empty
int isEmpty(Stack* top) {
    return top == NULL;
}

// Function to peek at the top node of the stack (without popping)
TreeNode* peek(Stack* top) {
    if (top == NULL) {
        return NULL;
    }
    return top->treeNode;
}

// Function to perform iterative postorder traversal using one stack
void iterativePostorderTraversal(TreeNode* root) {
    if (root == NULL) return;  // If the tree is empty, return

    Stack* stack = NULL;  // Initialize the stack
    TreeNode* current = root;  // Start with the root node
    TreeNode* lastVisitedNode = NULL;  // Keep track of the last node that was visited

    // Continue until you've visited all nodes (when current is NULL and stack is empty)
    while (current != NULL || !isEmpty(stack)) {
        if (current != NULL) {
            // Traverse left, push all left children onto the stack
            push(&stack, current);  // Push the current node onto the stack
            current = current->left;  // Move to the left child
        } else {
            // Peek the node at the top of the stack
            TreeNode* topNode = peek(stack);

            // Check if the right subtree exists and hasn't been visited
            if (topNode->right != NULL && lastVisitedNode != topNode->right) {
                current = topNode->right;  // Move to the right subtree
            } else {
                // Visit the node (because both left and right have been visited)
                printf("%d ", topNode->data);
                
                // Mark this node as visited
                lastVisitedNode = pop(&stack);  // Pop the node from the stack
            }
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
    TreeNode* root = createNode(1);  // Root node (1)
    root->left = createNode(2);  // Left child of root (2)
    root->right = createNode(3);  // Right child of root (3)
    root->left->left = createNode(4);  // Left child of node 2 (4)
    root->left->right = createNode(5);  // Right child of node 2 (5)

    printf("Postorder Traversal: ");
    iterativePostorderTraversal(root);
    printf("\n");

    return 0;
}
