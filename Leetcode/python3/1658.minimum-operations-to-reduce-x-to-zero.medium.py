class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        s = sum(nums)-x
        ans =float("inf")
        d = {0:-1,}
        for i in range(len(nums)):
            nums[i]+=nums[i-1] if i!=0 else 0
            d[nums[i]] = i
            if nums[i]-s in d:
                ans = min(ans, len(nums)-(i-d[nums[i]-s]))
        return ans if ans!=float("inf") else -1
                