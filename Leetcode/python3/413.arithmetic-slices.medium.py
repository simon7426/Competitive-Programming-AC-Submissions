class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        cnt = 1
        n = len(nums)
        for i in range(1,n-1):
            if nums[i]-nums[i-1] == nums[i+1] - nums[i]:
                ans+=cnt
                cnt+=1
            else:
                cnt = 1
        return ans