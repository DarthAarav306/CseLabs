#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

Node* createBinaryTreeIterative() {
    int data;
    printf("Enter value for root node (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;  // No tree if the root is -1
    }

    // Create the root node
    Node* root = createNode(data);

    // Use a queue to manage nodes for level-order insertion
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];  // Dequeue

        // Input for the left child
        int leftData;
        printf("Enter left child of %d (-1 for no node): ", current->data);
        scanf("%d", &leftData);
        if (leftData != -1) {
            current->lchild = createNode(leftData);
            queue[rear++] = current->lchild;  // Enqueue
        }

        // Input for the right child
        int rightData;
        printf("Enter right child of %d (-1 for no node): ", current->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            current->rchild = createNode(rightData);
            queue[rear++] = current->rchild;  // Enqueue
        }
    }

    return root;
}

// In-order traversal for testing the tree structure
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
}

int main() {
    Node* root = createBinaryTreeIterative();
    
    printf("In-order Traversal of the Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
