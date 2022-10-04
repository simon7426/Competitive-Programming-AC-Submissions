class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        
        def check(mid):
            st= [(0,0)]
            vis = {(0,0)}
            
            while st:
                (x,y) = st.pop()
                if x==m-1 and y==n-1:
                    return True
                for a,b in [(1,0),(-1,0),(0,1),(0,-1)]:
                    p,q = x+a,y+b
                    if 0<=p <m and 0<=q<n:
                        if (p,q) not in vis:
                            cost = abs(heights[p][q]-heights[x][y])
                            if cost <= mid:
                                vis.add((p,q))
                                st.append((p,q))
            return False
        
        m = len(heights)
        n = len(heights[0])
        
        lo = -1
        hi = max(max(r) for r in heights)
        
        while(hi-lo>1):
            mid = (lo+hi)//2
            if check(mid):
                hi = mid
            else:
                lo = mid
        return hi