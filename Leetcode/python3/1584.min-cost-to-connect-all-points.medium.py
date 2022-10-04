class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        nodes = []
        for i in range(n):
            for j in range(i+1,n):
                nodes.append((abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]),(i,j)))
        nodes = sorted(nodes)
        par = [i for i in range(n)]
        def findPa(x):
            if x == par[x]:
                return x
            par[x] = findPa(par[x])
            return par[x]
        def union(x,y):
            pax = findPa(x)
            pay = findPa(y)
            if pax != pay:
                if pax < pay:
                    par[pay] = pax
                else:
                    par[pax] = pay
                return True
            else:
                return False
        ans = 0
        for val in nodes:
            if union(val[1][0],val[1][1]):
                ans += val[0]
        return ans