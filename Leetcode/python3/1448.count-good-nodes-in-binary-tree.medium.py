# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode, maxx: int = -10000) -> int:
        return self.goodNodes(root.left, max(maxx, root.val)) + self.goodNodes(root.right, max(maxx, root.val)) + (root.val >= maxx) if root else 0