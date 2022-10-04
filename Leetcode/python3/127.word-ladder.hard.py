class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)
        queue = collections.deque()
        queue.append((beginWord,1))
        wrd_len = len(beginWord)
        while(queue):
            word, ans = queue.popleft()
            if word == endWord:
                return ans
            for i in range(wrd_len):
                for j in range(26):
                    newWord = word[:i]+chr(ord('a')+j)+word[i+1:]
                    if newWord in wordList:
                        wordList.remove(newWord)
                        queue.append((newWord,ans+1))
        return 0
