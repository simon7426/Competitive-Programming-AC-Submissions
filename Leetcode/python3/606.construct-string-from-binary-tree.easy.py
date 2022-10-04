# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        def preorder(root,ans=""):
            ans+=str(root.val)
            if root.left:
                ans+='('
                ans+=preorder(root.left)
                ans+=')'
            if not root.left and root.right:
                ans+='()'
            
            if root.right:
                ans+='('
                ans+=preorder(root.right)
                ans+=')'
            return ans
        ans = preorder(root)
        return ans