#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
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

// Recursive function to construct the binary tree from pre-order and post-order traversals
Node* buildTree(int pre[], int post[], int* preIndex, int postStart, int postEnd, int size) {
    // Base case: If start index exceeds end index or preIndex exceeds size, return NULL
    if (*preIndex >= size || postStart > postEnd) {
        return NULL;
    }

    // The first node in pre-order traversal is the root node
    Node* root = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If there is only one element, it is the root of this subtree
    if (postStart == postEnd || *preIndex >= size) {
        return root;
    }

    // Search for the next element in pre-order in the post-order array
    int postIndex;
    for (postIndex = postStart; postIndex <= postEnd; postIndex++) {
        if (post[postIndex] == pre[*preIndex]) {
            break;
        }
    }

    // Using index in post-order, construct left and right subtrees recursively
    if (postIndex <= postEnd) {
        root->left = buildTree(pre, post, preIndex, postStart, postIndex, size);
        root->right = buildTree(pre, post, preIndex, postIndex + 1, postEnd - 1, size);
    }

    return root;
}

// Function to print the in-order traversal of the tree for verification
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int pre[n], post[n];
    printf("Enter the pre-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    printf("Enter the post-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    int preIndex = 0;
    Node* root = buildTree(pre, post, &preIndex, 0, n - 1, n);

    printf("In-order traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
