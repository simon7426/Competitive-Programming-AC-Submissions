class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m = len(matrix)
        n = len(matrix[0])
        for row in matrix:
            for i in range(1,n):
                row[i]+=row[i-1]
        res = 0
        for i in range(n):
            for j in range(i,n):
                cur = 0
                log = {}
                log[0] = 1
                for k in range(m):
                    cur+=matrix[k][j] - (matrix[k][i-1] if i>0 else 0)
                    if cur - target in log:
                        res+=log[cur-target]
                    if cur in log:
                        log[cur] += 1
                    else:
                        log[cur] = 1
        return res