class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = pre = 0
        n = len(colors)
        for i in range(1,n):
            if colors[i]!=colors[pre]:
                pre = i
            else:
                ans += min(neededTime[i], neededTime[pre])
                if neededTime[pre]<neededTime[i]:
                    pre = i
        return ans
                    