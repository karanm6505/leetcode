/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool inOrder(struct TreeNode* root, struct TreeNode** prev) {
    if (!root) return true;

    if (!inOrder(root->left, prev))
        return false;

    if (*prev && root->val <= (*prev)->val)
        return false;

    *prev = root;

    return inOrder(root->right, prev);
}

bool isValidBST(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    return inOrder(root, &prev);
}