class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        mark = {}
        mark[0] = -1
        cur = 0
        ans = 0
        for i in range(n):
            if nums[i] == 0:
                cur-=1
            else:
                cur+=1
            if cur in mark:
                ans = max(ans, i-mark[cur])
            else:
                mark[cur] = i
        return ans