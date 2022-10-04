class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def check(val):
            sm = 0
            cnt = 1
            for i in nums:
                sm+=i
                if sm>val:
                    sm = i
                    cnt+=1
                    if cnt>m:
                        return False
            return True
        
        lo = max(nums)
        hi = sum(nums)
        while(lo<hi):
            mid = lo + (hi-lo)//2
            if check(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo