class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height)<= 2 :
            return 0
        n = len(height)
        ans = 0
        ll = height[0]
        rr = height[n-1]
        l = 1
        r = n-2
        while l<=r:
            if ll < rr:
                
                if height[l]>ll:
                    ll = height[l]
                else:
                    ans += ll - height[l]
                l+=1
            else:
                if height[r]>rr:
                    rr = height[r]
                else:
                    ans += rr - height[r]
                r -= 1
        return ans
                