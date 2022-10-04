class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        isDouble = True
        ans = 0
        n = len(nums)
        mn = nums[0]
        is_min = []
        is_min.append(0)
        for i in range(1, n):
            if nums[i]>mn:
                is_min.append(1)
                mn = nums[i]
            else:
                is_min.append(0)
        mx = nums[n-1]
        is_max = []
        is_max.append(1)        
        for i in range(n-2,-1,-1):
            if nums[i]<mx:
                is_max.append(1)
                mx = nums[i]
            else:
                is_max.append(0)
        # print(is_max)
        is_max.reverse()
        # print(is_max)
        for i in range(1, n-1):
            if is_min[i] and is_max[i]:
                ans+=1
        for i in range(1, len(nums)-1):
            if nums[i-1]<nums[i] and nums[i]<nums[i+1]:
                ans+=1
        return ans
            