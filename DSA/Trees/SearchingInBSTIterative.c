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

// Iterative function to search for a value in the BST
Node* search(Node* root, int key) {
    Node* current = root;
    
    // Traverse the tree until we find the key or reach a leaf node
    while (current != NULL) {
        if (key == current->data) {
            return current;  // Key found
        } else if (key < current->data) {
            current = current->left;  // Move to the left subtree
        } else {
            current = current->right; // Move to the right subtree
        }
    }
    
    return NULL;  // Key not found
}

int main() {
    Node* root = NULL;
    int data, key;
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

    // Search for a key in the BST
    printf("Enter value to search: ");
    scanf("%d", &key);

    Node* result = search(root, key);
    if (result != NULL) {
        printf("Value %d found in the BST.\n", key);
    } else {
        printf("Value %d not found in the BST.\n", key);
    }

    return 0;
}
