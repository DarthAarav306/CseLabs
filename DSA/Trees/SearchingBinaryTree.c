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

// Function to search for a value in the binary tree
int searchBinaryTree(Node* root, int target) {
    // Base case: if the root is NULL, return 0 (not found)
    if (root == NULL) {
        return 0;
    }

    // If the target is found at the current node, return 1
    if (root->data == target) {
        return 1;
    }

    // Recursively search in the left and right subtrees
    // If found in either subtree, return 1
    if (searchBinaryTree(root->lchild, target) || searchBinaryTree(root->rchild, target)) {
        return 1;
    }

    // If not found in both subtrees, return 0
    return 0;
}

// Main function to create a binary tree and search for an element
int main() {
    int data;
    printf("Enter root node data (-1 for no root): ");
    scanf("%d", &data);

    // Create the binary tree
    Node* root = createBinaryTree(data);

    // Prompt the user for the target value to search
    int target;
    printf("Enter the value to search: ");
    scanf("%d", &target);

    // Search the binary tree for the target value
    if (searchBinaryTree(root, target)) {
        printf("Value %d found in the tree.\n", target);
    } else {
        printf("Value %d not found in the tree.\n", target);
    }

    return 0;
}
