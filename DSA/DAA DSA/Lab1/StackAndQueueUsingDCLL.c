#include <stdio.h>
#include <stdlib.h>

// Define a structure for the doubly linked list node
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Define a structure for the Circular Doubly Linked List
typedef struct CircularDoublyLinkedList
{
    Node *tail;
} CircularDoublyLinkedList;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode; // Points to itself (circular)
    return newNode;
}

// Initialize the Circular Doubly Linked List
void initialize(CircularDoublyLinkedList *list)
{
    list->tail = NULL; // List is initially empty
}

// Function to check if the list is empty
int isEmpty(CircularDoublyLinkedList *list)
{
    return list->tail == NULL;
}

// Function to add a node to the front (For Stack Push)
void pushStack(CircularDoublyLinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (isEmpty(list))
    {
        list->tail = newNode;
    }
    else
    {
        Node *head = list->tail->next; // Head node
        newNode->next = head;
        newNode->prev = list->tail;
        head->prev = newNode;
        list->tail->next = newNode;
    }
}

// Function to remove a node from the front (For Stack Pop)
void popStack(CircularDoublyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }

    Node *head = list->tail->next; // Head node
    if (head == list->tail)
    { // Only one element
        list->tail = NULL;
    }
    else
    {
        Node *newHead = head->next;
        list->tail->next = newHead;
        newHead->prev = list->tail;
    }
    printf("Popped: %d\n", head->data);
    free(head);
}

// Function to add a node to the rear (For Queue Enqueue)
void enqueueQueue(CircularDoublyLinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (isEmpty(list))
    {
        list->tail = newNode;
    }
    else
    {
        Node *head = list->tail->next; // Head node
        newNode->next = head;
        newNode->prev = list->tail;
        head->prev = newNode;
        list->tail->next = newNode;
        list->tail = newNode; // Update tail to the new node
    }
}

// Function to remove a node from the front (For Queue Dequeue)
void dequeueQueue(CircularDoublyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }

    Node *head = list->tail->next; // Head node
    if (head == list->tail)
    { // Only one element
        list->tail = NULL;
    }
    else
    {
        Node *newHead = head->next;
        list->tail->next = newHead;
        newHead->prev = list->tail;
    }
    printf("Dequeued: %d\n", head->data);
    free(head);
}

// Function to display the list
void display(CircularDoublyLinkedList *list)
{
    if (isEmpty(list))
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->tail->next; // Start from head
    printf("List contents: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->tail->next); // Stop when we circle back to the head
    printf("(circular)\n");
}

// Main function
int main()
{
    CircularDoublyLinkedList list;
    initialize(&list);

    int choice, data;

    do
    {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue to Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push to stack: ");
            scanf("%d", &data);
            pushStack(&list, data);
            break;
        case 2:
            popStack(&list);
            break;
        case 3:
            printf("Enter data to enqueue to queue: ");
            scanf("%d", &data);
            enqueueQueue(&list, data);
            break;
        case 4:
            dequeueQueue(&list);
            break;
        case 5:
            display(&list);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory
    while (!isEmpty(&list))
    {
        dequeueQueue(&list);
    }

    return 0;
}
