"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def __init__(self):
        self.visit = {None: None}
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head in self.visit:
            return self.visit[head]
        node = Node(head.val,None,None)
        self.visit[head] = node
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)
        return node