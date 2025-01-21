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

// Function to count the total number of nodes in a binary tree
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;  // Return 0 for an empty tree
    }

    // Count the current node, then recursively count left and right subtrees
    int leftCount = countNodes(root->lchild);
    int rightCount = countNodes(root->rchild);

    return 1 + leftCount + rightCount;  // 1 for the current node, plus left and right counts
}

// Main function to create a binary tree and count its nodes
int main() {
    int data;
    printf("Enter root node data (-1 for no root): ");
    scanf("%d", &data);

    // Create the binary tree
    Node* root = createBinaryTree(data);

    // Find and print the number of nodes in the binary tree
    int totalNodes = countNodes(root);
    printf("The number of nodes in the binary tree is: %d\n", totalNodes);

    return 0;
}
