"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        qq = collections.deque([root])
        while qq:
            sz = len(qq)
            for i in range(sz):
                node = qq.popleft()
                if i < sz -1:
                    node.next = qq[0]
                if node.left:
                    qq.append(node.left)
                if node.right:
                    qq.append(node.right)
        return root