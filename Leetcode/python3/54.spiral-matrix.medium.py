class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        dir_x = [0,1,0,-1]
        dir_y = [1,0,-1,0]
        travel_dir = 0
        m = len(matrix)
        n = len(matrix[0])
        cnt = m * n
        x = 0
        y = 0
        ans = []
        for lo in range(m*n):
            ans.append(matrix[x][y])
            matrix[x][y] = -101
            nxt_x = x+dir_x[travel_dir]
            nxt_y = y+dir_y[travel_dir]
            if (nxt_x>=0 and nxt_x<m and nxt_y>=0 and nxt_y <n and matrix[nxt_x][nxt_y]!=-101 ):
                x=nxt_x
                y=nxt_y
            else:
                travel_dir = (travel_dir + 1)%4
                x=x+dir_x[travel_dir]
                y=y+dir_y[travel_dir]
        return ans