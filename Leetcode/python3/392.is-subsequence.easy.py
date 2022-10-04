class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ans = 0
        s_len = len(s)
        if s_len == 0:
            return True
        for ch in t:
            if ans<s_len and ch==s[ans]:
                ans+=1
        return ans==s_len