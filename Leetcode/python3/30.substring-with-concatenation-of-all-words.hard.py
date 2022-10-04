class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words or not words[0]:
            return []
        self.ans = []
        self.req = {}
        self.s = s
        self.n = len(s)
        self.k = len(words[0])
        self.t = len(words)* self.k
        for w in words:
            self.req[w] = self.req[w] +1 if w in self.req else 1
        for i in range(min(self.k,self.n-self.t+1)):
            self._findSub(i,i)
        return self.ans
    def _findSub(self,l,r):
        curr = {}
        while r+self.k<=self.n:
            w = self.s[r:r+self.k]
            r+=self.k
            if w not in self.req:
                l = r
                curr.clear()
            else:
                curr[w] = curr[w] + 1 if w in curr else 1
                while curr[w] > self.req[w]:
                    curr[self.s[l:l+self.k]] -= 1
                    l+=self.k
                if r-l == self.t:
                    self.ans.append(l)