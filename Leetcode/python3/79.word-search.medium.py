class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        cp = len(word)
        seen = []
        for i in range(m):
            tmp = [0 for j in range(n)]
            seen.append(tmp)
        def start(x,y,val):
            if val==cp:
                return True
            ret = False
            dir_x = [0,0,1,-1]
            dir_y = [1,-1,0,0]
            for i in range(4):
                nxt_x = x+dir_x[i]
                nxt_y = y+dir_y[i]
                if(nxt_x>=0 and nxt_x<m and nxt_y>=0 and nxt_y<n and board[nxt_x][nxt_y]==word[val] and not seen[nxt_x][nxt_y]):
                    seen[nxt_x][nxt_y] = 1
                    ret =ret or start(nxt_x,nxt_y,val+1)
                    seen[nxt_x][nxt_y] = 0
            return ret
        ans = False
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    seen[i][j] = 1
                    ans = start(i,j,1)
                    if ans == True:
                        return ans
                    seen[i][j] = 0
        return False