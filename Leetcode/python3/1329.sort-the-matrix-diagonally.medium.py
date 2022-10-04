class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        dig = defaultdict(list)
        for i in range(n):
            for j in range(m):
                dig[i-j].append(mat[i][j])
        for k in dig:
            dig[k].sort(reverse=True)
        for i in range(n):
            for j in range(m):
                mat[i][j] = dig[i-j].pop()
        return mat