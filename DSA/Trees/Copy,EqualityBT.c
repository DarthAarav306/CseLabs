#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node in the binary tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree with user input
Node* createBinaryTree() {
    int data;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    Node* newNode = createNode(data);

    printf("Enter left child of %d\n", data);
    newNode->left = createBinaryTree();

    printf("Enter right child of %d\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to create a copy of a binary tree
Node* copyTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Function to check if two binary trees are identical
int areTreesEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;  // Both trees are empty, hence equal
    }
    if (root1 == NULL || root2 == NULL) {
        return 0;  // One tree is empty, and the other is not
    }

    // Check if the data in current nodes are the same and
    // recursively check the left and right subtrees
    return (root1->data == root2->data) &&
           areTreesEqual(root1->left, root2->left) &&
           areTreesEqual(root1->right, root2->right);
}

// In-order traversal to display tree data
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    printf("Creating the original binary tree.\n");
    Node* root1 = createBinaryTree();

    printf("In-order traversal of original tree: ");
    inorderTraversal(root1);
    printf("\n");

    // Create a copy of the binary tree
    Node* root2 = copyTree(root1);
    printf("In-order traversal of copied tree: ");
    inorderTraversal(root2);
    printf("\n");

    // Test for equality between the original and copied tree
    if (areTreesEqual(root1, root2)) {
        printf("The original and copied trees are identical.\n");
    } else {
        printf("The original and copied trees are not identical.\n");
    }

    return 0;
}
