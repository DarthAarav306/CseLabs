#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree based on user input
Node* createBinaryTree() {
    int data;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);

    // If the input is -1, this means there is no node (NULL)
    if (data == -1) {
        return NULL;
    }

    // Create the root node with the provided data
    Node* newNode = createNode(data);

    // Recursively create the left and right subtrees
    printf("Enter left child of %d\n", data);
    newNode->left = createBinaryTree();

    printf("Enter right child of %d\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to print all ancestors of a given key
int printAncestors(Node* root, int key) {
    // Base case: if root is NULL, return false
    if (root == NULL) {
        return 0;
    }

    // If the key is found at the current node, return true
    if (root->data == key) {
        return 1;
    }

    // Recur for left and right subtrees. If key is found in either subtree,
    // print the current node's data and return true.
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }

    // If key is not found in either subtree, return false
    return 0;
}

int main() {
    Node* root = NULL;
    int key;

    // Create the binary tree from user input
    printf("Create the binary tree:\n");
    root = createBinaryTree();

    // Ask the user for the key to find its ancestors
    printf("Enter the key to find its ancestors: ");
    scanf("%d", &key);

    printf("Ancestors of %d are: ", key);
    if (!printAncestors(root, key)) {
        printf("No ancestors found or key not present in the tree.\n");
    } else {
        printf("\n");
    }

    return 0;
}
