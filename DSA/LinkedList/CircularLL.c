#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the front of the circular linked list
void insertFront(Node** start, int data) {
    Node* newNode = createNode(data);
    if (*start == NULL) {
        *start = newNode;
        newNode->link = *start;  // First node points to itself
    } else {
        Node* temp = *start;
        while (temp->link != *start) {
            temp = temp->link;
        }
        newNode->link = *start;
        temp->link = newNode;
        *start = newNode;  // Update start to the new node
    }
    printf("Inserted %d at the front.\n", data);
}

// Function to insert a node at the rear of the circular linked list
void insertRear(Node** start, int data) {
    Node* newNode = createNode(data);
    if (*start == NULL) {
        *start = newNode;
        newNode->link = *start;  // First node points to itself
    } else {
        Node* temp = *start;
        while (temp->link != *start) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = *start;
    }
    printf("Inserted %d at the rear.\n", data);
}

// Function to delete a node from the front
void deleteFront(Node** start) {
    if (*start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*start)->link == *start) {
        printf("Deleted %d from the front.\n", (*start)->data);
        free(*start);
        *start = NULL;
    } else {
        Node* temp = *start;
        Node* last = *start;
        while (last->link != *start) {
            last = last->link;
        }
        printf("Deleted %d from the front.\n", (*start)->data);
        last->link = (*start)->link;
        *start = (*start)->link;
        free(temp);
    }
}

// Function to delete a node from the rear
void deleteRear(Node** start) {
    if (*start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*start)->link == *start) {
        printf("Deleted %d from the rear.\n", (*start)->data);
        free(*start);
        *start = NULL;
    } else {
        Node* temp = *start;
        while (temp->link->link != *start) {
            temp = temp->link;
        }
        printf("Deleted %d from the rear.\n", temp->link->data);
        free(temp->link);
        temp->link = *start;
    }
}

// Function to display the circular linked list
void display(Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = start;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != start);
    printf("(start)\n");
}

// Function to get the length of the circular linked list
int length(Node* start) {
    if (start == NULL) {
        return 0;
    }

    int count = 0;
    Node* temp = start;
    do {
        count++;
        temp = temp->link;
    } while (temp != start);

    return count;
}

void insertAtPosition(Node** start, int data, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*start == NULL) {  // Empty list case
        newNode->link = newNode;
        *start = newNode;
        printf("Inserted %d at position 1 (empty list).\n", data);
        return;
    }

    Node* temp = *start;
    int length = 0;

    // Traverse the list to find the length using do-while loop
    do {
        temp = temp->link;
        length++;
    } while (temp != *start);

    // If the position is out of bounds, return an error
    if (pos < 1 || pos > length + 1) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    // Insert at the beginning
    if (pos == 1) {
        temp = *start;
        while (temp->link != *start) {  // Go to the last node
            temp = temp->link;
        }
        newNode->link = *start;
        temp->link = newNode;
        *start = newNode;
        printf("Inserted %d at position 1 (beginning).\n", data);
    } 
    // Insert at the end
    else if (pos == length + 1) {
        temp = *start;
        while (temp->link != *start) {
            temp = temp->link;
        }
        newNode->link = *start;
        temp->link = newNode;
        printf("Inserted %d at position %d (end).\n", data, pos);
    } 
    // Insert at other positions
    else {
        temp = *start;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
        printf("Inserted %d at position %d.\n", data, pos);
    }
}

void deleteAtPosition(Node** start, int pos) {
    if (*start == NULL) {  // If the list is empty
        printf("List is empty.\n");
        return;
    }

    Node* temp = *start;
    int length = 0;

    // Traverse the list to calculate the length
    do {
        temp = temp->link;
        length++;
    } while (temp != *start);

    // Check if the position is out of bounds
    if (pos < 1 || pos > length) {
        printf("Position out of bounds.\n");
        return;
    }

    // If deleting the first node
    if (pos == 1) {
        // Case when there's only one node in the list
        if ((*start)->link == *start) {
            free(*start);
            *start = NULL;
            printf("Deleted node at position 1 (the only node).\n");
            return;
        }

        // Find the last node to update its link
        Node* last = *start;
        while (last->link != *start) {
            last = last->link;
        }

        Node* toDelete = *start;
        last->link = (*start)->link;  // Update the last node's link
        *start = (*start)->link;  // Update the start pointer to the second node
        free(toDelete);  // Delete the node
        printf("Deleted node at position 1 (first node).\n");
        return;
    }

    // Delete at other positions
    temp = *start;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->link;
    }

    Node* toDelete = temp->link;  // Node to be deleted
    temp->link = toDelete->link;  // Unlink the node from the list
    free(toDelete);  // Free the deleted node
    printf("Deleted node at position %d.\n", pos);
}


// Function to reverse the circular linked list
void reverse(Node** start) {
    if (*start == NULL || (*start)->link == *start) {
        return; // List is empty or has only one node
    }

    Node *prev = NULL, *curr = *start, *next;
    do {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    } while (curr != *start);

    (*start)->link = prev;
    *start = prev;
    printf("List reversed.\n");
}

// Function to search for a node with a given value
int search(Node* start, int key) {
    if (start == NULL) {
        return -1;
    }
    Node* temp = start;
    int pos = 1;
    do {
        if (temp->data == key) {
            return pos;
        }
        temp = temp->link;
        pos++;
    } while (temp != start);
    return -1;
}

// Function to split the list into two circular linked lists
void splitList(Node* start, Node** list1, Node** list2) {
    if (start == NULL) {
        return; // List is empty
    }

    Node* slow = start;
    Node* fast = start;

    while (fast->link != start && fast->link->link != start) {
        slow = slow->link;
        fast = fast->link->link;
    }

    *list1 = start;
    *list2 = slow->link;
    slow->link = *list1;

    Node* temp = *list2;
    while (temp->link != start) {
        temp = temp->link;
    }
    temp->link = *list2;
    printf("List split into two.\n");
}

// Function to concatenate two circular linked lists
void concatenate(Node** start1, Node** start2) {
    if (*start1 == NULL) {
        *start1 = *start2;
        return;
    }
    if (*start2 == NULL) {
        return;
    }

    Node* temp1 = *start1;
    Node* temp2 = *start2;

    while (temp1->link != *start1) {
        temp1 = temp1->link;
    }
    while (temp2->link != *start2) {
        temp2 = temp2->link;
    }

    temp1->link = *start2;
    temp2->link = *start1;
    printf("Lists concatenated.\n");
}

// Function to clear the circular linked list
void clearList(Node** start) {
    if (*start == NULL) {
        return;
    }

    Node* temp = *start;
    Node* next;

    do {
        next = temp->link;
        free(temp);
        temp = next;
    } while (temp != *start);

    *start = NULL;
    printf("List cleared.\n");
}

// Function to rotate the circular linked list by n positions
void rotate(Node** start, int n) {
    if (*start == NULL || n <= 0) {
        return;  // If list is empty or invalid rotation
    }

    int len = length(*start);

    // Adjust n if it is greater than the length of the list
    n = n % len;
    if (n == 0) {
        return; // No need to rotate if n is 0 or multiple of length
    }

    Node* temp = *start;
    
    // Traverse to the (len - n)th node (the new last node after rotation)
    for (int i = 1; i < len - n; i++) {
        temp = temp->link;
    }

    // Set the new start and rearrange the links
    Node* newStart = temp->link;
    Node* last = *start;

    // Traverse to the last node to connect it to the new start
    while (last->link != *start) {
        last = last->link;
    }

    // Last node links to the new start
    last->link = newStart;
    temp->link = *start;  // The old last node of the rotated part becomes the first node
    *start = newStart;

    printf("List rotated by %d positions.\n", n);
}
// Main function
int main() {
    int choice, value, pos, n;
    Node* list1 = NULL;
    Node* list2 = NULL;

    do {
        printf("\nEnter your choice:\n");
        printf("1: Insert element at the front of List 1\n");
        printf("2: Insert element at the rear of List 1\n");
        printf("3: Delete element from the front of List 1\n");
        printf("4: Delete element from the rear of List 1\n");
        printf("5: Display List 1\n");
        printf("6: Display the length of List 1\n");
        printf("7: Insert element at the front of List 2\n");
        printf("8: Insert element at the rear of List 2\n");
        printf("9: Delete element from the front of List 2\n");
        printf("10: Delete element from the rear of List 2\n");
        printf("11: Display List 2\n");
        printf("12: Display the length of List 2\n");
        printf("13: Insert element at a specific position in List 1\n");
        printf("14: Delete element from a specific position in List 1\n");
        printf("15: Search for an element in List 1\n");
        printf("16: Reverse List 1\n");
        printf("17: Split List 1\n");
        printf("18: Concatenate List 1 and List 2\n");
        printf("19: Clear List 1\n");
        printf("20: Clear List 2\n");
        printf("21: Rotate List 1 by N positions\n");
        printf("-1: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            // Other cases...
            case 21:
                printf("Enter the number of positions to rotate by: ");
                scanf("%d", &n);
                rotate(&list1, n);
                break;
            case -1:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != -1);

    return 0;
}
