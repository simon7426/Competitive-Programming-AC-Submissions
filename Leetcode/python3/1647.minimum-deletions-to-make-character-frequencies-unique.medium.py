class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = {}
        for ch in s:
            if ch in cnt:
                cnt[ch] += 1
            else:
                cnt[ch] = 1
        ans = []
        for k,v in cnt.items():
            ans.append(v)
        se = set()
        ret = 0
        for val in ans:
            while val and val in se:
                val-=1
                ret+=1
            if val > 0:
                se.add(val)
        return ret
        