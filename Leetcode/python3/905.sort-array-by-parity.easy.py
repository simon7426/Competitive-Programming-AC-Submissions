class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        def f(x):
            return x & 1
        return sorted(nums, key=f)