class Solution:
    def knightProbability(self, N,K,r,c):
        dirx = [1,2,2,1,-1,-2,-2,-1]
        diry = [2,1,-1,-2,-2,-1,1,2]
        mp = {}
        def dfs(k, x, y, prob):
            p = 0
            if 0<=x<N and 0<=y<N:
                if k<K:
                    for i in range(8):
                        next_x = x+dirx[i]
                        next_y = y+diry[i]
                        if (next_x,next_y,k+1) not in mp:
                            mp[(next_x,next_y,k+1)] = dfs(k+1, next_x, next_y, prob/8)
                        p+=mp[(next_x, next_y, k+1)]
                else:
                    p=prob
            return p
        return dfs(0,r,c,1)