class Solution:
    def maxArea(self, height: List[int]) -> int:
        lo = 0
        hi = len(height) -1
        res = 0
        while lo < hi:
            res = max(res, (hi-lo)*min(height[lo],height[hi]))
            if height[lo]<height[hi]:
                lo+=1
            else:
                hi-=1
        return res