#include <stdio.h>
#include <stdlib.h>

// Define the node structure with lchild and rchild
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Recursive function to create a binary tree with a given root value
Node* createTree(int data) {
    if (data == -1) {
        return NULL;  // Base case: no node
    }

    // Create the root node
    Node* newNode = createNode(data);

    // Prompt the user to input left and right children
    int leftData, rightData;
    printf("Enter left child of %d (-1 for no node): ", data);
    scanf("%d", &leftData);
    newNode->lchild = createTree(leftData);  // Recursive call for the left subtree

    printf("Enter right child of %d (-1 for no node): ", data);
    scanf("%d", &rightData);
    newNode->rchild = createTree(rightData);  // Recursive call for the right subtree

    return newNode;
}

// Function to perform inorder traversal to verify the tree structure
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lchild);  // Visit left subtree
    printf("%d ", root->data);       // Visit node
    inorderTraversal(root->rchild);  // Visit right subtree
}

int main() {
    int rootData;
    printf("Enter data for root node: ");
    scanf("%d", &rootData);

    // Create the binary tree with the root node's value
    Node* root = createTree(rootData);

    // Perform inorder traversal to verify the tree structure
    printf("Inorder Traversal of the Tree: ");
    inorderTraversal(root);

    return 0;
}
