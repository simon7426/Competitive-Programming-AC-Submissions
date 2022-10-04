class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0],-x[1]))
        ans = prev = 0
        for _, v2 in intervals:
            if v2 > prev:
                ans+=1
                prev = v2
        return ans