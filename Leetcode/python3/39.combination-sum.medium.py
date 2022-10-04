class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def dfs(val, sofar):
            if val == 0:
                ans.append(sofar)
            for num in candidates:
                if val < num:
                    break
                if sofar and num < sofar[-1]:
                    continue
                dfs(val-num, sofar + [num])
        candidates.sort()
        dfs(target, [])
        return ans