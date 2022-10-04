class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = {}
        for i, key in enumerate(s):
            if key in cnt:
                cnt[key] = 10**9
            else:
                cnt[key] = i
        ans = min(cnt.values())
        return -1 if ans == 10**9 else ans