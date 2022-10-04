class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums = sorted(nums)
        if len(nums) &1:
            fl = nums[len(nums)//2]
        else:
            fl = (nums[len(nums)//2-1]+nums[len(nums)//2])//2
        ret = 0
        for num in nums:
            ret += abs(fl-num)
        return ret