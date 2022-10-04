class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        path = path.split('/')
        for val in path:
            if val == "..":
                if st:
                    st.pop()
            elif val =="." or val=="":
                pass
            else:
                st.append(f'/{val}')
        if not st:
            return "/"
        return "".join(st)