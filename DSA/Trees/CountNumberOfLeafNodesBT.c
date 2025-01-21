#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

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

// Function to count the total number of leaf nodes in a binary tree
int countLeafNodes(Node* root) {
    // Base case: If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    // Check if the current node is a leaf node
    if (root->lchild == NULL && root->rchild == NULL) {
        return 1;  // Return 1 if it's a leaf node
    }

    // Recursively count the leaf nodes in the left and right subtrees
    int leftLeafCount = countLeafNodes(root->lchild);
    int rightLeafCount = countLeafNodes(root->rchild);

    // Sum the counts from the left and right subtrees
    return leftLeafCount + rightLeafCount;
}

// Main function to create a binary tree and count its leaf nodes
int main() {
    int data;
    printf("Enter root node data (-1 for no root): ");
    scanf("%d", &data);

    // Create the binary tree
    Node* root = createBinaryTree(data);

    // Find and print the number of leaf nodes in the binary tree
    int leafCount = countLeafNodes(root);
    printf("The number of leaf nodes in the binary tree is: %d\n", leafCount);

    return 0;
}
