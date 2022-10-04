class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ret = [[0] * n for _ in range(n)]
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]
        curx = cury = cd = 0
        for i in range(1, n*n +1):
            ret[curx][cury] = i
            newx = curx + dx[cd]
            newy = cury + dy[cd]
            if newx<0 or newx >= n or newy<0 or newy>=n or ret[newx][newy]:
                cd = (cd+1)%4
            curx += dx[cd]
            cury += dy[cd]
        return ret