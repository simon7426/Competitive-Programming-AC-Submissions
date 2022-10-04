class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n<0:
            x = 1/x
            n = -n
        if n % 2:
            return x * self.myPow(x,n-1)
        return self.myPow(x*x,n//2)