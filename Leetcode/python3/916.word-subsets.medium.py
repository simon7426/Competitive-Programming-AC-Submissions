class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        result = defaultdict(int)
        for word in words2:
            for c,v in Counter(word).items():
                result[c] = max(result[c],v)
        ans = []
        for word in words1:
            ct = Counter(word)
            for c,v in result.items():
                if c not in ct or v> ct[c]:
                    break
            else:
                ans.append(word)
        return ans