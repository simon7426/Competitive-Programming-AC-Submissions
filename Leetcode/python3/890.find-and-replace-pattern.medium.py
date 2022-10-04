class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        output = []
        for word in words:
            dict1 = {item: i for (i,item) in enumerate(word)}
            dict2 = {item: i for (i,item) in enumerate(pattern)}
            if list(dict1.values()) == list(dict2.values()):
                output.append(word)
        return output