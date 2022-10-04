class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        pre_sum = []
        sm = 0
        for val in nums:
            sm+=val
            pre_sum.append(sm)
        l = 0
        r = 0
        vis = {}
        ans = 0
        while (r<len(nums)):
            if nums[r] not in vis:
                ans = max(ans, pre_sum[r]-(pre_sum[l-1] if l else 0))
                vis[nums[r]] = True
                r+=1
            else:
                while nums[l] != nums[r]:
                    vis.pop(nums[l])
                    l+=1
                vis.pop(nums[l])
                l+=1
        return ans