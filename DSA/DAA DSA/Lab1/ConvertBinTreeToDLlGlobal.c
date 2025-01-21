#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Define the structure for a doubly linked list node
typedef struct DLLNode
{
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

// Global pointers to track the head and previous node of the doubly linked list
DLLNode *head = NULL; // Head of the doubly linked list
DLLNode *prev = NULL; // Pointer to the previous node in the DLL

// Function to create a new binary tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new doubly linked list node
DLLNode *createDLLNode(int data)
{
    DLLNode *newNode = (DLLNode *)malloc(sizeof(DLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to convert the binary tree to doubly linked list (inorder traversal)
void convertToDLL(TreeNode *root)
{
    if (root == NULL)
    {
        return; // Base case: If the tree is empty, do nothing
    }

    // Recur for the left subtree
    convertToDLL(root->left);

    // Process the current tree node
    DLLNode *current = createDLLNode(root->data); // Create a new DLL node
    if (prev == NULL)
    {
        // If this is the first node, set it as the head of the DLL
        head = current;
    }
    else
    {
        // Link the previous node to the current node
        prev->next = current;
        current->prev = prev;
    }
    prev = current; // Update the previous pointer to the current node

    // Recur for the right subtree
    convertToDLL(root->right);
}

// Function to print the doubly linked list
void printDLL(DLLNode *head)
{
    printf("Doubly Linked List:\n");
    DLLNode *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    /*
        Example Binary Tree:
                   10
                  /  \
                 12   15
                / \   / \
               25 30 36 40
    */
    // Create the binary tree
    TreeNode *root = createTreeNode(10);
    root->left = createTreeNode(12);
    root->right = createTreeNode(15);
    root->left->left = createTreeNode(25);
    root->left->right = createTreeNode(30);
    root->right->left = createTreeNode(36);
    root->right->right = createTreeNode(40);

    // Convert the binary tree to a doubly linked list
    convertToDLL(root);

    // Print the doubly linked list
    printDLL(head);

    return 0;
}
