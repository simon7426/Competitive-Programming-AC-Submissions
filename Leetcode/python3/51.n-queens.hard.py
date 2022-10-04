class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def valid(i,j):

            for row in range(i):

                if board[row] == j or abs(row-i)==abs(board[row]-j):

                    return False

            return True

        

        def dfs(i,current_values):

            if i == n:

                res.append(current_values)

                return

            for j in range(n):

                if valid(i,j):

                    board[i] = j

                    dfs(i+1,current_values+[ "."*j+"Q"+"."*(n-j-1) ])

            

        board = [-1]*n

        res = []

        dfs(0,[])

        return res