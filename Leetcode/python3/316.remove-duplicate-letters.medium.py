class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        seen = set()
        st = []
        last = {k : i for i,k in enumerate(s)}
        for i,val in enumerate(s):
            if val not in seen:
                while st and val<st[-1] and i<last[st[-1]]:
                    seen.remove(st.pop())
                seen.add(val)
                st.append(val)
        return ''.join(st)