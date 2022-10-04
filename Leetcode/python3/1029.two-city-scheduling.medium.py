class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        def sortKey(val):
            return val[0]-val[1]
        costs.sort(key=sortKey)
        n = len(costs)//2
        ans = 0
        for i in range(n):
            ans+=costs[i][0]+costs[n+i][1]
        return ans
            
            