# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = {}
        seen = set()
        par = {}
        for val in descriptions:
            if val[0] in seen:
                node = nodes[val[0]]
            else:
                node = TreeNode(val[0],None,None)
                nodes[val[0]] = node
                seen.add(val[0])
            if val[1] in seen:
                new_node = nodes[val[1]]
            else:
                new_node = TreeNode(val[1], None, None)
            nodes[val[1]] = new_node
            seen.add(val[1])
            par[val[1]] = val[0]
            if val[2]:
                node.left = new_node
            else:
                node.right = new_node
        for val in descriptions:
            if val[0] not in par:
                return nodes[val[0]]