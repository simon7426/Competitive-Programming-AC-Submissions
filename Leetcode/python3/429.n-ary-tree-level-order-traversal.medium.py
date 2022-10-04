"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = defaultdict(list)
        
        tmp = deque()
        tmp.append((root,1))
        while(len(tmp)):
            head, dep = tmp.popleft()
            if head:
                ans[dep].append(head.val)
                for child in head.children:
                    tmp.append((child, dep+1))
        anss = []
        for key,val in ans.items():
            anss.append(val)
        return anss
        
            