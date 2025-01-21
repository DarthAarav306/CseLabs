#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* rchild;
    struct Node* lchild;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

Node* createBinaryTree(int data) {
    if (data == -1) {
        return NULL;
    }
    Node* root = createNode(data);
    int ldata, rdata;
    printf("Enter lchild of %d: ", root->data);
    scanf("%d", &ldata);
    root->lchild = createBinaryTree(ldata);
    printf("Enter rchild of %d: ", root->data);
    scanf("%d", &rdata);
    root->rchild = createBinaryTree(rdata);
    return root;
}

typedef struct {
    Node* stack[100];  // Change int to Node* for storing pointers to nodes
    int top;
} Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, Node* ele) {
    s->top++;
    s->stack[s->top] = ele;
}

Node* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    Node* ele = s->stack[s->top];
    s->top--;
    return ele;
}

void iterativeInorder(Node* root) {
    if (!root) {
        return;
    }
    Stack s;
    init(&s);
    Node* current = root;
    while (!isEmpty(&s) || current) {
        while (current) {
            push(&s, current);
            current = current->lchild;
        }
        current = pop(&s);
        printf("%d ", current->data);
        current = current->rchild;
    }
}

void iterativePreOrder(Node* root) {
    if (!root) {
        return;
    }
    Stack s;
    init(&s);
    push(&s, root);
    while (!isEmpty(&s)) {
        Node* current = pop(&s);
        printf("%d ", current->data);
        if (current->rchild) {
            push(&s, current->rchild);
        }
        if (current->lchild) {
            push(&s, current->lchild);
        }
    }
}

void iterativePostOrder(Node* root) {
    if (!root) {
        return;
    }

    Node* current = root;
    Node* lastVisited = NULL;
    Stack s;
    init(&s);

    while (current || !isEmpty(&s)) {
        // Traverse to the leftmost node
        while (current) {
            push(&s, current);
            current = current->lchild;
        }

        // Peek at the top node in the stack
        Node* topNode = s.stack[s.top];

        // If the right child exists and hasn't been visited, go to the right child
        if (topNode->rchild && lastVisited != topNode->rchild) {
            current = topNode->rchild;
        } else {
            // Process the node if it has no right child or the right child has already been visited
            printf("%d ", topNode->data);  // Print the node's data
            lastVisited = pop(&s);         // Pop from the stack and mark as last visited
        }
    }
    printf("\n");
}
typedef struct {
    Node* queue[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmptyQ(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* ele) {
    if (q->rear == 99) {  // Optional overflow check for fixed-size queue
        printf("Queue overflow\n");
        return;
    }
    q->queue[q->rear] = ele;
    q->rear++;
}

Node* dequeue(Queue* q) {
    if (isEmptyQ(q)) {
        return NULL;
    }
    Node* ele = q->queue[q->front];
    q->front++;
    if (q->front == q->rear) {  // Reset when the queue becomes empty
        q->front = 0;
        q->rear = 0;
    }
    return ele;
}

void levelOrder(Node* root) {
    if (!root) {
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmptyQ(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->lchild) {
            enqueue(&q, current->lchild);
        }
        if (current->rchild) {
            enqueue(&q, current->rchild);
        }
    }
    printf("\n");
}
int main() {
    Node* root = NULL;
    int rootData;
    return 0;
}



