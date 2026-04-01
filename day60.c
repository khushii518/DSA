#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
bool isCBT(struct Node* root, int index, int total) {
    if (root == NULL) return true;

    if (index >= total)
        return false;

    return isCBT(root->left, 2 * index + 1, total) &&
           isCBT(root->right, 2 * index + 2, total);
}

// Check Min Heap property
bool isMinHeap(struct Node* root) {
    if (root == NULL) return true;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);

    // Both children
    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isMinHeap(root->left) &&
           isMinHeap(root->right);
}

// Main function
bool isHeap(struct Node* root) {
    int total = countNodes(root);

    if (!isCBT(root, 0, total))
        return false;

    return isMinHeap(root);
}
