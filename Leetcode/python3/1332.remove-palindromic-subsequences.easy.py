class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        for i in range(n//2):
            if s[i]!=s[-i-1]:
                return 2
        else:
            return 1