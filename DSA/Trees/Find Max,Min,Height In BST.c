#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
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

// Recursive function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the maximum element in the BST iteratively
int findMaxIterative(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// Function to find the maximum element in the BST recursively
int findMaxRecursive(Node* root) {
    if (root == NULL) {
        return -1;  // Return -1 if tree is empty
    }
    if (root->right == NULL) {
        return root->data;  // Max element found
    }
    return findMaxRecursive(root->right);  // Recur to the right subtree
}

// Function to find the minimum element in the BST iteratively
int findMinIterative(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find the minimum element in the BST recursively
int findMinRecursive(Node* root) {
    if (root == NULL) {
        return -1;  // Return -1 if tree is empty
    }
    if (root->left == NULL) {
        return root->data;  // Min element found
    }
    return findMinRecursive(root->left);  // Recur to the left subtree
}

// Separate function to find the maximum of two values
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Recursive function to find the height of the BST
int findHeight(Node* root) {
    if (root == NULL) {
        return -1;  // Height of an empty tree is -1
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    int data;
    char choice;

    printf("Binary Search Tree Implementation\n");

    // Insert nodes as provided by the user
    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Find and display the maximum element
    int maxElementIterative = findMaxIterative(root);
    int maxElementRecursive = findMaxRecursive(root);
    printf("Maximum element (Iterative): %d\n", maxElementIterative);
    printf("Maximum element (Recursive): %d\n", maxElementRecursive);

    // Find and display the minimum element
    int minElementIterative = findMinIterative(root);
    int minElementRecursive = findMinRecursive(root);
    printf("Minimum element (Iterative): %d\n", minElementIterative);
    printf("Minimum element (Recursive): %d\n", minElementRecursive);

    // Find and display the height of the tree
    int height = findHeight(root);
    printf("Height of the BST: %d\n", height);

    return 0;
}
