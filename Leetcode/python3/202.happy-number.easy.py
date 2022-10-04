class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        def cntHappy(nn):
            sm = 0
            while(nn):
                val = nn%10
                nn = nn//10
                sm+=(val * val)
            return sm
        while(n!=1):
            n = cntHappy(n)
            if n in seen:
                return False
            seen.add(n)
        return True
            