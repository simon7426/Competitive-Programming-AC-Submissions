class Solution:
    def numsSameConsecDiff(self, n, k):
        res = []
        #
        number = lambda A: ''.join([str(x) for x in A])
        #
        def dfs(A):
            if len(A)==n:
                res.append(number(A))
                return
            z = A[-1]
            for x in {z-k,z+k}:
                if 0<=x<=9:
                    A.append(x)
                    dfs(A)
                    A.pop()
        #
        for i in range(1,10):
            dfs([i])
        #
        return res