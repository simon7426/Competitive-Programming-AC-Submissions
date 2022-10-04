class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        st = []
        lst = -(int(1e9+10))
        for val in nums[::-1]:
            if val < lst:
                return True
            while st and st[-1] < val:
                lst = st.pop()
            st.append(val)
        return False
                
        