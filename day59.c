#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Map for inorder index
int map[10000];

// Build tree
struct Node* build(int* postorder, int postStart, int postEnd,
                   int* inorder, int inStart, int inEnd) {
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    int rootVal = postorder[postEnd];

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = map[rootVal];
    int leftSize = inIndex - inStart;

    // Build right FIRST
    root->right = build(postorder, postStart + leftSize, postEnd - 1,
                        inorder, inIndex + 1, inEnd);

    root->left = build(postorder, postStart, postStart + leftSize - 1,
                       inorder, inStart, inIndex - 1);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (!root) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
        map[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct Node* root = build(postorder, 0, n - 1,
                              inorder, 0, n - 1);

    preorder(root);

    return 0;
}
