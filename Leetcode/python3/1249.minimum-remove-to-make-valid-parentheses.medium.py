class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st = []
        mrk = set()
        for i,ch in enumerate(s):
            if ch == ")":
                if st:
                    st.pop()
                else:
                    mrk.add(i)
            elif ch == "(":
                st.append(i)
        for val in st:
            mrk.add(val)
        ans = ""
        for i,ch in enumerate(s):
            if i in mrk:
                continue
            ans+=ch
        return ans