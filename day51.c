#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find node pointer
struct TreeNode* find(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return find(root->left, val);
    else
        return find(root->right, val);
}

// LCA in BST
struct TreeNode* LCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct TreeNode* p = find(root, p_val);
    struct TreeNode* q = find(root, q_val);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->val);

    return 0;
}
