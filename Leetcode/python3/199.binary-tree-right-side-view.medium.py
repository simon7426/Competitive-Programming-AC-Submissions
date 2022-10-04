# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root, result_list, level):

            if not root:

                return

            if root and level == len(result_list):

                result_list.append(root.val)

            dfs(root.right, result_list, level+1)

            dfs(root.left, result_list, level+1)

            return result_list

        return dfs(root, [], 0)