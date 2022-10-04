class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)

        dp = []
        for i in range(n+1):
            tmp = []
            for j in range(m+1):
                tmp.append(False)
            dp.append(tmp)
        
        dp[0][0] = True
        for i in range(2,m+1):
            if p[i-1] == "*":
                dp[0][i] = dp[0][i-2]
        for i in range(1,n+1):
            for j in range(1,m+1):
                if p[j-1] == ".":
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1]=="*":
                    if dp[i][j-2] or dp[i][j-1] or ((p[j-2]=="." or p[j-2]==s[i-1]) and dp[i-1][j]):
                        dp[i][j] = True
                else:
                    if s[i-1]==p[j-1] and dp[i-1][j-1]:
                        dp[i][j] = True
        return dp[n][m]