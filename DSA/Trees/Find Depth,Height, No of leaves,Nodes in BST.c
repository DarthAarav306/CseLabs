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

// Recursive function to insert a node in the BST
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

int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;  // Change here: empty tree height as 0
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


// Function to calculate the depth of a node in the tree
int calculateDepth(Node* root, int data, int depth) {
    if (root == NULL) {
        return -1;  // Node not found
    }
    if (root->data == data) {
        return depth;
    } else if (data < root->data) {
        return calculateDepth(root->left, data, depth + 1);
    } else {
        return calculateDepth(root->right, data, depth + 1);
    }
}

int findDepth(Node* root, int target) {
    int depth = 0;

    while (root != NULL) {
        if (target == root->data) {
            return depth; // Return the depth when the target is found
        } else if (target < root->data) {
            root = root->left; // Move to the left subtree
        } else {
            root = root->right; // Move to the right subtree
        }
        depth++; // Increment depth at each level
    }

    return -1; // Return -1 if the target is not found
}
int findDepthRecursive(Node* root, int target) {
    if (root == NULL) {
        return -1; // Return -1 if the tree is empty or the target is not found
    }

    if (root->data == target) {
        return 0; // The root node itself is at depth 0
    }

    if (target < root->data) {
        int leftDepth = findDepthRecursive(root->left, target);
        return (leftDepth == -1) ? -1 : leftDepth + 1; // Add 1 to the depth if found in left subtree
    } else {
        int rightDepth = findDepthRecursive(root->right, target);
        return (rightDepth == -1) ? -1 : rightDepth + 1; // Add 1 to the depth if found in right subtree
    }
}


// Function to count the total number of nodes in the tree
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaf nodes in the tree
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = NULL;
    int choice, data;

    printf("Binary Search Tree Operations:\n");
    do {
        printf("1. Insert Node\n2. Calculate Depth\n3. Calculate Height\n4. Count Total Nodes\n5. Count Leaf Nodes\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter node value to calculate depth: ");
                scanf("%d", &data);
                int depth = calculateDepth(root, data, 0);
                if (depth != -1) {
                    printf("Depth of node %d is %d\n", data, depth);
                } else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 3:
                printf("Height of the BST is %d\n", calculateHeight(root));
                break;

            case 4:
                printf("Total number of nodes in the BST is %d\n", countNodes(root));
                break;

            case 5:
                printf("Total number of leaf nodes in the BST is %d\n", countLeaves(root));
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
