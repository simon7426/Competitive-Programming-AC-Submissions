class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            idx = abs(nums[i])-1
            nums[idx] = abs(nums[idx])*-1
        ret = []
        for i in range(n):
            if nums[i]>0:
                ret.append(i+1)
        return ret
        