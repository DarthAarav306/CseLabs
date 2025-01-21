#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find k-smallest elements
void kSmallest(Node* root, int k, int* count) {
    if (root == NULL || *count >= k) return;

    // Visit left subtree (smaller elements first)
    kSmallest(root->left, k, count);

    // Process the current node
    if (*count < k) {
        printf("%d ", root->data);
        (*count)++;
    }

    // Visit right subtree (larger elements next)
    kSmallest(root->right, k, count);
}

// Function to find k-largest elements
void kLargest(Node* root, int k, int* count) {
    if (root == NULL || *count >= k) return;

    // Visit right subtree (larger elements first)
    kLargest(root->right, k, count);

    // Process the current node
    if (*count < k) {
        printf("%d ", root->data);
        (*count)++;
    }

    // Visit left subtree (smaller elements next)
    kLargest(root->left, k, count);
}

// Function to find the kth smallest element
void kthSmallest(Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;

    // Visit left subtree
    kthSmallest(root->left, k, count, result);

    // Process the current node
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    // Visit right subtree
    kthSmallest(root->right, k, count, result);
}

// Function to find the kth largest element
void kthLargest(Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;

    // Visit right subtree
    kthLargest(root->right, k, count, result);

    // Process the current node
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    // Visit left subtree
    kthLargest(root->left, k, count, result);
}

// Main Function
int main() {
    Node* root = NULL;

    // Insert elements into the BST
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 35);

    int k = 3;

    // Find k-smallest elements
    int count = 0;
    printf("The %d smallest elements are: ", k);
    kSmallest(root, k, &count);
    printf("\n");

    // Find k-largest elements
    count = 0;
    printf("The %d largest elements are: ", k);
    kLargest(root, k, &count);
    printf("\n");

    // Find kth smallest element
    count = 0;
    int result = -1;
    kthSmallest(root, k, &count, &result);
    printf("The %dth smallest element is: %d\n", k, result);

    // Find kth largest element
    count = 0;
    result = -1;
    kthLargest(root, k, &count, &result);
    printf("The %dth largest element is: %d\n", k, result);

    return 0;
}
void inorderToArray(Node* root, int arr[], int* index) {
    if (root == NULL) return;

    inorderToArray(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorderToArray(root->right, arr, index);
}

// Find k-smallest and k-largest using array
void findKElementsUsingArray(Node* root, int k) {
    int arr[100], index = 0;

    inorderToArray(root, arr, &index);

    if (k <= 0 || k > index) {
        printf("Invalid k.\n");
        return;
    }

    printf("%d smallest element: %d\n", k, arr[k-1]);
    printf("%d largest element: %d\n", k, arr[index-k]);
}
void findKElementsUsingArray(Node* root, int k) {
    int arr[100], index = 0;

    // Fill the array with elements in sorted order (inorder traversal)
    inorderToArray(root, arr, &index);

    // Validate k
    if (k <= 0 || k > index) {
        printf("Invalid value of k.\n");
        return;
    }

    // Print k smallest elements
    printf("The %d smallest elements are: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print k largest elements
    printf("The %d largest elements are: ", k);
    for (int i = index - k; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print kth smallest and kth largest
    printf("The %dth smallest element is: %d\n", k, arr[k-1]);
    printf("The %dth largest element is: %d\n", k, arr[index-k]);
}
