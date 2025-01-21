int isPalindrome(struct Node* start) {
    if (start == NULL) {
        return 1; // An empty list is a palindrome
    }
    
    struct Node* left = start;  // Pointer starting from the beginning
    struct Node* right = start; // Pointer starting from the end

    // Move the `right` pointer to the last node
    while (right->next != NULL) {
        right = right->next; // Move one step at a time until we reach the last node
    }

    // Now compare the list from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data) {
            return 0; // If any mismatch, it's not a palindrome
        }
        left = left->next; // Move the `left` pointer forward
        right = right->prev; // Move the `right` pointer backward
    }

    return 1; // If we checked everything and didn't find a mismatch, it's a palindrome
}
