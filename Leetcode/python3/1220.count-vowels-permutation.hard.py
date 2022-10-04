class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dp = [1 for _ in range(5)]
        for _ in range(n-1):
            tmp = []
            tmp.append(dp[1] + dp[2] + dp[4])
            tmp.append(dp[0] + dp[2])
            tmp.append(dp[1] + dp[3])
            tmp.append(dp[2])
            tmp.append(dp[2] + dp[3])
            dp = tmp
        return sum(dp) % (10**9+7)