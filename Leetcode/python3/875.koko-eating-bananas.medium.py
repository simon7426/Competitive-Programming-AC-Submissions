class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(val):
            cnt = 0
            for item in piles:
                if item % val:
                    cnt += int(item/val) + 1
                else:
                    cnt+= int(item/val)
            # print(cnt,h, val)
            if cnt<=h:
                return True
            else:
                return False
        
        lo = 1
        hi = 1000000000
        while(lo<hi):
            mid = (lo+hi)>>1
            # print(lo, hi, mid)
            if check(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
            