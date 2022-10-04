class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ret = 0
        ans = -1000010
        for num in nums:
            ret+=num
            ans = max(ans,ret)
            if(ret<0):
                ret = 0
        return ans
            