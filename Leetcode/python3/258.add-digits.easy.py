class Solution:
    def addDigits(self, num: int) -> int:
        ans = num
        def add_digits(num: int) -> int:
            sm = 0
            while(num!=0):
                sm+=num%10
                num = num//10
            return sm
        while(ans//10):
            ans = add_digits(ans)
        return ans