# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def diameter(node):
            dep_left = (0,0)
            dep_right = (0,0)
            if not node.left and not node.right:
                return (1,0)
            if node.left:
                dep_left = diameter(node.left)
            if node.right:
                dep_right = diameter(node.right)
            return (1+max(dep_left[0],dep_right[0]),max(dep_left[0]+dep_right[0],max(dep_left[1],dep_right[1])))
        
        ans = diameter(root)
        return ans[1]