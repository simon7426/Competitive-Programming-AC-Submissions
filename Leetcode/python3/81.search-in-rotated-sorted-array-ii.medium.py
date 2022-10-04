class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        l = 0 
        r = n-1
        while(l<=r):
            while (l<r) and (nums[l]==nums[r]):
                l+=1
            mid = l + (r-l)//2
            if nums[mid] == target:
                return True
            if nums[mid]>=nums[l]:
                if nums[l]<=target and target < nums[mid]:
                    r = mid -1
                else:
                    l = mid+1
            elif nums[mid]<= nums[r]:
                if nums[mid]< target and target <= nums[r]:
                    l = mid+1
                else:
                    r = mid -1
        return False