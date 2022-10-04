class Solution:
    def reverse(self, x: int) -> int:
        is_neg=False
        if x<0:
            is_neg=True
            x*=-1
        y = str(x)[::-1]
        z = int(y)
        if is_neg:
            z*=-1
        if z>2**31 - 1 or z<-2**31:
            return 0
        return z