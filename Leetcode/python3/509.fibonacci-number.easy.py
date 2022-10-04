class Solution:
    def fib(self, n: int) -> int:
        if n<=1:
            return n
        f1 = 0
        f2 = 1
        for i in range(2,n+1):
            f1 += f2
            f1,f2 = f2,f1
        return f2