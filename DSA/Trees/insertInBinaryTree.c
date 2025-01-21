#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum queue size

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Define the structure of the queue
typedef struct {
    Node* array[MAX];
    int front;
    int rear;
} Queue;

// Queue initialization
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear < q->front;
}

// Enqueue a node
void enqueue(Queue* q, Node* node) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    q->array[++(q->rear)] = node;
}

// Dequeue a node
Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    return q->array[(q->front)++];
}

// Function to create a new node in the binary tree
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// Insert at the first available position (level order insertion)
void insertAtFirstAvailable(Node* root, int data) {
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* temp = dequeue(&q);

        // Insert as left child if empty
        if (temp->lchild == NULL) {
            temp->lchild = createNode(data);
            return;
        } else {
            enqueue(&q, temp->lchild);
        }

        // Insert as right child if empty
        if (temp->rchild == NULL) {
            temp->rchild = createNode(data);
            return;
        } else {
            enqueue(&q, temp->rchild);
        }
    }
}

// Insert based on a user-specified path (insertion string)
// For example, "L" to insert as left child of root, "RL" to insert as left child of the right child of root
void insertAtPath(Node* root, char* path, int data) {
    Node* current = root;

    for (int i = 0; i < strlen(path) - 1; i++) {
        if (path[i] == 'L') {
            if (current->lchild == NULL) {
                printf("Invalid path: Node not found.\n");
                return;
            }
            current = current->lchild;
        } else if (path[i] == 'R') {
            if (current->rchild == NULL) {
                printf("Invalid path: Node not found.\n");
                return;
            }
            current = current->rchild;
        }
    }

    // Insert at the specified position
    if (path[strlen(path) - 1] == 'L') {
        if (current->lchild == NULL) {
            current->lchild = createNode(data);
        } else {
            printf("Left child already exists at the specified path.\n");
        }
    } else if (path[strlen(path) - 1] == 'R') {
        if (current->rchild == NULL) {
            current->rchild = createNode(data);
        } else {
            printf("Right child already exists at the specified path.\n");
        }
    }
}

// Insert as the left child of a specified node if the node exists
void insertAsLeftChild(Node* root, int target, int data) {
    if (root == NULL) return;

    if (root->data == target) {
        if (root->lchild == NULL) {
            root->lchild = createNode(data);
        } else {
            printf("Left child already exists for node %d.\n", target);
        }
        return;
    }

    insertAsLeftChild(root->lchild, target, data);
    insertAsLeftChild(root->rchild, target, data);
}

// Insert as the right child of a specified node if the node exists
void insertAsRightChild(Node* root, int target, int data) {
    if (root == NULL) return;

    if (root->data == target) {
        if (root->rchild == NULL) {
            root->rchild = createNode(data);
        } else {
            printf("Right child already exists for node %d.\n", target);
        }
        return;
    }

    insertAsRightChild(root->lchild, target, data);
    insertAsRightChild(root->rchild, target, data);
}

// Level order traversal for verification
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("Level Order Traversal: ");
    while (!isEmpty(&q)) {
        Node* node = dequeue(&q);
        printf("%d ", node->data);

        if (node->lchild != NULL) {
            enqueue(&q, node->lchild);
        }
        if (node->rchild != NULL) {
            enqueue(&q, node->rchild);
        }
    }
    printf("\n");
}

// Main function to create a binary tree and test insertion functions
int main() {
    int rootData;
    printf("Enter root node data: ");
    scanf("%d", &rootData);

    Node* root = createNode(rootData);

    // Insert at first available position
    insertAtFirstAvailable(root, 2);
    insertAtFirstAvailable(root, 3);

    // Insert at a specific path
    char path[10];
    printf("Enter path for insertion (e.g., 'L' or 'RL'): ");
    scanf("%s", path);
    int data;
    printf("Enter data to insert at path %s: ", path);
    scanf("%d", &data);
    insertAtPath(root, path, data);

    // Insert as left or right child of a specified node
    insertAsLeftChild(root, 2, 4);  // Insert 4 as left child of node with data 2
    insertAsRightChild(root, 2, 5); // Insert 5 as right child of node with data 2

    // Perform level order traversal to verify the structure
    levelOrderTraversal(root);

    return 0;
}
