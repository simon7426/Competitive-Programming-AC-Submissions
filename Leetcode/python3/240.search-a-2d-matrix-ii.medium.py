class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        
        i = 0
        j = m-1
        
        while(0<=i<n and 0<=j<m):
            cur = matrix[i][j]
            
            if cur < target:
                i += 1
            elif cur > target:
                j -= 1
            else:
                return True
        return False