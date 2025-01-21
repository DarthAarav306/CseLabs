#include <stdio.h>
#include <stdlib.h>

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

// Function to find the index of a value in the inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; // Should not happen if input is valid
}

// Recursive function to construct the binary tree
Node* buildTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Select current node from preorder traversal using preorderIndex and increment it
    Node* root = createNode(preorder[*preorderIndex]);
    (*preorderIndex)++;

    // If this node has no children, return the node
    if (inorderStart == inorderEnd) {
        return root;
    }

    // Otherwise, find the position of this node in inorder traversal
    int inorderIndex = search(inorder, inorderStart, inorderEnd, root->data);

    // Using the inorder index, construct left and right subtrees
    root->left = buildTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}

// Function to print inorder traversal of the tree to verify the tree structure
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Function to print preorder traversal of the tree to verify the tree structure
void printPreorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];
    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    int preorderIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, &preorderIndex);

    printf("Constructed Inorder traversal: ");
    printInorder(root);
    printf("\n");

    printf("Constructed Preorder traversal: ");
    printPreorder(root);
    printf("\n");

    return 0;
}
