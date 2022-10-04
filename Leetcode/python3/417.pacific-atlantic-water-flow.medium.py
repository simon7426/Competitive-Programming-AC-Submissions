class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])
        visPacific = [[0 for _ in range(m)] for _ in range(n)]
        visAtlantic = [[0 for _ in range(m)] for _ in range(n)]
        def dfs(x, y, vis):
            vis[x][y] = 1
            dx = [1,-1,0,0]
            dy = [0, 0,1,-1]
            for i in range(4):
                nx = x+dx[i]
                ny = y+dy[i]
                if nx>=0 and nx<n and ny>=0 and ny<m and heights[nx][ny]>=heights[x][y] and not vis[nx][ny]:
                    dfs(nx,ny,vis)
        for i in range(m):
            if not visPacific[0][i]:
                dfs(0,i,visPacific)
            if not visAtlantic[n-1][i]:
                dfs(n-1,i, visAtlantic)
        for i in range(n):
            if not visPacific[i][0]:
                dfs(i,0,visPacific)
            if not visAtlantic[i][m-1]:
                dfs(i,m-1,visAtlantic)
        ans = []
        for i in range(n):
            for j in range(m):
                if visPacific[i][j]==1 and visAtlantic[i][j]==1:
                    ans.append([i,j])
        return ans