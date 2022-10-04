class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        if startValue > target:
            return startValue-target
        ans = 0
        while startValue<target:
            if target & 1:
                target+=1
                ans+=1
            target>>=1
            ans += 1
        return ans+startValue-target
        