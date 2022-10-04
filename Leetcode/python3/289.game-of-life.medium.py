class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        tmp = []
        for i in board:
            tm = []
            for j in i:
                tm.append(j)
            tmp.append(tm)
        m = len(board)
        n = len(board[0])
        dx = [0,0,1,-1,1,1,-1,-1]
        dy = [1,-1,0,0,1,-1,1,-1]
        for i in range(m):
            for j in range(n):
                cnt = 0
                for k in range(8):
                    ni = i + dx[k]
                    nj = j + dy[k]
                    if ni < 0 or ni >= m or nj <0 or nj >=n:
                        continue
                    cnt += tmp[ni][nj]
                if tmp[i][j] == 1:
                    if cnt <2:
                        board[i][j] = 0
                    elif cnt <= 3:
                        board[i][j] = 1
                    else:
                        board[i][j] = 0
                else:
                    if cnt == 3:
                        board[i][j] = 1

                    