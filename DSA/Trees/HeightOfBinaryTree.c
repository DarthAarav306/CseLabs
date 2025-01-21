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

// Function to return the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Function to find the height of a binary tree
int findHeight(Node* root) {
    if (root == NULL) {
        return 0;  // Return 0 for an empty tree
    }

    // Find the height of the left and right subtrees
    int leftHeight = findHeight(root->lchild);
    int rightHeight = findHeight(root->rchild);

    // Height of the tree is 1 + max height of left and right subtrees
    return 1 + max(leftHeight, rightHeight);
}

// Main function to create a binary tree and find its height
int main() {
    int data;
    printf("Enter root node data (-1 for no root): ");
    scanf("%d", &data);

    // Create the binary tree
    Node* root = createBinaryTree(data);

    // Find and print the height of the binary tree
    int height = findHeight(root);
    printf("The height of the binary tree is: %d\n", height);

    return 0;
}
