int isStructurallyIdentical(Node* root1, Node* root2) {
    // If both roots are NULL, the structures are identical
    if (root1 == NULL && root2 == NULL) {
        return 1; // True
    }

    // If one of the roots is NULL and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL) {
        return 0; // False
    }

    // Recursively check the left and right subtrees
    return isStructurallyIdentical(root1->lchild, root2->lchild) &&
           isStructurallyIdentical(root1->rchild, root2->rchild);
}

Node* merge(Node* root1, Node* root2) {
    // If both nodes are NULL, the merged node is NULL
    if (root1 == NULL && root2 == NULL) {
        return NULL;
    }

    // If one of the nodes is NULL, return the other node
    if (root1 == NULL) {
        return root2;
    }
    if (root2 == NULL) {
        return root1;
    }

    // Create a new node with the sum of the values from the two nodes
    Node* newRoot = createNode(root1->data + root2->data);

    // Recursively merge the left and right subtrees
    newRoot->lchild = merge(root1->lchild, root2->lchild);
    newRoot->rchild = merge(root1->rchild, root2->rchild);

    return newRoot;
}
