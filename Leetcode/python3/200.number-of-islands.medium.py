class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        vis = [[0 for i in range(n)] for j in range(m)]
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        def dfs(x,y):
            if vis[x][y] == 1:
                return
            vis[x][y] = 1
            for i in range(4):
                nx = x+dx[i]
                ny = y+dy[i]
                if nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny] == "1" and vis[nx][ny] == 0:
                    dfs(nx,ny)
        ans = 0
        for i in range(m):
            for j in range(n):
                if vis[i][j]==0 and grid[i][j] == "1":
                    ans+=1
                    dfs(i,j)
        return ans
            