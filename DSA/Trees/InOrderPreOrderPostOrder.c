#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* rchild;
    struct Node* lchild;
} Node;

typedef struct {
    Node* stack[100];
    int top;
} Stack;

// Stack initialization
void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, Node* ele) {
    s->stack[++s->top] = ele;
}

Node* pop(Stack* s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->stack[s->top--];
}

// Create a new tree node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

Node* createTree(int data) {
    if (data == -1) {
        return NULL;  // Base case: no node
    }

    // Create the root node
    Node* newNode = createNode(data);

    // Prompt the user to input left and right children
    int leftData, rightData;
    printf("Enter left child of %d (-1 for no node): ", data);
    scanf("%d", &leftData);
    newNode->lchild = createTree(leftData);  // Recursive call for the left subtree

    printf("Enter right child of %d (-1 for no node): ", data);
    scanf("%d", &rightData);
    newNode->rchild = createTree(rightData);  // Recursive call for the right subtree

    return newNode;
}

// Build an expression tree from a postfix expression
Node* buildExpressionTreeFromPostfix(char* expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(expr); i++) {
        if (isdigit(expr[i])) {
            // Create a new node for operand and push onto stack
            Node* operandNode = createNode(expr[i]);
            push(&s, operandNode);
        } else {
            // Pop two nodes for the operator
            Node* opn1 = pop(&s);
            Node* opn2 = pop(&s);
            Node* opr = createNode(expr[i]);

            // Set popped nodes as children of the operator
            opr->rchild = opn1;
            opr->lchild = opn2;

            // Push the new subtree onto the stack
            push(&s, opr);
        }
    }
    return pop(&s); // The final tree root
}

// Build an expression tree from a prefix expression
Node* buildExpressionTreeFromPrefix(char* expr) {
    Stack s;
    initStack(&s);

    // Traverse from right to left for prefix
    for (int i = strlen(expr) - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            // Create a new node for operand and push onto stack
            Node* operandNode = createNode(expr[i]);
            push(&s, operandNode);
        } else {
            // Pop two nodes for the operator
            Node* opn1 = pop(&s);
            Node* opn2 = pop(&s);
            Node* opr = createNode(expr[i]);

            // Set popped nodes as children of the operator
            opr->lchild = opn1;
            opr->rchild = opn2;

            // Push the new subtree onto the stack
            push(&s, opr);
        }
    }
    return pop(&s); // The final tree root
}

// Evaluate the expression tree recursively
int eval(Node* root) {
    if (!root) {
        return -1;
    }
    // If the node is a leaf node (operand), return its value as an integer
    if (!root->rchild && !root->lchild) {
        return root->data - '0';
    }
    // Evaluate left and right children and apply the operator
    switch (root->data) {
        case '+': return eval(root->lchild) + eval(root->rchild);
        case '-': return eval(root->lchild) - eval(root->rchild);
        case '*': return eval(root->lchild) * eval(root->rchild);
        case '/': return eval(root->lchild) / eval(root->rchild);
        case '^': return eval(root->lchild) ^ eval(root->rchild);
        default: return 0;  // Return 0 for unknown operators
    }
}
// 1. Construct from Inorder and Preorder
Node* constructFromInorderAndPreorder(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }
    Node* root = createNode(preorder[*preorderIndex]);
    (*preorderIndex)++;
    
    if (inorderStart == inorderEnd) {
        return root;
    }
    
    int i;
    for (i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == root->data) {
            break;
        }
    }
    
    root->lchild = constructFromInorderAndPreorder(inorder, preorder, inorderStart, i - 1, preorderIndex);
    root->rchild = constructFromInorderAndPreorder(inorder, preorder, i + 1, inorderEnd, preorderIndex);
    
    return root;
}

// 2. Construct from Inorder and Postorder
Node* constructFromInorderAndPostorder(int inorder[], int postorder[], int inorderStart, int inorderEnd, int* postOrderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }
    
    Node* root = createNode(postorder[*postOrderIndex]);
    (*postOrderIndex)--;

    if (inorderStart == inorderEnd) {
        return root;
    }
    
    int i;
    for (i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == root->data) {
            break;
        }
    }
    
    root->rchild = constructFromInorderAndPostorder(inorder, postorder, i + 1, inorderEnd, postOrderIndex);
    root->lchild = constructFromInorderAndPostorder(inorder, postorder, inorderStart, i - 1, postOrderIndex);
    
    return root;
}

// 3. Construct from Preorder and Postorder
Node* constructFromPreorderAndPostorder(int preorder[], int postorder[], int postorderStart, int postOrderEnd, int* preorderIndex, int size) {
    if (*preorderIndex >= size || postorderStart > postOrderEnd) {
        return NULL;
    }
    
    Node* root = createNode(preorder[*preorderIndex]);
    (*preorderIndex)++;
    
    if (*preorderIndex >= size || postorderStart == postOrderEnd) {
        return root;
    }
    
    int i;
    for (i = postorderStart; i <= postOrderEnd; i++) {
        if (postorder[i] == preorder[*preorderIndex]) {
            break;
        }
    }
    
    root->lchild = constructFromPreorderAndPostorder(preorder, postorder, postorderStart, i, preorderIndex, size);
    root->rchild = constructFromPreorderAndPostorder(preorder, postorder, i + 1, postOrderEnd - 1, preorderIndex, size);
    
    return root;
}
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->lchild);  // Visit left subtree
    printf("%d ", root->data);       // Visit node
    inorderTraversal(root->rchild);  // Visit right subtree
}
int main() {
   int preorder[] = {10,5,3,7,8,15,13,12,17};
   int postorder[] ={3,8,7,5,12,13,17,15,10};
   int inorder[] = {3,5,7,8,10,12,13,15,17};
   int preorderindex = 0;
   int postorderindex = 8;
   Node* root1 = constructFromInorderAndPreorder(inorder,preorder,0,8,&preorderindex);
   Node* root2 = constructFromInorderAndPostorder(inorder,postorder,0,8,&postorderindex);
   Node* root3 = constructFromPreorderAndPostorder(preorder,postorder,0,8,&preorderindex,9);
   inorderTraversal(root1);
   printf("\n");
   inorderTraversal(root2);
   printf("\n");
   inorderTraversal(root3);
   printf("\n");

    return 0;
}
