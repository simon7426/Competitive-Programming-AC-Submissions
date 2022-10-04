class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        n = len(s)
        next_occurence = [[n+1]*26 for _ in range(n+1)]
        for i in range(n-1,-1,-1):
            for j in range(26):
                next_occurence[i][j] = next_occurence[i+1][j]
            next_occurence[i][ord(s[i])-ord('a')] = i
        ans = 0
        for word in words:
            ind = 0
            point = next_occurence[0][ord(word[ind])-ord('a')]
            while (ind<len(word) and point!=n+1 and next_occurence[point][ord(word[ind])-ord('a')]!=n+1):
                point = next_occurence[point][ord(word[ind])-ord('a')]+1
                ind+=1
            if ind == len(word):
                ans+=1
        return ans