class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        m -= 1
        n -= 1
        if m<n:
            m,n = n,m
        j = 1
        ans = 1
        for i in range(m+1,m+n+1):
            ans *= i
            ans /= j
            j+=1
        return int(ans)