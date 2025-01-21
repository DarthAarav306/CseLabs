#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* array[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX_SIZE) {
        q->array[q->rear++] = node;
    } else {
        printf("Queue overflow\n");
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->array[q->front++];
    }
    return NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Node** root, int data, int parentData, char* direction) {
    Node* newNode = createNode(data);

    if (*root == NULL) {
        *root = newNode;
        printf("Tree was empty. Node %d set as root.\n", data);
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, *root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        // Find the parent node for insertion
        if (current->data == parentData) {
            if (strcmp(direction, "left") == 0 && current->left == NULL) {
                current->left = newNode;
                printf("Node %d added as left child of %d.\n", data, parentData);
            } else if (strcmp(direction, "right") == 0 && current->right == NULL) {
                current->right = newNode;
                printf("Node %d added as right child of %d.\n", data, parentData);
            } else {
                printf("Child already exists at %s of node %d.\n", direction, parentData);
            }
            return;
        }
        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
    printf("Parent node %d not found.\n", parentData);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int data, parentData;
    char direction[10];

    printf("Binary Tree Creation:\n");
    printf("Enter root node data: ");
    scanf("%d", &data);
    root = createNode(data);
    printf("Root node %d created.\n", data);
    
    while (1) {
        printf("\nEnter new node data (-1 to stop): ");
        scanf("%d", &data);
        if (data == -1) break;

        printf("Enter parent node data for %d: ", data);
        scanf("%d", &parentData);
        
        printf("Enter direction (left/right) for %d: ", data);
        scanf("%s", direction);

        insertNode(&root, data, parentData, direction);
    }

    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
