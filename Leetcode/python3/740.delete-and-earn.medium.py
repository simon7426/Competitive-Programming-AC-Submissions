class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = {}
        mx = 0
        for val in nums:
            cnt.setdefault(val,0)
            cnt[val] += val
            mx = max(mx, val)
        points = [0] * (mx+1)
        dp = [0] * (mx+2)
        for k,v in cnt.items():
            points[k] = v
        dp[1] = points[0]
        ans = dp[1]
        for i in range(1,mx+1):
            dp[i+1] = max(dp[i], dp[i-1]+points[i])
            ans = max(dp[i+1], ans)
        return ans
        