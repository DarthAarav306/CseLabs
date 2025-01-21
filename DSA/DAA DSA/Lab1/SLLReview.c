#include <stdio.h>
#include <stdlib.h>

// Define a structure for the singly linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a list by adding each node at the front
void createList(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node to the left of the node with a specific key
void insertLeft(Node **head, int key, int data)
{
    Node *newNode = createNode(data);

    // If the list is empty
    if (*head == NULL)
    {
        printf("List is empty, cannot insert left of key %d.\n", key);
        free(newNode);
        return;
    }

    // If the key is at the head
    if ((*head)->data == key)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the key
    Node *temp = *head;
    while (temp->next != NULL && temp->next->data != key)
    {
        temp = temp->next;
    }

    // If the key is found
    if (temp->next != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Key %d not found, cannot insert left.\n", key);
        free(newNode);
    }
}

// Function to delete all occurrences of a given key
void deleteAllOccurrences(Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete key %d.\n", key);
        return;
    }

    // Delete occurrences at the head
    while (*head != NULL && (*head)->data == key)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // Traverse the list and delete remaining occurrences
    Node *temp = *head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        }
        else
        {
            temp = temp->next;
        }
    }
}

// Function to search a node based on its key value
void searchNode(Node *head, int key)
{
    Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Key %d not found in the list.\n", key);
}

// Function to display the contents of the list
void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    printf("List contents: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    Node *head = NULL;
    int choice, data, key;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create the list by adding a node at the front\n");
        printf("2. Insert a node to the left of a node with a specific key\n");
        printf("3. Delete all occurrences of a key\n");
        printf("4. Search a node based on its key value\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to add at the front: ");
            scanf("%d", &data);
            createList(&head, data);
            break;
        case 2:
            printf("Enter the key to insert left of: ");
            scanf("%d", &key);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertLeft(&head, key, data);
            break;
        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            deleteAllOccurrences(&head, key);
            break;
        case 4:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            searchNode(head, key);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
