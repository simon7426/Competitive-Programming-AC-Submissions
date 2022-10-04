class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ""
        for i in range(n):
            left = n-1-i
            if k-left>26:
                ans+='z'
                k-=26
            else:
                # print(k,left)
                # print(chr(ord('a')+k-left))
                ans+=chr(ord('a')+k-left-1)
                k=left
        return ans[::-1]