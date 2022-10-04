# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        li = []
        def traverse(node):
            if node == None:
                return
            li.append(node.val)
            if node.left:
                traverse(node.left)
            if node.right:
                traverse(node.right)
            return
        traverse(root1)
        traverse(root2)
        li.sort()
        return li