class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        for i in range(n//2):
            tmp = s[i]
            s[i] = s[n-i-1]
            s[n-i-1] = tmp
        return s