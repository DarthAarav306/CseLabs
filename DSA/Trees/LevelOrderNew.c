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

void levelOrder(Node* root) {
    if (!root) {
        printf("Empty tree\n");
        return;
    }

    Node* queue[500];
    int front = 0;
    int rear = 0;

    // Enqueue root
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue the front node
        Node* node = queue[front++];

        // Print the current node's data
        printf("%d ", node->data);

        // Enqueue the left child if it exists
        if (node->lchild) {
            queue[rear++] = node->lchild;
        }

        // Enqueue the right child if it exists
        if (node->rchild) {
            queue[rear++] = node->rchild;
        }
    }
    printf("\n");
}

int main() {
    // Create a sample tree
    Node* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->lchild = createNode(6);
    root->rchild->rchild = createNode(7);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}
