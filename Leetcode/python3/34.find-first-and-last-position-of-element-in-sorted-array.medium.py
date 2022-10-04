class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lft = bisect.bisect_left(nums,target)
        rht = bisect.bisect(nums,target)
        if not nums or lft>=len(nums) or nums[lft]!=target or rht<0 or nums[rht-1]!=target:
            return [-1,-1]

        return [lft,rht-1]
    