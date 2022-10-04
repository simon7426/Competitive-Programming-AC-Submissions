class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo=0
        hi=len(nums)
        while(lo<hi):
            mid = (lo+hi)>>1
            if(nums[mid]<target):
                lo = mid+1
            else:
                hi = mid
        if(lo<len(nums) and nums[lo]==target):
            return lo
        return -1