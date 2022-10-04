class Solution:
    def calPoints(self, ops: List[str]) -> int:
        ans = []
        for val in ops:
            if val == "+":
                ans.append(ans[-1]+ans[-2])
            elif val == "C":
                ans.pop()
            elif val == "D":
                ans.append(ans[-1]<<1)
            else:
                ans.append(int(val))
        return sum(ans)
                