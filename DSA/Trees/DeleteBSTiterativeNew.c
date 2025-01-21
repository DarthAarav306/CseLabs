Node* delete(Node* root, int ele) {
    if (!root) {
        printf("Tree is empty\n");
        return NULL; // If the tree is empty
    }

    Node* current = root;
    Node* prev = NULL;

    // Search for the node to delete
    while (current && current->data != ele) {
        prev = current;
        if (ele < current->data) {
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }

    // If the element is not found
    if (!current) {
        printf("Element not found\n");
        return root;
    }

    // Case 1: Node to delete is a leaf
    if (!current->lchild && !current->rchild) {
        if (!prev) { // If the node is the root
            free(current);
            return NULL;
        }
        if (prev->lchild == current) {
            prev->lchild = NULL;
        } else {
            prev->rchild = NULL;
        }
        free(current);
    }
    // Case 2: Node to delete has one child
    else if (!current->lchild || !current->rchild) {
        Node* child = (current->lchild) ? current->lchild : current->rchild;
        if (!prev) { // If the node is the root
            free(current);
            return child;
        }
        if (prev->lchild == current) {
            prev->lchild = child;
        } else {
            prev->rchild = child;
        }
        free(current);
    }
    // Case 3: Node to delete has two children
    else {
        Node* temp = current->rchild;
        Node* tempPrev = current;

        // Find the inorder successor (leftmost node of right subtree)
        while (temp->lchild) {
            tempPrev = temp;
            temp = temp->lchild;
        }

        // Replace the data of the node to delete with the successor's data
        current->data = temp->data;

        // Delete the successor node
        if (tempPrev->lchild == temp) {
            tempPrev->lchild = temp->rchild;
        } else {
            tempPrev->rchild = temp->rchild;
        }
        free(temp);
    }

    return root;
}
