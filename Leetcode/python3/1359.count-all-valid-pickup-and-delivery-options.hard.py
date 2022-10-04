class Solution:
    def countOrders(self, n: int) -> int:
        ans = 1
        MOD = 10**9+7
        for i in range(2,n+1):
            ans = ((2*i*i-i)*ans)%MOD
        return ans