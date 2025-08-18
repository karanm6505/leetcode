# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorder(self, root):
        if root is None:
            return []
        else:
            return self.inorder(root.left) + [root.val] + self.inorder(root.right)
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        L = self.inorder(root)
        return L[k-1]
        