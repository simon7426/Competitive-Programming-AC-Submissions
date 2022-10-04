class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[1]]
        for i in range(1,numRows):
            tmp = [1]
            for j in range(1,i):
                tmp.append(dp[i-1][j]+dp[i-1][j-1])
            tmp.append(1)
            dp.append(tmp)
        return dp
                