#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* treeNode;
    int visited;  // 0 if first visit, 1 if processed
} StackNode;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative post-order traversal using one stack and visited flag
void postOrderIterative(Node* root) {
    if (root == NULL) return;

    StackNode stack[100];
    int top = -1;

    // Push the root node onto the stack with visited set to 0 (unprocessed)
    stack[++top] = (StackNode){root, 0};

    while (top != -1) {
        StackNode current = stack[top--];  // Pop the top item

        if (current.visited == 1) {
            printf("%d ", current.treeNode->data);  // Print node data on second visit
        } else {
            // Push the node again with visited set to 1 for processing
            stack[++top] = (StackNode){current.treeNode, 1};

            // Push the right and left children (right first so that left is processed next)
            if (current.treeNode->right) {
                stack[++top] = (StackNode){current.treeNode->right, 0};
            }
            if (current.treeNode->left) {
                stack[++top] = (StackNode){current.treeNode->left, 0};
            }
        }
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Post-order Traversal: ");
    postOrderIterative(root);
    printf("\n");

    return 0;
}

