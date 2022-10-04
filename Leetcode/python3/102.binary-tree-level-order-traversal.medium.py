# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: return []

        queue, res = collections.deque([root]),[]

        while queue:

            size = len(queue)

            tmp=[]

            while size>0: 

                node = queue.popleft()

                tmp.append(node.val)

                if node.left:

                    queue.append(node.left)

                if node.right:

                    queue.append(node.right)

                size-=1

            res.append(tmp)

        return res