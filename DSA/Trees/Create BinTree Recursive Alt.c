#include <stdio.h>
#include <stdlib.h>

// Define the structure of the binary tree node
typedef struct Node {
    int data;
    struct Node* rchild;
    struct Node* lchild;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

// Recursive function to create the binary tree
Node* createBinaryTree() {
    int data;
    printf("Enter value for node (-1 to stop): ");
    scanf("%d", &data);

    // Base case: return NULL if input is -1
    if (data == -1) {
        return NULL;
    }

    // Create the root node
    Node* head = createNode(data);

    printf("Enter left child of %d (-1 to stop): ", data);
    head->lchild = createBinaryTree();

    printf("Enter right child of %d (-1 to stop): ", data);
    head->rchild = createBinaryTree();

    return head;
}

// Inorder traversal to verify the tree structure
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
}

int main() {
    Node* root = createBinaryTree();
    
    printf("Inorder Traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
