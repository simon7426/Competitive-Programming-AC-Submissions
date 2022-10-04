class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maxx = 0
        for row in accounts:
            tmp = 0
            for val in row:
                tmp+=val
            if tmp > maxx:
                maxx = tmp
        return maxx