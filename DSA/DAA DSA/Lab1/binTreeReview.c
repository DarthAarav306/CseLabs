#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node
{
    int data;
    struct Node *rchild;
    struct Node *lchild;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data == root->data)
    {
        printf("Duplicate Node: %d\n", data);
    }
    else if (data > root->data)
    {
        root->rchild = insertIntoBST(root->rchild, data);
    }
    else
    {
        root->lchild = insertIntoBST(root->lchild, data);
    }
    return root;
}

// Function to create a BST by accepting user input
Node *createBST()
{
    Node *root = NULL;
    int childData;
    printf("Enter node data (-1 to exit): ");
    while (1)
    {
        scanf("%d", &childData);
        if (childData == -1)
        {
            break;
        }
        root = insertIntoBST(root, childData);
    }
    return root;
}

// Function to search for a key or insert it into the BST if not found
Node *searchOrInsert(Node *root, int key)
{
    if (root == NULL)
    {
        printf("Key %d not found, inserting it into the tree.\n", key);
        return createNode(key);
    }
    if (key == root->data)
    {
        printf("Key %d found.\n", key);
    }
    else if (key > root->data)
    {
        root->rchild = searchOrInsert(root->rchild, key);
    }
    else
    {
        root->lchild = searchOrInsert(root->lchild, key);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->lchild);
        printf("%d ", root->data);
        inorderTraversal(root->rchild);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        printf("%d ", root->data);
    }
}

// Main function
int main()
{
    Node *root = NULL;
    int choice, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create binary tree\n");
        printf("2. Search or insert key\n");
        printf("3. Inorder traversal\n");
        printf("4. Preorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createBST();
            printf("Binary tree created.\n");
            break;
        case 2:
            printf("Enter key to search or insert: ");
            scanf("%d", &key);
            root = searchOrInsert(root, key);
            break;
        case 3:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
