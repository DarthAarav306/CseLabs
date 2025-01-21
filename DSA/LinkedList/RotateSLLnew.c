#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int length(Node* head)
{
  if(!head)
  {
    return 0;
  }
  if(!head->next)
  {
    return 1;
  }
  Node* temp = head;
  int count = 0;
  while(temp!=NULL)
  {
    temp = temp->next;
    count++;
  }
  return count;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void rotate(Node** head, int k, int right)
{
    if (!*head || k == 0)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        return;
    }
    int len = length(*head);
    k = k % len;  // Adjust k if it's greater than the length
    if (k == 0)
    {
        return;  // No rotation needed
    }
    if (right)
    {
        k = len - k;
    }
    // Find the last node to make the list circular
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *head;  // Make the list circular
    // Find the node before the new head
    Node* temp1 = *head;
    for (int i = 1; i < k; i++)
    {
        temp1 = temp1->next;
    }
    *head = temp1->next;  // Update the head
    temp1->next = NULL;   // Break the list
}
int main() {
    Node* head = NULL;
    int n, k, right;

    printf("Enter number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Original List: ");
    display(head);

    printf("Enter rotation count k: ");
    scanf("%d", &k);
    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &right);

    rotate(&head, k, right);
    printf("List after rotation: ");
    display(head);

    return 0;
}