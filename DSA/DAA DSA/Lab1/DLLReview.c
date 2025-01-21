#include <stdio.h>
#include <stdlib.h>

// Define a node in the doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Add a node at the front
void addFront(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head != NULL)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert a node to the left of a given key
void insertLeft(Node **head, int key, int data)
{
    Node *current = *head;
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Key %d not found.\n", key);
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL)
    {
        current->prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }
    current->prev = newNode;
}

// Delete all occurrences of a key
void deleteKey(Node **head, int key)
{
    Node *current = *head;
    int found = 0;
    while (current != NULL)
    {
        if (current->data == key)
        {
            found = 1;
            Node *temp = current;
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            current = current->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
    if (!found)
    {
        printf("Key %d not found in the list.\n", key);
    }
}

// Search a node based on its key value
void searchNode(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Key %d found in the list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Key %d not found in the list.\n", key);
}

// Display the contents of the list
void displayList(Node *head)
{
    Node *current = head;
    if (current == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("List contents: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add node at front\n");
        printf("2. Insert node to the left of a key\n");
        printf("3. Delete all occurrences of a key\n");
        printf("4. Search for a node by key\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            addFront(&head, data);
            break;
        case 2:
            printf("Enter key to insert left of: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertLeft(&head, key, data);
            break;
        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteKey(&head, key);
            break;
        case 4:
            printf("Enter key to search: ");
            scanf("%d", &key);
            searchNode(head, key);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
