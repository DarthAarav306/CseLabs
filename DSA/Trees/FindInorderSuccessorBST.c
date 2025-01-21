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

// Recursive function to insert a node into the BST
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

// Function to create a BST from an array of numbers using recursion
Node* createTree(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Recursive function to perform in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the in-order successor
Node* findInOrderSuccessor(Node* root, Node* target) {
    if (target->right != NULL) {
        // Case 1: If the node has a right subtree, find the minimum in the right subtree
        return findMin(target->right);
    }

    // Case 2: If the node has no right subtree, find the lowest ancestor
    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != NULL) {
        if (target->data < ancestor->data) {
            successor = ancestor; // Successor might be this ancestor
            ancestor = ancestor->left; // Move to the left subtree
        } else if (target->data > ancestor->data) {
            ancestor = ancestor->right; // Move to the right subtree
        } else {
            break; // Stop when the target node is found
        }
    }

    return successor;
}

// Recursive function to find the in-order successor of a given node in the BST
Node* findInorderSuccessorRecursive(Node* root, Node* target, Node* successor) {
    if (root == NULL) return successor;

    if (target->data < root->data) {
        return findInorderSuccessorRecursive(root->left, target, root);
    } else if (target->data > root->data) {
        return findInorderSuccessorRecursive(root->right, target, successor);
    } else {
        if (root->right != NULL) {
            return leftmost(root->right);
        }
    }
    return successor;
}

// Function to find a node with a given value
Node* findNode(Node* root, int data) {
    while (root != NULL) {
        if (data < root->data) {
            root = root->left;
        } else if (data > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    int choice, n, data;

    printf("Binary Search Tree Operations:\n");
    do {
        printf("1. Create Tree\n2. Find Inorder Successor (Iterative)\n3. Find Inorder Successor (Recursive)\n4. Display Inorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter elements to create BST: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                root = createTree(arr, n);
                break;
            }

            case 2:
                printf("Enter element to find inorder successor (Iterative): ");
                scanf("%d", &data);
                Node* target = findNode(root, data);
                if (target) {
                    Node* successor = findInorderSuccessorIterative(root, target);
                    if (successor) {
                        printf("Inorder successor of %d is %d (Iterative)\n", data, successor->data);
                    } else {
                        printf("No inorder successor found for %d.\n", data);
                    }
                } else {
                    printf("Node with value %d not found in the tree.\n", data);
                }
                break;

            case 3:
                printf("Enter element to find inorder successor (Recursive): ");
                scanf("%d", &data);
                target = findNode(root, data);
                if (target) {
                    Node* successor = findInorderSuccessorRecursive(root, target, NULL);
                    if (successor) {
                        printf("Inorder successor of %d is %d (Recursive)\n", data, successor->data);
                    } else {
                        printf("No inorder successor found for %d.\n", data);
                    }
                } else {
                    printf("Node with value %d not found in the tree.\n");
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
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
