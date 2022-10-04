class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9+7
        dp = [[[0] * n for _ in range(m)] for _ in range(maxMove+1)]
        for s in range(1,maxMove+1):
            for x in range(m):
                for y in range(n):
                    v1 = 1 if x==0 else dp[s-1][x-1][y]
                    v2 = 1 if x==m-1 else dp[s-1][x+1][y]
                    v3 = 1 if y==0 else dp[s-1][x][y-1]
                    v4 = 1 if y==n-1 else dp[s-1][x][y+1]
                    dp[s][x][y] = (v1+v2+v3+v4) % MOD
        return dp[maxMove][startRow][startColumn]