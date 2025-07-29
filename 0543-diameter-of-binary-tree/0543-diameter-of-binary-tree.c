/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}
int depth(struct TreeNode* root, int* diameter) {
    if (root == NULL) return 0;

    int left = depth(root->left, diameter);
    int right = depth(root->right, diameter);

    *diameter = max(*diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root)
 {
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
}