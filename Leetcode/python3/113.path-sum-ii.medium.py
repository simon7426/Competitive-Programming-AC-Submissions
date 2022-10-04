# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []
        elif not root.left and not root.right:
            if root.val == targetSum:
                return [[root.val]]
            else:
                return []
        l = self.pathSum(root.left, targetSum - root.val)
        r = self.pathSum(root.right, targetSum - root.val)
        resL = [[root.val]+x for x in l]
        resR = [[root.val]+x for x in r]
        return resL + resR