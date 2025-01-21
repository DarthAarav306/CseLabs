#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

Node* createTreeRecursive() {
    int data;
    printf("Enter value of node(-1 to exit): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    Node* root = createNode(data);
    printf("For left child of %d ", data);
    root->lchild = createTreeRecursive();
    printf("For right child of %d ", data);
    root->rchild = createTreeRecursive();
    return root;
}
Node* createBinTreeRecursiveAlt(int data) {
    if (data == -1) {
        return NULL;
    }
    Node* root = createNode(data);
    int ldata, rdata;
    printf("Enter left child of %d(-1 to exit): ", root->data);
    scanf("%d", &ldata);
    root->lchild = createBinTreeRecursiveAlt(ldata);

    printf("Enter right child of %d(-1 to exit): ", root->data);
    scanf("%d", &rdata);
    root->rchild = createBinTreeRecursiveAlt(rdata);

    return root;
}
Node* createBinTreeIterative(int data)
{
    if(data==-1)
    {
        return NULL;
    } 
    Node* root = createNode(data);
    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear] = root;
    rear++;
    while(front<rear)
    {
        Node* current = queue[front];
        front++;
        printf("Enter lchild of %d(-1 to stop):- ",current->data);
        int ldata;
        scanf("%d",&ldata);
        if(ldata!=-1)
        {
            current->lchild = createNode(ldata);
            queue[rear] = current->lchild;
            rear++;
        }
        printf("Enter rchild of %d(-1 to stop):- ",current->data);
        int rdata;
        scanf("%d",&rdata);
        if(rdata!=-1)
        {
            current->rchild = createNode(rdata);
            queue[rear] = current->rchild;
            rear++;
        }
    }
    return root;
}
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->lchild);
    printf("%d ", root->data);
    inorderTraversal(root->rchild);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, rootData;
    printf("Enter value of root:- ");
    scanf("%d",&rootData);
    root = createBinTreeIterative(rootData);
    inorderTraversal(root);
    return 0;
}
