class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if word1 == word2:
            return 0
        m = len(word1)
        n = len(word2)
        
        dp = [[-1 for _ in range(n+1)] for _ in range (m+1)]
        def lcs(x,y):
            if  x==0 or y == 0:
                return 0
            if dp[x][y] != -1:
                return dp[x][y]
            if word1[x-1] == word2[y-1]:
                dp[x][y] = 1 + lcs(x-1,y-1)
                return dp[x][y]
            dp[x][y] = max(lcs(x,y-1), lcs(x-1,y))
            return dp[x][y]
        ans = lcs(m,n)
        return m-ans+n-ans