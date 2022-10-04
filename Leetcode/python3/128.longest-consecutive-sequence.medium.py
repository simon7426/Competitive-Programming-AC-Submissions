class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        if not nums:
            return 0
        ans = 1
        for val in nums:
            if val-1 not in nums:
                tmp = 1
                tmp_num = val+1
                while(tmp_num in nums):
                    tmp_num+=1
                    tmp+=1
                ans = max(ans,tmp)
        return ans