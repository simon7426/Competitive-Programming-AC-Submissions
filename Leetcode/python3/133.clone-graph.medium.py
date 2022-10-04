"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        self.visit = {}
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        if node in self.visit:
            return self.visit[node]
        ans = Node(node.val, [])
        self.visit[node] = ans
        if node.neighbors:
            ans.neighbors = [self.cloneGraph(neighbor) for neighbor in node.neighbors ]
        return ans