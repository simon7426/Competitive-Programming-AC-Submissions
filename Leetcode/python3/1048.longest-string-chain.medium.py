class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda word: len(word))
        dic = {}
        ans = 0
        for word in words:
            cur = 1
            for i in range(len(word)):
                tmp = word[:i] + word[i+1:]
                if tmp in dic:
                    cur = max(cur, dic[tmp]+1)
            dic[word] = cur
            ans = max(ans, dic[word])
        return ans