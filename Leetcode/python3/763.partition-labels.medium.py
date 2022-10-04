class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        cnt = {}
        n = len(s)
        for i in range(n):
            if s[n-1-i] in cnt:
                continue
            cnt[s[n-1-i]] = n-1-i
        ans = []
        end = cnt[s[0]]
        ln = -1
        for i,val in enumerate(s):
            # print(end)
            if i == end:
                ans.append(i-ln)
                ln = i
                if i+1 != n:
                    end = cnt[s[i+1]]
            if cnt[val] > end:
                end = cnt[val]
        return ans