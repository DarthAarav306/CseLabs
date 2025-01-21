#include <stdio.h>
#include <stdlib.h>

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

// Function to check if two binary trees are equal
int areTreesEqual(Node* root1, Node* root2) {
    // Both trees are empty
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    // One tree is empty and the other is not
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    // Check if the data of both nodes is equal
    // and both left and right subtrees are equal
    return (root1->data == root2->data) &&
           areTreesEqual(root1->lchild, root2->lchild) &&
           areTreesEqual(root1->rchild, root2->rchild);
}

// Main function to create two trees and test for equality
int main() {
    int data1, data2;

    // Create the first binary tree
    printf("Enter root data for the first tree (-1 for no root): ");
    scanf("%d", &data1);
    Node* root1 = createBinaryTree(data1);

    // Create the second binary tree
    printf("Enter root data for the second tree (-1 for no root): ");
    scanf("%d", &data2);
    Node* root2 = createBinaryTree(data2);

    // Test if the trees are equal
    if (areTreesEqual(root1, root2)) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }

    return 0;
}
