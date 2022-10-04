class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n-2
        while i>=0:
            if nums[i]>=nums[i+1]:
                i-=1
            else:
                for j in range(n-1,i,-1):
                    if nums[j]> nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        nums[i+1:] = sorted(nums[i+1:])
                        return
        nums.reverse()