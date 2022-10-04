class Solution:
    def countSubstrings(self, s: str) -> int:
        cnt = 0
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for l in range(1,n+1):
            for start in range(n-l+1):
                end = start+l-1
                if l==1 or (l==2 and s[start]==s[end]) or (l>=3 and s[start]==s[end] and dp[start+1][end-1]):
                    dp[start][end] = True
                    cnt+=1
        return cnt