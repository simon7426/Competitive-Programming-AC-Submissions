class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9+7
        dp = [1]
        for i in range(2,n+1):
            tmp = []
            num = 0
            for j in range(min(1+i*(i-1)//2,k+1)):
                if j<len(dp):
                    num = (num+dp[j])%MOD
                if j>=i:
                    num = (MOD+num-dp[j-i]) % MOD
                tmp.append(num)
            dp = tmp
        return k < len(dp) and dp[k] or 0