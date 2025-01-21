#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size of the binary tree array

// Array to store the binary tree using 1-based indexing
int tree[MAX_SIZE];
int currentSize = 1;  // Track the next available position in the tree

// Initialize the array with 0 to represent empty nodes
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = 0;
    }
}

// Function to insert a node at the next available position in level order
void insertNode(int data) {
    if (currentSize >= MAX_SIZE) {
        printf("Tree is full!\n");
        return;
    }
    tree[currentSize++] = data;  // Insert data at the current available position
}

// Function to get the left child of a node at a given index
int getLeftChild(int index) {
    int leftChildIndex = 2 * index;
    if (leftChildIndex < currentSize && tree[leftChildIndex] != 0) {
        return tree[leftChildIndex];
    } else {
        printf("No left child for node at index %d\n", index);
        return -1;
    }
}

// Function to get the right child of a node at a given index
int getRightChild(int index) {
    int rightChildIndex = 2 * index + 1;
    if (rightChildIndex < currentSize && tree[rightChildIndex] != 0) {
        return tree[rightChildIndex];
    } else {
        printf("No right child for node at index %d\n", index);
        return -1;
    }
}

// Function to get the parent of a node at a given index
int getParent(int index) {
    if (index <= 1) {
        printf("The root node has no parent.\n");
        return -1;
    }
    int parentIndex = index / 2;
    return tree[parentIndex];
}

// Simple function to display the tree in level order
void displayTree() {
    printf("Level-order Traversal:\n");
    for (int i = 1; i < currentSize; i++) {  // Start from index 1 for 1-based indexing
        if (tree[i] != 0) {  // Display only non-zero entries
            printf("%d ", tree[i]);
        }
    }
    printf("\n");
}

int main() {
    initializeTree();

    int data;
    char choice;

    printf("Binary Tree Implementation Using Array (1-based indexing)\n");

    // Insert nodes as provided by the user
    do {
        printf("Enter data to insert (-1 to stop): ");
        scanf("%d", &data);

        if (data == -1) break;  // Exit if user enters -1

        insertNode(data);  // Insert node at the next available position

        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Display the tree in level-order
    displayTree();

    // Example usage of the child and parent retrieval functions
    int index;
    printf("Enter the index to find its left child: ");
    scanf("%d", &index);
    printf("Left child of node at index %d: %d\n", index, getLeftChild(index));

    printf("Enter the index to find its right child: ");
    scanf("%d", &index);
    printf("Right child of node at index %d: %d\n", index, getRightChild(index));

    printf("Enter the index to find its parent: ");
    scanf("%d", &index);
    printf("Parent of node at index %d: %d\n", index, getParent(index));

    return 0;
}
