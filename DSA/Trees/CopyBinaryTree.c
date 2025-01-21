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

// Function to copy a binary tree
Node* copyTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    // Create a new node with the same data as the current node
    Node* newNode = createNode(root->data);

    // Recursively copy the left and right subtrees
    newNode->lchild = copyTree(root->lchild);
    newNode->rchild = copyTree(root->rchild);

    return newNode;  // Return the root of the newly created subtree
}

// Function for inorder traversal to verify the copied tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
}

// Main function to create and copy a binary tree
int main() {
    int data;
    printf("Enter root node data (-1 for no root): ");
    scanf("%d", &data);

    // Create the original tree
    Node* root = createBinaryTree(data);

    // Copy the tree
    Node* copiedRoot = copyTree(root);

    // Verify the copied tree by printing inorder traversal
    printf("Inorder traversal of the original tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the copied tree: ");
    inorderTraversal(copiedRoot);
    printf("\n");

    return 0;
}
