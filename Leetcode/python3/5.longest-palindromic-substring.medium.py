class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ''
        ma = 1
        ln = len(s)
        dp = [[False]*ln for _ in range(ln)]
        ans = s[0]
        for start in range(ln-1,-1,-1):
            dp[start][start] = True
            for end in range(start+1,ln):
                if s[start] == s[end]:
                    if end - start == 1 or dp[start+1][end-1]:
                        dp[start][end] = True
                        if ma < end - start + 1:
                            ma = end - start + 1
                            ans = s[start:end+1]
        return ans