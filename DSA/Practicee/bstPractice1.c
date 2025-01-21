//Write program to find the depth, height, number of leaves, nodes in a BST
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* rchild;
    struct Node* lchild;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

Node* createBinaryTree()
{
    int data;
    printf("Enter value for node(-1 to exit):-");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    Node* root = createNode(data);
    printf("Enter lchild of %d:- ",root->data);
    root->lchild = createBinaryTree();
    printf("Enter rchild of %d:- ",root->data);
    root->rchild = createBinaryTree();
    return root;
}
Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    Node* newNode = createNode(data);
    if(data<root->data)
    {
        root->lchild = insert(root->lchild,data);
    }
    else if(data>root->data)
    {
        root->rchild = insert(root->rchild,data);
    }
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->lchild);
    printf("%d",root->data);
    inorder(root->rchild);
}

void levelOrder(Node* root)
{
    if(!root)
    {
        printf("\nEmpty tree");
        return;
    }
    int queue[500];
    int front=-1;
    int rear=-1;
    

}
