class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        cnts = {}
        for let in s:
            if let in cnts:
                cnts[let]+=1
            else:
                cnts[let] = 1
        for let in t:
            if let in cnts:
                cnts[let]-=1
            else:
                return let
        for k,v in cnts.items():
            if v:
                return k