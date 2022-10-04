# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = [(root,0)]
        ans = 1
        while q:
            ans = max(ans, q[-1][1] - q[0][1] + 1)
            tmp = []
            for node, val in q:
                if node.left:
                    tmp.append((node.left, val*2))
                if node.right:
                    tmp.append((node.right, val*2 + 1))
            q = tmp
        return ans