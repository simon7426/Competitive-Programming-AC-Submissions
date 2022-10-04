class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in reversed(range(2,len(nums))):
            if i+1 < len(nums) and nums[i]==nums[i+1]:
                continue
            target = -nums[i]
            left,right = 0,i-1
            while(left<right):
                if nums[left]+nums[right]<target:
                    left+=1
                elif nums[left]+nums[right]>target:
                    right-=1
                else:
                    ans.append([nums[left],nums[right],nums[i]])
                    left+=1
                    right-=1
                    while(left<right and nums[left]==nums[left-1]):
                        left+=1
                    while(left<right and nums[right]==nums[right+1]):
                        right-=1
        return ans
                    