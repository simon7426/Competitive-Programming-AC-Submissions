class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        digits.reverse()
        c = 1
        for i in range(n):
            if c==0:
                break
            digits[i]+=1
            if digits[i] == 10:
                digits[i] = 0
                c = 1
            else:
                c = 0
        if c == 1:
            digits.append(1)
        digits.reverse()
        return digits
            