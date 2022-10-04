class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = 0
        for i, x in enumerate(nums):
            ans = ans ^ i ^ x
        return ans ^ len(nums)