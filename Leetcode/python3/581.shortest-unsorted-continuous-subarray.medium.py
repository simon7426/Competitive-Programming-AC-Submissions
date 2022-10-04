class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        n = len(nums)
        lm = -1
        for i in range(n):
            if nums[i]!=sorted_nums[i]:
                lm = i
                break
        if lm==-1:
            return 0
        rm = n-1
        for i in range(n):
            if nums[n-i-1]!=sorted_nums[n-i-1]:
                rm = n-i-1
                break
        return rm-lm+1