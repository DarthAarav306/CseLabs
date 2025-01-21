#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int type; // 0 for File, 1 for Directory
    int size;
    struct Node *leftChild;  // For subdirectory or files within a directory
    struct Node *rightSibling; // For siblings within the same directory
} Node;

// Function to create a new node (file or directory)
Node* createNode(char name[], int type, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->type = type;
    newNode->size = size;
    newNode->leftChild = newNode->rightSibling = NULL;
    return newNode;
}

// Function to find a directory by its path
Node* findDirectory(Node* root, char path[]) {
    if (strcmp(root->name, path) == 0)
        return root;
    Node* child = root->leftChild;
    while (child != NULL) {
        if (child->type == 1) {
            Node* result = findDirectory(child, path);
            if (result) return result;
        }
        child = child->rightSibling;
    }
    return NULL;
}

// Function to add a new entry (file or directory) in a given path
void addEntry(Node* root, char path[], char name[], int type, int size) {
    Node* dir = findDirectory(root, path);
    if (dir == NULL) {
        printf("Directory not found.\n");
        return;
    }
    Node* newNode = createNode(name, type, size);
    if (dir->leftChild == NULL) {
        dir->leftChild = newNode;
    } else {
        Node* sibling = dir->leftChild;
        while (sibling->rightSibling != NULL) {
            sibling = sibling->rightSibling;
        }
        sibling->rightSibling = newNode;
    }
    printf("%s created.\n", name);
}

// Function to delete an entry (file or directory) by name from a given directory
void deleteEntry(Node* parent, char name[]) {
    Node* current = parent->leftChild;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->rightSibling;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
        return;
    }

    if (previous == NULL) {
        parent->leftChild = current->rightSibling;
    } else {
        previous->rightSibling = current->rightSibling;
    }

    if (current->type == 1) { // Recursively delete all contents if it's a directory
        while (current->leftChild != NULL) {
            deleteEntry(current, current->leftChild->name);
        }
    }
    free(current);
    printf("%s deleted.\n", name);
}

// Function to list the contents of a directory
void listContents(Node* root) {
    Node* child = root->leftChild;
    while (child != NULL) {
        printf("%s (%s)\n", child->name, child->type == 0 ? "File" : "Directory");
        child = child->rightSibling;
    }
}

// Recursive function to find an entry by name and print its path
int findEntryByName(Node* root, char name[], char path[]) {
    strcat(path, "/");
    strcat(path, root->name);

    if (strcmp(root->name, name) == 0) {
        printf("Entry found at path: %s\n", path);
        return 1;
    }

    Node* child = root->leftChild;
    while (child != NULL) {
        if (findEntryByName(child, name, path)) {
            return 1;
        }
        child = child->rightSibling;
    }

    path[strlen(path) - strlen(root->name) - 1] = '\0'; 
    return 0;
}

// Function to calculate the total size of a directory
int calculateSize(Node* root) {
    int totalSize = 0;
    Node* child = root->leftChild;
    while (child != NULL) {
        if (child->type == 0) {
            totalSize += child->size;
        } else if (child->type == 1) {
            totalSize += calculateSize(child);
        }
        child = child->rightSibling;
    }
    return totalSize;
}

// Function to detach an entry from its current directory for moving
Node* detachEntry(Node* parent, char name[]) {
    Node* current = parent->leftChild;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->rightSibling;
    }

    if (current == NULL) {
        printf("Entry not found.\n");
        return NULL;
    }

    if (previous == NULL) {
        parent->leftChild = current->rightSibling;
    } else {
        previous->rightSibling = current->rightSibling;
    }

    current->rightSibling = NULL;
    return current;
}

// Function to move an entry from one location to another
void moveEntry(Node* root, char currentPath[], char entryName[], char targetPath[]) {
    Node* currentDir = findDirectory(root, currentPath);
    if (currentDir == NULL) {
        printf("Current directory not found.\n");
        return;
    }

    Node* targetDir = findDirectory(root, targetPath);
    if (targetDir == NULL) {
        printf("Target directory not found.\n");
        return;
    }

    Node* entry = detachEntry(currentDir, entryName);
    if (entry != NULL) {
        if (targetDir->leftChild == NULL) {
            targetDir->leftChild = entry;
        } else {
            Node* sibling = targetDir->leftChild;
            while (sibling->rightSibling != NULL) {
                sibling = sibling->rightSibling;
            }
            sibling->rightSibling = entry;
        }
        printf("%s moved to %s.\n", entryName, targetPath);
    }
}

int main() {
    Node* root = createNode("root", 1, 0);

    int choice;
    char path[200], name[50], targetPath[200];
    int size;
    while (1) {
        printf("\nMenu:\n1. Create File/Directory\n2. Delete File/Directory\n3. List Directory\n4. Find Entry\n5. Calculate Directory Size\n6. Move Entry\n7. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter path: ");
                scanf("%s", path);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter type (0 for File, 1 for Directory): ");
                int type;
                scanf("%d", &type);
                size = 0;
                if (type == 0) {
                    printf("Enter file size: ");
                    scanf("%d", &size);
                }
                addEntry(root, path, name, type, size);
                break;

            case 2:
                printf("Enter directory path: ");
                scanf("%s", path);
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteEntry(findDirectory(root, path), name);
                break;

            case 3:
                printf("Enter directory path: ");
                scanf("%s", path);
                Node* dir = findDirectory(root, path);
                if (dir) listContents(dir);
                else printf("Directory not found.\n");
                break;

            case 4:
                printf("Enter entry name to find: ");
                scanf("%s", name);
                path[0] = '\0'; // Reset path
                if (!findEntryByName(root, name, path))
                    printf("Entry not found.\n");
                break;

            case 5:
                printf("Enter directory path: ");
                scanf("%s", path);
                dir = findDirectory(root, path);
                if (dir) printf("Total size: %d\n", calculateSize(dir));
                else printf("Directory not found.\n");
                break;

            case 6:
                printf("Enter current directory path: ");
                scanf("%s", path);
                printf("Enter name of entry to move: ");
                scanf("%s", name);
                printf("Enter target directory path: ");
                scanf("%s", targetPath);
                moveEntry(root, path, name, targetPath);
                break;

            case 7:
                exit(0);
            
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}
