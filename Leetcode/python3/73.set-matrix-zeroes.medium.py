class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = set()
        col = set()
        m = len(matrix)
        if m:
            n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    if i not in row:
                        row.add(i)
                    if j not in col:
                        col.add(j)
        for val in row:
            for j in range(n):
                matrix[val][j] = 0
        for val in col:
            for i in range(m):
                matrix[i][val] = 0
                