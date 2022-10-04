class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def toInt(val):
            ret = 0
            for ch in val:
                ret = ret | (1<<(ord(ch)-97))
            return ret
        key = [toInt(val) for val in words]
        n = len(words)
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                if (key[i] & key[j] == 0):
                    ans = max(ans, len(words[i])*len(words[j]))
                    
        return ans