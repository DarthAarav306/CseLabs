#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to find the depth of a node in a binary tree
int findDepth(Node* root, int target, int depth) {
    if (root == NULL) {
        return -1; // Node not found
    }
    
    if (root->data == target) {
        return depth; // Node found, return the current depth
    }
    
    // Search in the left subtree
    int leftDepth = findDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth; // Node found in the left subtree
    }
    
    // Search in the right subtree
    return findDepth(root->right, target, depth + 1);
}

// Wrapper function to start depth search from depth 0
int getDepth(Node* root, int target) {
    return findDepth(root, target, 0);
}

// Main function to demonstrate the code
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int target = 5;
    int depth = getDepth(root, target);
    
    if (depth != -1) {
        printf("Depth of node with value %d is %d.\n", target, depth);
    } else {
        printf("Node with value %d not found in the tree.\n", target);
    }

    return 0;
}
