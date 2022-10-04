class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        tmp = []
        m = len(grid)
        n = len(grid[0])
        ln = m*n
        k = ln - (k%ln)
        for i in grid:
            for j in i:
                tmp.append(j)
        newTmp = tmp[k:] + tmp[:k]
        ans = []
        for i in range(m):
            tmp = []
            for j in range(n):
                tmp.append(newTmp[i*n+j])
            ans.append(tmp)
        return ans