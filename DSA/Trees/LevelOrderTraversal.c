#include <stdio.h>
#include <stdlib.h>
void levelOrder(Node* root) {
    if (!root) {
        return; // If the tree is empty, return
    }

    Node* queue[MAX]; // Array to implement the queue
    int front = -1;   // Points to the front of the queue
    int rear = -1;    // Points to the rear of the queue

    // Enqueue the root node (increment both front and rear for the first insertion)
    rear++;
    front++;
    queue[rear] = root;

    printf("Level Order Traversal: ");
    while (front <= rear) { // While the queue is not empty
        // Dequeue the front node
        Node* current = queue[front];
        front++;

        // Visit the current node
        printf("%d ", current->data);

        // Enqueue the left child if it exists
        if (current->lchild) {
            rear++;
            queue[rear] = current->lchild;
        }

        // Enqueue the right child if it exists
        if (current->rchild) {
            rear++;
            queue[rear] = current->rchild;
        }
    }
    printf("\n");
}

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
        printf("Queue underflow\n");
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

// Level order traversal using a queue
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("Level Order Traversal: ");
    while (!isEmpty(&q)) {
        Node* node = dequeue(&q);  // Dequeue the front node
        printf("%d ", node->data);  // Visit the node

        // Enqueue left and right children
        if (node->lchild != NULL) {
            enqueue(&q, node->lchild);
        }
        if (node->rchild != NULL) {
            enqueue(&q, node->rchild);
        }
    }
    printf("\n");
}

// Main function to create a tree with user input and perform level order traversal
int main() {
    int data;

    // Take input for the root node
    printf("Enter data for root (-1 for no root): ");
    scanf("%d", &data);

    Node* root = createBinaryTree(data);  // Initialize root with the tree created

    // Perform level order traversal
    levelOrderTraversal(root);

    return 0;
}
