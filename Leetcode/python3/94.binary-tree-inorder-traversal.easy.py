# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root, tmp = []):
            if not root:
                return None
            if root.left:
                dfs(root.left)
            tmp.append(root.val)
            if root.right:
                dfs(root.right)
            return tmp
        
        tmp = dfs(root)
        return tmp