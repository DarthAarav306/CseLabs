#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum stack size

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Function to create a new node in the binary tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Function to create the binary tree using user input
Node* createBinaryTree(int data) {
    if (data == -1) {
        return NULL;
    }
    
    Node* newNode = createNode(data);
    int ldata, rdata;

    // Input and create left child
    printf("Enter data for left child of %d (-1 to stop): ", data);
    scanf("%d", &ldata);
    newNode->lchild = createBinaryTree(ldata);

    // Input and create right child
    printf("Enter data for right child of %d (-1 to stop): ", data);
    scanf("%d", &rdata);
    newNode->rchild = createBinaryTree(rdata);

    return newNode;
}

// Iterative postorder traversal using one stack implemented directly in the function
void iterativePostorderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Node* stack[MAX];
    int top = -1;
    Node* current = root;
    Node* lastVisited = NULL;

    printf("Postorder Traversal: ");
    while (current != NULL || top != -1) {
        // Reach the leftmost node of the current subtree
        while (current != NULL) {
            stack[++top] = current;
            current = current->lchild;
        }

        // Peek the node on top of the stack
        Node* topNode = stack[top];

        // If the right child exists and hasn't been visited yet, go to the right child
        if (topNode->rchild != NULL && lastVisited != topNode->rchild) {
            current = topNode->rchild;
        } else {
            // Visit the node
            printf("%d ", topNode->data);
            lastVisited = stack[top--];  // Update last visited after popping
        }
    }
    printf("\n");
}

// Main function to take input and perform postorder traversal
int main() {
    Node* root;
    int data;

    // Take input to create the binary tree
    printf("Enter data for root (-1 for no root): ");
    scanf("%d", &data);

    root = createBinaryTree(data);  // Initialize root with the tree created

    // Perform iterative postorder traversal
    iterativePostorderTraversal(root);

    return 0;
}
