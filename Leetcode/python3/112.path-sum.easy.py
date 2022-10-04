# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def explore(node, add, target):
    ret = 0
    node.val+=add
    if not node.left and not node.right:
        ret = ret or node.val == target
    if node.left:
        ret = ret or explore(node.left,node.val,target)
    if node.right:
        ret = ret or explore(node.right,node.val,target)
    return ret
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        return explore(root,0,targetSum)