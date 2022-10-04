class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        def getSum(val1, val2):
            res = ((val2+val1)*(val2-val1)+(val2-val1))//2
            return res
        nums.sort()
        ans = 0
        if k<=nums[0]-1:
            ans+=getSum(0, k)
            k=0
        else:
            ans+=getSum(0,nums[0]-1)
            k -= nums[0]-1
        for i in range(1,len(nums)):
            cnt = nums[i]-nums[i-1]-1
            if k==0 or cnt<=0:
                continue
            if cnt <= k:
                k-=cnt
                ans += getSum(nums[i-1],nums[i]-1)
            else:
                ans+=getSum(nums[i-1], nums[i-1]+k)
                k = 0
        if k:
            ans+=getSum(nums[len(nums)-1], nums[len(nums)-1]+k)
        return int(ans)