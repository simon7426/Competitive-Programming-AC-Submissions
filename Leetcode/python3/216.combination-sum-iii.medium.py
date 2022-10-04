class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        if sum(range(1,k+1))> n:
            return []
        if sum(range(1,k+1)) == n:
            return [[i for i in range(1,k+1)]]
        ans = []
        def dfs(i,k,n,L):
            if n==0 and k==0:
                ans.append(L)
                return
            for i in range(i,min(10,n+1)):
                dfs(i+1,k-1,n-i,L+[i])
        dfs(1,k,n,[])
        return ans