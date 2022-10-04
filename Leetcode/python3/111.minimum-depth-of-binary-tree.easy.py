# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
ans = 100010
def explore(node, value):
    global ans
    leaf = 1
    if node.left:
        leaf = 0
        explore(node.left,value+1)
    if node.right:
        leaf = 0
        explore(node.right,value+1)
    if leaf:
        ans = min(ans,value)
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        global ans
        ans = 100010
        explore(root,1)
        return ans