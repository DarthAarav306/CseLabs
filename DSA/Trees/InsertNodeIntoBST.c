#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* lchild;  // Left child
    struct Node* rchild;  // Right child
} Node;

// Function to create a new node
Node* createNewNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Function to insert a node into the BST (ignoring duplicates)
Node* insert(Node* root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return createNewNode(data);
    }

    // If data is smaller, insert into the left subtree
    if (data < root->data) {
        root->lchild = insert(root->lchild, data);
    }
    // If data is larger, insert into the right subtree
    else if (data > root->data) {
        root->rchild = insert(root->rchild, data);
    }
    // If data == root->data, ignore the insertion (no duplicates allowed)
    // No need to do anything in this case, we just return the root as-is.

    return root;
}
Node* insert(Node* root, int data) {
    if (!root) {
        return createNode(data); // Create and return a new root if the tree is empty
    }
    
    Node* temp = root;
    Node* prev = NULL;
    
    // Traverse to find the correct insertion point
    while (temp) {
        prev = temp;
        if (data > temp->data) {
            temp = temp->rchild;
        } else if (data < temp->data) {
            temp = temp->lchild;
        } else {
            return root; // If the value already exists, return without insertion
        }
    }
    
    // Create the new node
    Node* newNode = createNode(data);
    
    // Attach the new node to the correct parent pointer
    if (data < prev->data) {
        prev->lchild = newNode;
    } else {
        prev->rchild = newNode;
    }
    return root;
}

// Function to check whether the tree is empty
int isEmpty(Node* root) {
    return root == NULL;
}

// Inorder Traversal to display the tree (for verification)
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lchild);  // Visit left subtree
    printf("%d ", root->data);       // Visit root
    inorderTraversal(root->rchild);  // Visit right subtree
}

int main() {
    Node* root = NULL;  // Initially, the tree is empty

    // Check if the tree is empty
    if (isEmpty(root)) {
        printf("The tree is currently empty.\n");
    }

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 70);  // Duplicate value, should be ignored

    // Check again if the tree is empty
    if (!isEmpty(root)) {
        printf("The tree is no longer empty.\n");
    }

    // Perform inorder traversal to display the BST
    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
