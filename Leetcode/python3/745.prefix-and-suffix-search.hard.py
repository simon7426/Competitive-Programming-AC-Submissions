class WordFilter:

    def __init__(self, words: List[str]):
        self._prefixes = prefixes = defaultdict(set)
        self._suffixes = suffixes = defaultdict(set)
        m = {word: weight for weight, word in enumerate(words)}
        for word, weight in m.items():
            for i in range(len(word)+1):
                prefixes[word[:i]].add(weight)
                suffixes[word[i:]].add(weight)


    def f(self, prefix: str, suffix: str) -> int:
        cands = self._prefixes[prefix] & self._suffixes[suffix]
        return max(cands) if cands else -1  
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)