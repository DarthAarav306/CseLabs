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

// Recursive function to insert a node into the binary tree for testing
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
int pathFromNodeToRoot(Node* root, int target) {
    if (root == NULL) {
        return 0;  // Base case: reached a leaf or empty tree
    }

    // If the current node is the target, print it
    if (root->data == target) {
        printf("%d ", root->data); // Print the target node
        return 1;
    }

    // Recursively check the left and right subtrees
    if (pathFromNodeToRoot(root->left, target) || pathFromNodeToRoot(root->right, target)) {
        printf("%d ", root->data); // Print the current node on the way back
        return 1;
    }

    return 0;  // Target not found in this path
}

// Function to print ancestors of a target node
int printAncestors(Node* root, int target) {
    if (root == NULL) {
        return 0;  // Reached a leaf or empty tree
    }
    
    // If the current node is the target, we found it
    if (root->data == target) {
        return 1;
    }

    // Recursively check the left and right subtrees
    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data); // Print the ancestor if target found in subtree
        return 1;
    }

    return 0;  // Target not found in this path
}
int pathFromRootToNode(Node* root, int target) {
    if (root == NULL) {
        return 0;  // Reached a leaf or empty tree
    }

    printf("%d ", root->data); // Print the current node

    if (root->data == target) {
        return 1; // Stop once the target is found
    }

    // Recursively check left and right subtrees
    if (pathFromRootToNode(root->left, target) || pathFromRootToNode(root->right, target)) {
        return 1; // Target found in one of the subtrees
    }

    return 0;  // Backtrack if target not found
}

// Inorder traversal for visual confirmation of tree structure
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, data, target;

    // Basic operations to build and test the tree
    printf("Binary Tree Operations:\n");
    do {
        printf("\n1. Insert Node\n2. Display Inorder Traversal\n3. Print Ancestors\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Enter target node to find ancestors: ");
                scanf("%d", &target);
                printf("Ancestors of node %d: ", target);
                if (!printAncestors(root, target)) {
                    printf("Target node %d not found in the tree.", target);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
