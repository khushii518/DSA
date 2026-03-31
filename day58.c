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
struct Node* build(int* preorder, int preStart, int preEnd,
                   int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = rootVal;
    root->left = root->right = NULL;

    int inIndex = map[rootVal];
    int leftSize = inIndex - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
        map[inorder[i]] = i;
    }

    struct Node* root = build(preorder, 0, n - 1,
                              inorder, 0, n - 1);

    postorder(root);

    return 0;
}
