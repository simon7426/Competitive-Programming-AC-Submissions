class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        subs = [nums[0]]
        for i in range(1,len(nums)):
            if nums[i] > subs[-1]: subs.append(nums[i])
            else:
                subs[bisect_left(subs, nums[i], 0, len(subs))] = nums[i]
        return len(subs)