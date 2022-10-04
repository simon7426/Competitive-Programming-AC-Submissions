class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n==0:
            return False
        if matrix[0][0] > target or matrix[m-1][n-1] < target:
            return False
        tmp = []
        for i in range(m):
            tmp.append(matrix[i][0])
        index = bisect.bisect_left(tmp,target)
        if index == len(tmp):
            index -= 1
        if target<matrix[index][0]:
            index -= 1
        index2 = bisect.bisect_left(matrix[index], target)
        if index2 == n:
            return False
        return matrix[index][index2] == target