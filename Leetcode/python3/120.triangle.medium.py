class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = []
        dp.append(triangle[0])
        for i in range(1, len(triangle)):
            tmp = []
            for cnt, j in enumerate(triangle[i]):
                if cnt == 0:
                    tmp.append(j+dp[i-1][0])
                elif cnt == len(triangle[i]) - 1:
                    tmp.append(j+dp[i-1][-1])
                else:
                    tmp.append(j+min(dp[i-1][cnt],dp[i-1][cnt-1]))
            dp.append(tmp)
        return min(dp[len(triangle)-1])