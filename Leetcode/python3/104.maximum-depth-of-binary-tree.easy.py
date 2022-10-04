# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
ans = 1
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        global ans
        ans = 1
        def traverse(node, dep):
            global ans
            ans = max(ans, dep)
            if node.left:
                traverse(node.left, dep+1)
            if node.right:
                traverse(node.right, dep+1)
        if not root:
            return 0
        traverse(root,1)
        return ans