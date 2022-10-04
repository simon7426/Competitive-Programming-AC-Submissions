class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted([word[::-1] for word in set(words)])
        ans = 0
        last = ""
        for word in words + [""]:
            if not word.startswith(last):
                ans+=len(last)+1
            last = word
        return ans