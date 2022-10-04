# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        ans = collections.defaultdict(int)
        def dfs(node, dep):
            node.dep = dep
            ans[node.dep]+=node.val
            if node.left:
                dfs(node.left,dep+1)
            if node.right:
                dfs(node.right,dep+1)
        dfs(root,0)
        mx = 0
        ret = ans[mx]
        for key,val in ans.items():
            if key>mx:
                mx = key
                ret = ans[mx]
        return ret