# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root is None:
                return None
            if root.val == 1:
                root.ok = True
            else:
                root.ok = False
            if root.left and dfs(root.left):
                root.ok = True
            else:
                root.left = None
            if root.right and dfs(root.right):
                root.ok = True
            else:
                root.right = None
                
            return root.ok
        dfs(root)
        if root.ok:
            return root
        else:
            return None