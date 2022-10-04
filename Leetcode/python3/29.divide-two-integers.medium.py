class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        res, flag = 0,0
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0): 
            flag = -1
        dividend = abs(dividend)
        divisor = abs(divisor)
        while(dividend >= divisor ):
            n = 0
            while(dividend >= divisor<<n):
                n+=1
            res += 1 << (n-1)
            dividend -= (divisor << (n-1))
        res = -res if flag < 0 else res
        if res < -2147483648 or res>2147483647:
            return 2147483647
        return res