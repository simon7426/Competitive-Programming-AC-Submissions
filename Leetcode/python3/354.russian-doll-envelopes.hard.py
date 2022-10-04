class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda key: (key[0], -key[1]))
        tails = []
        n = len(envelopes)
        for i in range(n):
            idx = bisect.bisect_right(tails,envelopes[i][1])
            if idx-1>=0 and tails[idx-1] == envelopes[i][1]:
                continue
            if idx==len(tails):
                tails.append(envelopes[i][1])
            else:
                tails[idx] = envelopes[i][1]
        return len(tails)