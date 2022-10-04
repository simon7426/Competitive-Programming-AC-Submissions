class WordDictionary:

    def __init__(self):
        self.dic = defaultdict(list)

    def addWord(self, word: str) -> None:
        self.dic[len(word)].append(word)

    def search(self, word: str) -> bool:
        dot = 0
        for i in range(len(word)):
            if word[i] == '.':
                dot+=1
        if dot == 0:
            if word in self.dic[len(word)]: return True
        else:
            for bord in self.dic[len(word)]:
                matched = 0
                for i in range(len(word)):
                    if word[i] == '.':
                        continue
                    if word[i] == bord[i]:
                        matched += 1
                if matched == len(word) - dot:
                    return True
        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)