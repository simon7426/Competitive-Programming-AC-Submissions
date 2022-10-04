class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        st = [-1]
        left_smaller = [-1] * n
        right_smaller = [n] * n
        for i in range(n):
            while st and st[-1]!=-1 and heights[st[-1]] > heights[i]:
                right_smaller[st[-1]] = i
                st.pop()
            if i>0 and heights[i-1] == heights[i]:
                left_smaller[i] = left_smaller[i-1]
            else:
                left_smaller[i] = st[-1]
            st.append(i)
        ans = 0
        for i in range(n):
            ans = max(ans, heights[i]*(right_smaller[i]-left_smaller[i]-1))
        
        return ans