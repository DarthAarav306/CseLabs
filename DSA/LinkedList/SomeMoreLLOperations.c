void deleteDuplicates(Node* head) {
    if (!head || !head->next) {
        return;
    }

    Node* temp; // Outer loop pointer
    for (temp = head; temp->next != NULL; temp = temp->next) { // Outer loop stops at the second last node
        Node* prev = temp; // Pointer to track the previous node
        Node* temp1;

        for (temp1 = temp->next; temp1 != NULL; /* handled inside */) {
            if (temp1->data == temp->data) { // Duplicate found
                prev->next = temp1->next; // Skip the duplicate
                free(temp1); // Free the duplicate node
                temp1 = prev->next; // Update the current pointer
            } else {
                prev = temp1; // Move the previous pointer
                temp1 = temp1->next; // Move the current pointer
            }
        }
    }
}


// Function to calculate the length of the linked list
int length(Node* head) {
    int len = 0; // Start counting from 0
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}
void rotate(Node** head, int k, int left) {
    if (!*head || (*head)->next == NULL) {
        return; // No rotation needed for empty or single-node list
    }

    int len = length(*head);

    // Correct the value of `k` to ensure it lies within the range
    k = k % len;
    if (k == 0) {
        return; // No rotation needed if `k` is 0 or a multiple of the length
    }

    // Adjust `k` for right rotation if needed
    if (!left) {
        k = len - k;
    }

    // Make the list circular
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = *head;

    // Traverse to the kth node
    temp = *head;
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }

    // Update the head and break the circular connection
    *head = temp->next;
    temp->next = NULL;
}

//BubbleSort
void bubbleSort(Node* head) {
    if (!head || !head->next) {
        return; // No sorting needed for empty or single-node lists
    }

    Node* temp;
    int len = length(head); // Function to calculate the length of the list

    for (int i = 0; i < len - 1; i++) { // Outer loop
        temp = head;

        for (int j = 0; j < len - i - 1; j++) { // Inner loop
            if (temp->data > temp->next->data) { // Compare adjacent nodes
                // Swap the data
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
            }
            temp = temp->next; // Move to the next node
        }
    }
}
void bubbleSort(Node* head) {
    if (!head || !head->next) {
        return; // No sorting needed for empty or single-node lists
    }

    Node* outer = head; // Outer loop pointer

    while (outer->next != NULL) { // Outer loop (traverse the whole list)
        Node* inner = head; // Inner loop pointer

        while (inner->next != NULL) { // Inner loop (compare adjacent elements)
            if (inner->data > inner->next->data) { // Compare adjacent nodes
                // Swap the data
                int temp = inner->data;
                inner->data = inner->next->data;
                inner->next->data = temp;
            }
            inner = inner->next; // Move to the next node
        }

        outer = outer->next; // Move the outer pointer forward
    }
}


void selectionSort(Node* head)
{
    if (!head || !head->next) {
        return; // No sorting needed for empty or single-node lists
    }
    
    Node* i;
    for (i = head; i->next != NULL; i = i->next) {
        Node* j;
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) { // Swap if current `i` data is greater than `j`
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insertAtEnd(Node* head, int data)
{
    Node* newNode = createNode(data);
    if(!head)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void sort(Node** head) {
    if (!*head || !(*head)->next) {
        return; // No sorting needed for empty or single-node lists
    }

    Node* newList = NULL; // Start with an empty new list
    Node* temp = *head;

    while (temp != NULL) {
        Node* newNode = createNode(temp->data); // Create a new node with the current data

        if (!newList) { // If the new list is empty, insert at the start
            newList = newNode;
        } else {
            Node* temp1 = newList;
            Node* prev = NULL;

            // Traverse the new list to find the correct position for the new node
            while (temp1 != NULL) {
                if (temp->data < temp1->data) {
                    break;
                }
                prev = temp1;
                temp1 = temp1->next;
            }

            if (prev == NULL) { // Insert at the beginning
                newNode->next = newList;
                newList = newNode;
            } else if (temp1 == NULL) { // Insert at the end
                prev->next = newNode;
            } else { // Insert in the middle
                prev->next = newNode;
                newNode->next = temp1;
            }
        }

        temp = temp->next; // Move to the next node in the original list
    }

    *head = newList; // Update the original list to point to the new sorted list
}




void bubbleSort(Node** head) {
    if (!*head || !(*head)->next) {
        return; // No sorting needed for empty or single-node lists
    }

    int len = length(*head); // Function to calculate the length of the list
    Node* end = NULL; // Marks the sorted part of the list

    for (int i = 0; i < len - 1; i++) { // Outer loop for each pass
        Node* current = *head;
        Node* prev = NULL;

        while (current->next != end) { // Inner loop for comparison
            if (current->data > current->next->data) { // Compare adjacent nodes
                // Swap nodes
                Node* next = current->next;
                current->next = next->next;
                next->next = current;

                if (prev) {
                    prev->next = next; // Link previous node to the swapped node
                } else {
                    *head = next; // Update head if the first node is swapped
                }

                prev = next; // Update `prev` to the new previous node after swap
            } else {
                // No swap, just move pointers forward
                prev = current;
                current = current->next;
            }
        }

        end = current; // Update the end of the sorted part
    }
}
