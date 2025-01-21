#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* array[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Node* array[MAX_SIZE];
    int front, rear;
} Queue;

// Stack Functions
void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, Node* node) {
    if (s->top < MAX_SIZE - 1) {
        s->array[++(s->top)] = node;
    } else {
        printf("Stack overflow\n");
    }
}

Node* pop(Stack* s) {
    return isStackEmpty(s) ? NULL : s->array[(s->top)--];
}

Node* peek(Stack* s) {
    return isStackEmpty(s) ? NULL : s->array[s->top];
}

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isQueueEmpty(Queue* q) {
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
    return isQueueEmpty(q) ? NULL : q->array[q->front++];
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    Node* newNode = createNode(data);
    printf("Enter left child of %d\n", data);
    newNode->left = createTree();
    printf("Enter right child of %d\n", data);
    newNode->right = createTree();

    return newNode;
}
// Iterative pre-order traversal using the stack structure
void iterativePreorderTraversal(Node* root) {
    if (root == NULL) return;

    Stack s;
    initStack(&s);
    push(&s, root);

    printf("Preorder Traversal: ");
    while (!isStackEmpty(&s)) {
        Node* current = pop(&s);
        printf("%d ", current->data);

        if (current->right) push(&s, current->right);
        if (current->left) push(&s, current->left);
    }
    printf("\n");
}

// Iterative in-order traversal using the stack structure
void iterativeInorderTraversal(Node* root) {
    if (root == NULL) return;

    Stack s;
    initStack(&s);
    Node* current = root;

    printf("Inorder Traversal: ");
    while (current != NULL || !isStackEmpty(&s)) {
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

// Iterative post-order traversal using a single stack with a lastVisited flag
void iterativePostorderTraversal(Node* root) {
    if (root == NULL) return;

    Stack s;
    initStack(&s);

    // Pointers to help keep track of the current node and the last visited node
    Node* lastVisited = NULL;
    Node* current = root;

    printf("Postorder Traversal: ");

    // Loop continues until we’ve processed all nodes
    while (current != NULL || !isStackEmpty(&s)) {
        // Reach the leftmost node of the current subtree
        while (current != NULL) {
            // Push the current node to stack to process it after its children
            push(&s, current);
            // Move to the left child
            current = current->left;
        }

        // Peek the node at the top of the stack without removing it
        Node* topNode = peek(&s);

        // Check if the right child exists and if it was not visited last
        if (topNode->right != NULL && lastVisited != topNode->right) {
            // Move to the right child of the top node
            current = topNode->right;
        } else {
            // If there is no right child or it has been visited,
            // visit the top node in the stack (post-order visit)
            printf("%d ", topNode->data);

            // Mark this node as last visited and pop it from the stack
            lastVisited = pop(&s);
        }
    }
    printf("\n");
}
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    printf("Level-order Traversal: ");
    while (!isQueueEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
    printf("\n");
}

int main() {
    printf("Creating the binary tree.\n");
    Node* root = createTree();
    iterativePreorderTraversal(root);
    iterativeInorderTraversal(root);
    iterativePostorderTraversal(root);
    levelOrderTraversal(root);

    return 0;
}
