# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def check(self,node, lo, hi):
        if not node:
            return True
        if lo and lo.val >= node.val:
            return False
        if hi and hi.val <= node.val:
            return False
        return self.check(node.left, lo, node) and self.check(node.right, node, hi)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.check(root, None, None)