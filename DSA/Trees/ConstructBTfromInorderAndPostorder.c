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
    return -1;
}

// Recursive function to construct the binary tree from inorder and postorder
Node* buildTree(int inorder[], int postorder[], int inorderStart, int inorderEnd, int* postorderIndex) {
    // Base case: if start index exceeds end index
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // Get the current node from postorder using postorderIndex and decrement postorderIndex
    Node* root = createNode(postorder[*postorderIndex]);
    (*postorderIndex)--;

    // If this node has no children, return it
    if (inorderStart == inorderEnd) {
        return root;
    }

    // Find the position of this node in inorder array
    int inorderIndex = search(inorder, inorderStart, inorderEnd, root->data);

    // Build right and left subtrees
    root->right = buildTree(inorder, postorder, inorderIndex + 1, inorderEnd, postorderIndex);
    root->left = buildTree(inorder, postorder, inorderStart, inorderIndex - 1, postorderIndex);

    return root;
}

// Function to print inorder traversal of the tree
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Function to print postorder traversal of the tree
void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];
    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postorderIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, &postorderIndex);

    printf("Constructed Inorder traversal: ");
    printInorder(root);
    printf("\n");

    printf("Constructed Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
