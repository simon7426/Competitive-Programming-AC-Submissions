class Solution:
    def validPalindrome(self, s: str) -> bool:
        def checkPalindrome(st, sz):
            for i in range(sz//2):
                if st[i] != st[sz-1-i]:
                    return False
            return True
        n = len(s)
        if checkPalindrome(s, n):
            return True
        for i in range(n//2):
            if s[i]!=s[n-1-i]:
                key1 = i
                key2 = n-1-i
                break
        s1 = s[:key1]+s[key1+1:]
        if checkPalindrome(s1, n-1):
            return True
        s2 = s[:key2]+s[key2+1:]
        if checkPalindrome(s2, n-1):
            return True
        return False