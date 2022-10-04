class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s)<=1:
            return 0
        st = list()
        st.append(-1)
        ans = 0
        for idx, c in enumerate(s):
            if c == '(':
                st.append(idx)
            else:
                st.pop()
                if len(st)==0:
                    st.append(idx)
                length = idx-st[-1]
                if length > ans:
                    ans = length
        return ans