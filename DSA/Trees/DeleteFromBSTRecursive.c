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
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Function to find the inorder successor (smallest in the right subtree)
Node* findInorderSuccessor(Node* root) {
    Node* current = root->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to find the inorder predecessor (largest in the left subtree)
Node* findInorderPredecessor(Node* root) {
    Node* current = root->left;
    while (current != NULL && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Recursive function to delete a node from the BST
Node* deleteFromBST(Node* root, int data) {
    if (root == NULL) {
        printf("Node with value %d not found.\n", data);
        return NULL;
    }

    // Traverse the tree to find the node to delete
    if (data < root->data) {
        root->left = deleteFromBST(root->left, data);
    } else if (data > root->data) {
        root->right = deleteFromBST(root->right, data);
    } else {
        // Node with no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Node with one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children - Choose either inorder successor or predecessor

        // Uncomment one of the following two blocks to use either successor or predecessor:

        // Using Inorder Successor
        Node* successor = findInorderSuccessor(root);
        root->data = successor->data;
        root->right = deleteFromBST(root->right, successor->data);

        // OR

        /*
        // Using Inorder Predecessor
        Node* predecessor = findInorderPredecessor(root);
        root->data = predecessor->data;
        root->left = deleteFromBST(root->left, predecessor->data);
        */
    }
    return root;
}

// Function for inorder traversal to display the BST
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int choice, data;

    printf("Binary Search Tree Operations:\n");
    do {
        printf("1. Insert\n2. Delete (Recursive)\n3. Display Inorder\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertIntoBST(root, data);
                break;

            case 2:
                printf("Enter data to delete (Recursive): ");
                scanf("%d", &data);
                root = deleteFromBST(root, data);
                break;

            case 3:
                printf("Inorder Traversal of BST: ");
                inorderTraversal(root);
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
