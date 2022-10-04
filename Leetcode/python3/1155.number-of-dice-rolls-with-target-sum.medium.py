class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dpdict = {}
        def dp(d, target):
            if d == 0:
                return 0 if target > 0 else 1
            if (d, target) in dpdict:
                return dpdict[(d, target)]
            to_return = 0
            for kk in range(max(0, target-k), target):
                to_return += dp(d-1, kk)
            dpdict[(d, target)] = to_return
            return to_return
        return dp(n, target) % (10**9 + 7)