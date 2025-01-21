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

// Recursive function to build a BST by inserting nodes in BST order
Node* createBSTRecursive() {
    int data;
    printf("Enter data (-1 to stop): ");
    scanf("%d", &data);

    // Stop if user inputs -1
    if (data == -1) {
        return NULL;
    }

    // Create the root node
    Node* root = createNode(data);

    // Recursively create the left and right subtrees following BST rules
    printf("Inserting left child of %d\n", data);
    root->left = createBSTRecursive();

    printf("Inserting right child of %d\n", data);
    root->right = createBSTRecursive();

    return root;
}

// Iterative function to insert a node into the BST
Node* insertIntoBSTIterative(Node* root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;
    char direction;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            printf("Duplicate value %d not inserted.\n", data);
            return root;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

Node* insertIntoBSTIterative(Node* root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    // Traverse the tree to find the correct position
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            // If data already exists, do not insert duplicate
            printf("Duplicate value %d not inserted.\n", data);
            return root;
        }
    }

    // Insert as left or right child based on the value comparison
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Iterative function to delete a node from the BST
Node* deleteFromBSTIterative(Node* root, int data) {
    Node* parent = NULL;
    Node* current = root;

    // Step 1: Locate the node to delete and its parent
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node was not found in the BST, return the unchanged root
    if (current == NULL) {
        printf("Node with value %d not found.\n", data);
        return root;
    }

    // Case 1: Node with no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        // If current is not the root, disconnect it from its parent
        if (current != root) {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            // If deleting the root node itself
            root = NULL;
        }
        free(current);
    }
    // Case 2: Node with one child
    else if (current->left == NULL || current->right == NULL) {
        Node* child;
        // Determine whether the child is left or right
        if (current->left != NULL) {
            child = current->left;
        } else {
            child = current->right;
        }

        // If current is not the root, link the parent to the child
        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            // If current is the root, update root to the child
            root = child;
        }
        free(current);
    }
    // Case 3: Node with two children
    else {
        Node* successor = current->right;
        Node* successorParent = current;

        // Uncomment the following for Inorder Successor

        // Find the inorder successor (smallest node in right subtree)
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // OR Uncomment the following for Inorder Predecessor
        /*
        // Find the inorder predecessor (largest node in left subtree)
        successor = current->left;
        successorParent = current;
        while (successor->right != NULL) {
            successorParent = successor;
            successor = successor->right;
        }
        */

        // Copy the successor’s data to the current node
        current->data = successor->data;

        // Delete the successor node, which is now redundant
        if (successorParent->left == successor) {
            // Successor is left child of its parent
            successorParent->left = successor->right;
        } else {
            // Successor is right child of its parent
            successorParent->right = successor->right;
        }

        free(successor);
    }

    return root;
}

// Function for inorder traversal to display the BST
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int choice, data;

    printf("Binary Search Tree Operations:\n");
    do {
        printf("1. Create BST (Recursive)\n2. Insert (Iterative)\n3. Delete (Iterative)\n4. Display Inorder\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createBSTRecursive();
                break;

            case 2:
                printf("Enter data to insert (Iterative): ");
                scanf("%d", &data);
                root = insertIntoBSTIterative(root, data);
                break;

            case 3:
                printf("Enter data to delete (Iterative): ");
                scanf("%d", &data);
                root = deleteFromBSTIterative(root, data);
                break;

            case 4:
                printf("Inorder Traversal of BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
