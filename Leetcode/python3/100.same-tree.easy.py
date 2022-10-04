# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def explore(node1,node2):
    if node1.left:
        if node2.left:
            if not explore(node1.left,node2.left):
                return False
        else:
            return False
    elif not node2.left:
        pass
    else:
        return False
    if node1.right:
        if node2.right:
            if not explore(node1.right,node2.right):
                return False
        else:
            return False
    elif not node2.right:
        pass
    else:
        return False
    return node1.val == node2.val
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and q:
            return False
        if p and not q:
            return False
        if not p and not q:
            return True
        return explore(p,q)