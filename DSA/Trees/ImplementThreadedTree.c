#include <stdio.h>
#include <stdlib.h>

// Define the structure of a threaded binary tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
    int leftThread, rightThread; // 1 if the pointer is a thread, 0 if it points to a child
} Node;

// Function to create a new threaded node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->leftThread = 1; // Initially, the left and right are threads
    newNode->rightThread = 1;
    return newNode;
}

// Function to create a normal binary tree
Node* createBinaryTree() {
    int data;
    printf("Enter node data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    Node* newNode = createNode(data);

    printf("Enter left child of %d\n", data);
    newNode->left = createBinaryTree();

    printf("Enter right child of %d\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to initialize the header node
Node* initializeHeader(Node* root) {
    Node* header = createNode(-1); // Special header node with dummy data (-1)
    header->left = root;
    header->right = header;
    header->leftThread = 0; // Left pointer points to root, so it's not a thread
    header->rightThread = 1; // Right pointer points back to itself
    return header;
}

// Recursive inorder traversal (for normal binary trees)
void inorderTraversalRecursive(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversalRecursive(root->left);
    printf("%d ", root->data);
    inorderTraversalRecursive(root->right);
}

Node* insucc(Node* node) {
    if (node->rightThread) {
        return node->right;
    } else {
        Node* temp = node->right;
        while (temp != NULL && !temp->leftThread) {
            temp = temp->left;
        }
        return temp;
    }
}
void inorder(Node* header)
{
    Node* temp = insucc(header);
    while(temp!=header)
    {
        printf("%d",temp->data);
        temp = insucc(temp);
    }
    printf("\n");
}
// Threaded inorder traversal using `insucc`
void tinorder(Node* header) {
    Node* temp = header;
    while (1) {
        temp = insucc(temp);
        if (temp == header) break;
        printf("%d ", temp->data);
    }
    printf("\n");
}

// Alternate threaded inorder traversal using the header node
void inorderTraversal(Node* header) {
    Node* current = header->left; // Start from the leftmost node of the root
    while (!current->leftThread) {
        current = current->left;
    }

    while (current != header) { // Continue until we loop back to the header
        printf("%d ", current->data);
        if (current->rightThread) {
            current = current->right;
        } else {
            current = current->right;
            while (current != NULL && !current->leftThread) {
                current = current->left;
            }
        }
    }
    printf("\n");
}


// Helper function to convert a normal binary tree to a threaded binary tree
void createThreadedTree(Node* root, Node** prev) {
    if (root == NULL) {
        return;
    }

    createThreadedTree(root->left, prev);

    if (root->left == NULL) {
        root->left = *prev;
        root->leftThread = 1;
    }
    if (*prev && (*prev)->right == NULL) {
        (*prev)->right = root;
        (*prev)->rightThread = 1;
    }

    *prev = root;

    createThreadedTree(root->right, prev);
}

// Function to build a complete threaded binary tree from a normal binary tree
Node* buildThreadedTree(Node* root) {
    Node* prev = NULL;
    createThreadedTree(root, &prev);

    Node* header = initializeHeader(root);

    Node* leftmostNode = leftmost(root);
    Node* rightmostNode = root;
    while (rightmostNode->right != NULL && !rightmostNode->rightThread) {
        rightmostNode = rightmostNode->right;
    }
    leftmostNode->left = header;
    rightmostNode->right = header;

    return header;
}

// Function to insert a new node in the threaded binary tree
void insertNode(Node** root, int data) {
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (!current->leftThread) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (!current->rightThread) {
                current = current->right;
            } else {
                break;
            }
        }
    }

    if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = 0;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = 0;
        parent->right = newNode;
    }
}

// Function to insert a node as a left or right child of a specific node
void insertAsChild(Node* parent, int data, char side) {
    Node* newNode = createNode(data);

    if (side == 'L' || side == 'l') {
        if (parent->leftThread) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = 0;
            parent->left = newNode;
        } else {
            Node* leftSubtree = parent->left;
            newNode->left = leftSubtree;
            newNode->right = parent;
            parent->left = newNode;
            parent->leftThread = 0;

            Node* temp = leftSubtree;
            while (!temp->rightThread) {
                temp = temp->right;
            }
            temp->right = newNode;
            temp->rightThread = 1;
        }
    } else if (side == 'R' || side == 'r') {
        if (parent->rightThread) {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = 0;
            parent->right = newNode;
        } else {
            Node* rightSubtree = parent->right;
            newNode->right = rightSubtree;
            newNode->left = parent;
            parent->right = newNode;
            parent->rightThread = 0;

            Node* temp = rightSubtree;
            while (!temp->leftThread) {
                temp = temp->left;
            }
            temp->left = newNode;
            temp->leftThread = 1;
        }
    }
}

int main() {
    Node* root = NULL;
    Node* header = NULL;
    int choice, data, parentData;
    char side;

    printf("Threaded Binary Tree Operations:\n");
    do {
        printf("1. Create Binary Tree\n2. Convert to Threaded Tree\n3. Insert Node\n4. Insert as Left or Right Child\n5. Inorder Traversal (Recursive)\n6. Inorder Traversal using Threads\n7. Inorder Traversal with Header\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating a normal binary tree:\n");
                root = createBinaryTree();
                break;

            case 2:
                printf("Converting Binary Tree to Threaded Binary Tree...\n");
                header = buildThreadedTree(root);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&root, data);
                break;

            case 4:
                printf("Enter parent node data: ");
                scanf("%d", &parentData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Insert as left (L) or right (R) child? ");
                scanf(" %c", &side);

                Node* current = root;
                while (current != NULL && current->data != parentData) {
                    if (parentData < current->data) {
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                }

                if (current == NULL) {
                    printf("Parent node with data %d not found.\n", parentData);
                } else {
                    insertAsChild(current, data, side);
                }
                break;

            case 5:
                printf("Inorder Traversal (Recursive): ");
                inorderTraversalRecursive(root);
                printf("\n");
                break;

            case 6:
                printf("Inorder Traversal using Threads: ");
                tinorder(header);
                printf("\n");
                break;

            case 7:
                printf("Inorder Traversal with Header Node: ");
                inorderTraversal(header);
                printf("\n");
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
