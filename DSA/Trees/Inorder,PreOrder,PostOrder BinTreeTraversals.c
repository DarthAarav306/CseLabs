#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
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

// Function to create the binary tree by taking user input
Node* createBinaryTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    // -1 indicates no node should be created
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the entered data
    Node* newNode = createNewNode(data);

    // Recursively create the left and right subtrees
    printf("Enter left child of %d\n", data);
    newNode->lchild = createBinaryTree();

    printf("Enter right child of %d\n", data);
    newNode->rchild = createBinaryTree();

    return newNode;
}

// Inorder Traversal: Left, Root, Right
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    
    inorderTraversal(root->lchild);  // Visit left subtree
    printf("%d ", root->data);       // Visit root
    inorderTraversal(root->rchild);  // Visit right subtree
}

// Preorder Traversal: Root, Left, Right
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);       // Visit root
    preorderTraversal(root->lchild); // Visit left subtree
    preorderTraversal(root->rchild); // Visit right subtree
}

// Postorder Traversal: Left, Right, Root
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    
    postorderTraversal(root->lchild);  // Visit left subtree
    postorderTraversal(root->rchild);  // Visit right subtree
    printf("%d ", root->data);         // Visit root
}

int main() {
    printf("Create the binary tree:\n");
    Node* root = createBinaryTree(); // Build the binary tree using user input

    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
