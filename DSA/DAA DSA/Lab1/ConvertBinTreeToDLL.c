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

// Function to create a new binary tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal and convert the tree to DLL
void convertToDLL(TreeNode *root, DLLNode **head, DLLNode **prev)
{
    if (root == NULL)
    {
        return;
    }

    // Recur for the left subtree
    convertToDLL(root->left, head, prev);

    // Create a new DLL node from the current tree node
    DLLNode *current = (DLLNode *)malloc(sizeof(DLLNode));
    current->data = root->data;
    current->prev = *prev;
    current->next = NULL;

    // If this is the first node, set it as the head of the DLL
    if (*prev == NULL)
    {
        *head = current;
    }
    else
    {
        // Link the previous node to the current node
        (*prev)->next = current;
    }

    // Update the previous pointer to the current node
    *prev = current;

    // Recur for the right subtree
    convertToDLL(root->right, head, prev);
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
    DLLNode *head = NULL; // Head of the DLL
    DLLNode *prev = NULL; // Previous pointer for DLL
    convertToDLL(root, &head, &prev);

    // Print the doubly linked list
    printDLL(head);

    return 0;
}
