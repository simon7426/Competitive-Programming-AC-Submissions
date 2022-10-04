class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        cnt = [0 for i in range(65)]
        for i in nums:
            cnt[i+30]+=1
        x = 0
        for i in range(len(nums)):
            x = nums[i]
            nums[i] = 1
            for j in range(65):
                if not cnt[j]:
                    continue
                if(x+30==j):
                    if(cnt[j]==1):
                        continue
                    nums[i] = nums[i] * (j-30) ** (cnt[j]-1)
                else:
                    nums[i] = nums[i] * (j-30) ** (cnt[j])
        return nums