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
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a new node into the BST
Node* insert(Node* root, int data) {
    // Base case: If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Recursive cases: Insert data in the left or right subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to perform inorder traversal (to verify BST properties)
void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);          // Traverse the left subtree
    printf("%d ", root->data);             // Visit the root node
    inorderTraversal(root->right);         // Traverse the right subtree
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
        root = insert(root, data);  // Insert data into the BST

        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Display the BST using inorder traversal
    printf("Inorder Traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
