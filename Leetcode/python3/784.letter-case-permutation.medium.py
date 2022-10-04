class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        s = s.lower()
        fin = len(s)
        ans = []
        def explore(val,tmp):
            if val == fin:
                ans.append(tmp)
                return
            if s[val]>='a' and s[val]<='z':
                explore(val+1,tmp+s[val])
                explore(val+1,tmp+s[val].upper())
            else:
                explore(val+1,tmp+s[val])
        explore(0,"")
        return ans