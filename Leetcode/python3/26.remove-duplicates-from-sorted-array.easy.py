class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for num in nums:
            if i<1 or nums[i-1]!=num:
                nums[i] = num
                i+=1
        return i