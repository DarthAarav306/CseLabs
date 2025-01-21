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

// Function to insert a node in the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the in-order successor of a given node
Node* findInOrderSuccessor(Node* root, Node* node) {
    Node* successor = NULL;

    // Case 1: Node has a right subtree
    if (node->right != NULL) {
        Node* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    // Case 2: Node does not have a right subtree
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}
Node* inorderSuccessor(Node* root, Node* node) {
    Node* temp;

    // Case 1: Node has a right child
    if (node->rchild) {
        temp = node->rchild;
        while (temp->lchild) {
            temp = temp->lchild;
        }
        return temp;
    }

    // Case 2: Node does not have a right child
    temp = root;
    Node* prev = NULL;  // `prev` will store the potential successor
    while (temp != NULL && temp->data != node->data) {
        if (node->data < temp->data) {
            prev = temp;  // Update `prev` only when moving left
            temp = temp->lchild;
        } else {
            temp = temp->rchild;
        }
    }

    return prev;  // `prev` is the in-order successor, if it exists
}

// Function for in-order traversal to display tree nodes
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 22);
    insertNode(root, 4);
    insertNode(root, 12);
    insertNode(root, 10);
    insertNode(root, 14);

    printf("In-order Traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    Node* node = root->left->right;  // Node with value 12
    Node* successor = findInOrderSuccessor(root, node);

    if (successor != NULL) {
        printf("The in-order successor of %d is %d\n", node->data, successor->data);
    } else {
        printf("The in-order successor does not exist.\n");
    }

    return 0;
}
