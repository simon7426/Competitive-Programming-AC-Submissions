class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        st = []
        for val in s:
            if val == "(":
                st.append(val)
            else:
                last = st.pop()
                if last == '(':
                    st.append(1)
                else:
                    tmp = 0
                    while last != '(':
                        tmp+=last
                        last = st.pop()
                    st.append(tmp<<1)
        return sum(st)