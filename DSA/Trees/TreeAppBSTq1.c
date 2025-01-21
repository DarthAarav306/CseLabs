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

// Iterative function to create a BST from an array of numbers
Node* createTree(int arr[], int n) {
    if (n <= 0) return NULL;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i]);
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = NULL;

            while (current != NULL) {
                parent = current;
                if (arr[i] < current->data) {
                    current = current->left;
                } else if (arr[i] > current->data) {
                    current = current->right;
                } else {
                    printf("Duplicate value %d not inserted.\n", arr[i]);
                    free(newNode);
                    break;
                }
            }
            if (arr[i] < parent->data) {
                parent->left = newNode;
            } else if (arr[i] > parent->data) {
                parent->right = newNode;
            }
        }
    }

    return root;
}

// Helper function to find the largest element in the left subtree iteratively (used for deletion)
Node* findMaxIterative(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Iterative function to delete a node from the BST
Node* deleteIterative(Node* root, int data) {
    Node* parent = NULL;
    Node* current = root;

    // Step 1: Find the node to delete and its parent
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", data);
        return root;
    }

    // Case 1: Node with no children (leaf node)
    if (current->left == NULL && current->right == NULL) {
        if (current != root) {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }
        free(current);
    }
    // Case 2: Node with one child
    else if (current->left == NULL || current->right == NULL) {
        Node* child = (current->left) ? current->left : current->right;

        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        free(current);
    }
    // Case 3: Node with two children
    else {
        // Find the maximum node in the left subtree (inorder predecessor)
        Node* maxNodeParent = current;
        Node* maxNode = current->left;

        while (maxNode->right != NULL) {
            maxNodeParent = maxNode;
            maxNode = maxNode->right;
        }

        // Copy the data from maxNode to current node
        current->data = maxNode->data;

        // Now delete the maxNode, which is guaranteed to have at most one child
        if (maxNode->left) { // maxNode has a left child
            if (maxNodeParent->right == maxNode) {
                maxNodeParent->right = maxNode->left;
            } else {
                maxNodeParent->left = maxNode->left;
            }
        } else { // maxNode is a leaf
            if (maxNodeParent->right == maxNode) {
                maxNodeParent->right = NULL;
            } else {
                maxNodeParent->left = NULL;
            }
        }
        free(maxNode);
    }

    return root;
}

// Iterative in-order traversal to display the BST
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Current must be NULL at this point
        current = stack[top--];
        printf("%d ", current->data);

        // Visit the right subtree
        current = current->right;
    }
    printf("\n");
}

int main() {
    Node* root = NULL;
    int choice, n, data;

    printf("Binary Search Tree Operations:\n");
    do {
        printf("1. Create BST\n2. Delete Element\n3. Display Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter list: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                root = createTree(arr, n);
                break;
            }

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = deleteIterative(root, data);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
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
