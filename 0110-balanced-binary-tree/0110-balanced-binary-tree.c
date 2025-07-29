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

int checkHeight(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;  

    int right = checkHeight(root->right);
    if (right == -1) return -1;  

    if (abs(left - right) > 1) return -1;  

    return 1 + max(left, right);  
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}
