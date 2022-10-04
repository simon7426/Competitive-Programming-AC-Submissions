class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return 1
        fst = nums[1] - nums[0]
        if fst == 0:
            ans = 1
        else:
            ans = 2
        for i in range(2,n):
            dif = nums[i] - nums[i-1]
            if (dif > 0 and fst <=0 ) or (dif< 0 and fst>=0):
                ans+=1
                fst = dif
        return ans