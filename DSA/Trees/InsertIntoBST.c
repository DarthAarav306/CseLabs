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
Node* insertIntoBST(Node* root, int data) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        return createNode(data);
    }

    // Recur down the tree based on data comparison
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);  // Insert into the left subtree
    } else if (data > root->data) {
        root->right = insertIntoBST(root->right, data);  // Insert into the right subtree
    }

    // Return the unchanged root pointer
    return root;
}

// Iterative function to insert a new node into the BST
Node* insertIntoBSTIterative(Node* root, int data) {
    // Create a new node to be inserted
    Node* newNode = createNode(data);

    // If the tree is empty, the new node becomes the root
    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    // Traverse the tree to find the insertion point
    while (current != NULL) {
        parent = current;
        // If data already exists, return without insertion
        if (data == current->data) {
            printf("Node with value %d already exists. No insertion performed.\n", data);
            free(newNode);
            return root;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Insert the new node as a child of the found parent
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}
// Iterative function to insert a new node into the BST
void insertIntoBSTIterative(Node** root, int data) {
    // Create a new node to be inserted
    Node* newNode = createNode(data);

    // If the tree is empty, the new node becomes the root
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    // Traverse the tree to find the insertion point
    while (current != NULL) {
        parent = current;
        if (data == current->data) {
            printf("Node with value %d already exists. No insertion performed.\n", data);
            free(newNode);
            return;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Insert the new node as a child of the found parent
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function for inorder traversal (to verify BST properties)
void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);      // Visit left subtree
    printf("%d ", root->data);         // Visit node
    inorderTraversal(root->right);     // Visit right subtree
}

int main() {
    Node* root = NULL;
    int data;
    char choice;

    printf("Binary Search Tree Creation and Insertion\n");

    // Create the BST with initial nodes using recursive insertion
    root = createNode(50);  // Manually creating the root for demonstration
    insertIntoBST(root, 30);
    insertIntoBST(root, 70);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    printf("Inorder Traversal of initial BST: ");
    inorderTraversal(root);
    printf("\n");

    // Insert a single node into the BST iteratively
    printf("Enter data to insert into BST iteratively: ");
    scanf("%d", &data);
    root = insertIntoBSTIterative(root, data);

    // Display the updated BST using inorder traversal
    printf("Inorder Traversal after iterative insertion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
