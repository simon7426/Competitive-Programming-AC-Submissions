class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        MOD = (10**9)+7
        dp = {x:1 for x in arr}
        for i in range(len(arr)):
            for j in range(i):
                if(not(arr[i]%arr[j]) and (arr[i]//arr[j]) in dp):
                    dp[arr[i]] = (dp[arr[i]] + ((dp[arr[j]] * dp[(arr[i]//arr[j])]) % MOD)) % MOD
        return sum(dp.values()) % MOD