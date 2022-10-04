class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        r1 = ord(s[1]) - ord('0')
        r2 = ord(s[4]) - ord('0')
        c1 = ord(s[0]) - ord('A')
        c2 = ord(s[3]) - ord('A')
        ans = []
        for i in range(c1,c2+1):
            for j in range(r1,r2+1):
                ans.append(f"{chr(ord('A')+i)}{j}")
        return ans