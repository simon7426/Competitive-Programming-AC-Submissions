class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        cnt = Counter(changed)
        ans = []
        for k in cnt:
            if k == 0:
                if cnt[k] & 1:
                    return []
                ans += [0] * (cnt[k]>>1)
            else:
                x = k
                while(not(x&1) and x>>1 in cnt):
                    x = x >> 1
                while x in cnt:
                    if cnt[x] > 0:
                        ans += [x] * cnt[x]
                        if cnt[x+x] < cnt[x]:
                            return []
                        cnt[x+x] -= cnt[x]
                        cnt[x] = 0
                    x += x
        return ans
          
        