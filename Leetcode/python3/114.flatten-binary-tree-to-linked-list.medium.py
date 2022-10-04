# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def dfs(root, tmp):
            if not root:
                return None
            dfs(root.right, tmp)
            dfs(root.left,tmp)
            root.right = tmp.pop()
            root.left = None
            tmp.append(root)
            return root
        dfs(root,[None])
        