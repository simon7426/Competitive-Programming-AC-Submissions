class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        columnTitle = columnTitle[::-1]
        ans = 0
        for i in range(len(columnTitle)):
            ans += (ord(columnTitle[i])-ord('A')+1) * (26**i)
        return ans