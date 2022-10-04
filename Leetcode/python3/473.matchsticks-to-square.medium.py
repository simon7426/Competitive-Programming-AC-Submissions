class Solution:

    def makesquare(self, nums: List[int]) -> bool:

        n = len(nums)

        if n < 4: return False

        s = sum(nums)

        if s % 4: return False

        target = s // 4

        if max(nums) > target: return False

        used = [False] * n

        def dfs(idx, cur, k):

            if k == 4: return True

            if cur == target:

                return dfs(0, 0, k + 1)

            for i in range(idx, n):

                if not used[i]:

                    used[i] = True

                    if dfs(i, cur + nums[i], k): return True

                    used[i] = False

            return False

        return dfs(0, 0, 0)
        