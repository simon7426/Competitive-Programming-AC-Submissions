class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for st in strs:
            zero,one = 0,0    
            for c in st:
                if c=="0":
                    zero+=1
                elif c=="1":
                    one +=1
            for i in range(m,zero-1,-1):
                for j in range(n,one-1,-1):
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1)
        return dp[m][n]