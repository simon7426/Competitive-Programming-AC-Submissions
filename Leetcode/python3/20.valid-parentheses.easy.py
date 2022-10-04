class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c==')':
                if st and st[-1] == '(':
                    st.pop()
                else:
                    return False
            elif c=='}':
                if st and st[-1] == '{':
                    st.pop()
                else:
                    return False
            elif c== ']':
                if st and st[-1] == '[':
                    st.pop()
                else:
                    return False
            else:
                st.append(c)
        if st:
            return False
        return True